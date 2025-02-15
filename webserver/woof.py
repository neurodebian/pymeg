#!/usr/bin/env python2
# -*- encoding: utf-8 -*-
#
#  woof -- an ad-hoc single file webserver
#  Copyright (C) 2004 Simon Budig  <simon@budig.de>
# 
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  A copy of the GNU General Public License is available at
#  http://www.fsf.org/licenses/gpl.txt, you can also write to the
#  Free Software  Foundation, Inc., 59 Temple Place - Suite 330,
#  Boston, MA 02111-1307, USA.

# Darwin support with the help from Mat Caughron, <mat@phpconsulting.com>
# Solaris support by Colin Marquardt, <colin.marquardt@zmd.de>
# FreeBSD support with the help from Andy Gimblett, <A.M.Gimblett@swansea.ac.uk>
# Cygwin support by Stefan ReichÃ¶r <stefan@xsteve.at>

import sys, os, popen2, signal, select, socket, getopt, commands
import urllib, BaseHTTPServer
import ConfigParser

maxdownloads = 1
cpid = -1
compressed = True


# Utility function to guess the IP (as a string) where the server can be
# reached from the outside. Quite nasty problem actually.

def find_ip ():
   if sys.platform == "cygwin":
      ipcfg = os.popen("ipconfig").readlines()
      for l in ipcfg:
         try:
            candidat = l.split(":")[1].strip()
            if candidat[0].isdigit():
               break
         except:
            pass
      return candidat

   os.environ["PATH"] = "/sbin:/usr/sbin:/usr/local/sbin:" + os.environ["PATH"]
   platform = os.uname()[0];

   if platform == "Linux":
      netstat = commands.getoutput ("LC_MESSAGES=C netstat -rn")
      defiface = [i.split ()[-1] for i in netstat.split ('\n')
                                    if i.split ()[0] == "0.0.0.0"]
   elif platform in ("Darwin", "FreeBSD"):
      netstat = commands.getoutput ("LC_MESSAGES=C netstat -rn")
      defiface = [i.split ()[-1] for i in netstat.split ('\n')
                                    if len(i) > 2 and i.split ()[0] == "default"]
   elif platform == "SunOS":
      netstat = commands.getoutput ("LC_MESSAGES=C netstat -arn")
      defiface = [i.split ()[-1] for i in netstat.split ('\n')
                                    if len(i) > 2 and i.split ()[0] == "0.0.0.0"]
   else:
      print >>sys.stderr, "Unsupported platform; please add support for your platform in find_ip().";
      return None

   if not defiface:
      return None

   if platform == "Linux":
      ifcfg = commands.getoutput ("LC_MESSAGES=C ifconfig "
                                  + defiface[0]).split ("inet addr:")
   elif platform in ("Darwin", "FreeBSD", "SunOS"):
      ifcfg = commands.getoutput ("LC_MESSAGES=C ifconfig "
                                  + defiface[0]).split ("inet ")

   if len (ifcfg) != 2:
      return None
   ip_addr = ifcfg[1].split ()[0]

   # sanity check
   try:
      ints = [ i for i in ip_addr.split (".") if 0 <= int(i) <= 255]
      if len (ints) != 4:
         return None
   except ValueError:
      return None

   return ip_addr

   
# Main class implementing an HTTP-Requesthandler, that serves just a single
# file and redirects all other requests to this file (this passes the actual
# filename to the client).
# Currently it is impossible to serve different files with different
# instances of this class.

class FileServHTTPRequestHandler (BaseHTTPServer.BaseHTTPRequestHandler):
   server_version = "Simons FileServer"
   protocol_version = "HTTP/1.0"

   filename = "."

   def log_request (self, code='-', size='-'):
      if code == 200:
         BaseHTTPServer.BaseHTTPRequestHandler.log_request (self, code, size)


   def do_GET (self):
      global maxdownloads, cpid, compressed

      # Redirect any request to the filename of the file to serve.
      # This hands over the filename to the client.

      self.path = urllib.quote (urllib.unquote (self.path))
      location = "/" + urllib.quote (os.path.basename (self.filename))
      if os.path.isdir (self.filename):
         if compressed:
            location += ".tar.gz"
         else:
            location += ".tar"

      if self.path != location:
         txt = """\
                <html>
                   <head><title>302 Found</title></head>
                   <body>302 Found <a href="%s">here</a>.</body>
                </html>\n""" % location
         self.send_response (302)
         self.send_header ("Location", location)
         self.send_header ("Content-type", "text/html")
         self.send_header ("Content-Length", str (len (txt)))
         self.end_headers ()
         self.wfile.write (txt)
         return

      maxdownloads -= 1

      # let a separate process handle the actual download, so that
      # multiple downloads can happen simultaneously.

      cpid = os.fork ()
      os.setpgrp ()

      if cpid == 0:
         # Child process
         size = -1
         datafile = None
         child = None
         
         if os.path.isfile (self.filename):
            size = os.path.getsize (self.filename)
            datafile = open (self.filename)
         elif os.path.isdir (self.filename):
            os.environ['woof_dir'], os.environ['woof_file'] = os.path.split (self.filename)
            if compressed:
               arg = 'z'
            else:
               arg = ''
            child = popen2.Popen3 ('cd "$woof_dir";tar c%sf - "$woof_file"' % arg)
            datafile = child.fromchild

         self.send_response (200)
         self.send_header ("Content-type", "application/octet-stream")
         if size >= 0:
            self.send_header ("Content-Length", size)
         self.end_headers ()

         try:
            try:
               while 1:
                  if select.select ([datafile], [], [], 2)[0]:
                     c = datafile.read (1024)
                     if c:
                        self.wfile.write (c)
                     else:
                        datafile.close ()
                        break
            except:
               print >>sys.stderr, "Connection broke. Aborting"

         finally:
            # for some reason tar doesnt stop working when the pipe breaks
            if child:
               if child.poll ():
                  os.killpg (os.getpgid (child.pid), signal.SIGTERM)
               

def serve_files (filename, maxdown = 1, ip_addr = '', port = 8080):
   global maxdownloads

   maxdownloads = maxdown

   # We have to somehow push the filename of the file to serve to the
   # class handling the requests. This is an evil way to do this...

   FileServHTTPRequestHandler.filename = filename

   try:
      httpd = BaseHTTPServer.HTTPServer ((ip_addr, port),
                                         FileServHTTPRequestHandler)
   except socket.error:
      print >>sys.stderr, "cannot bind to IP address '%s' port %d" % (ip_addr, port)
      sys.exit (1)

   if not ip_addr:
      ip_addr = find_ip ()
   if ip_addr:
      print "Now serving on http://%s:%s/" % (ip_addr, httpd.server_port)

   while cpid != 0 and maxdownloads > 0:
      httpd.handle_request ()



def usage (defport, defmaxdown, errmsg = None):
   name = os.path.basename (sys.argv[0])
   print >>sys.stderr, """
    Usage: %s [-i <ip_addr>] [-p <port>] [-c <count>] [-u] <file/dir>
           %s [-i <ip_addr>] [-p <port>] [-c <count>] [-u] -s
   
    Serves a single file <count> times via http on port <port> on IP
    address <ip_addr>.
    When a directory is specified, a .tar.gz archive gets served (or an
    uncompressed tar archive when -u is specified), when -s is specified
    instead of a filename, %s distributes itself.
   
    defaults: count = %d, port = %d

    You can specify different defaults in two locations: /etc/woofrc
    and ~/.woofrc can be INI-style config files containing the default
    port and the default count. The file in the home directory takes
    precedence.

    Sample file:

        [main]
        port = 8008
        count = 2
        ip = 127.0.0.1
        compressed = true
   """ % (name, name, name, defmaxdown, defport)
   if errmsg:
      print >>sys.stderr, errmsg
      print >>sys.stderr
   sys.exit (1)



def main ():
   global cpid, compressed

   maxdown = 1
   port = 8080
   ip_addr = ''

   config = ConfigParser.ConfigParser()
   config.read (['/etc/woofrc', os.path.expanduser('~/.woofrc')])

   if config.has_option ('main', 'port'):
      port = config.getint ('main', 'port')

   if config.has_option ('main', 'count'):
      maxdown = config.getint ('main', 'count')

   if config.has_option ('main', 'ip'):
      ip_addr = config.get ('main', 'ip')

   if config.has_option ('main', 'compressed'):
      compressed = config.getboolean ('main', 'compressed')

   defaultport = port
   defaultmaxdown = maxdown

   try:
      options, filenames = getopt.getopt (sys.argv[1:], "hsui:c:p:")
   except getopt.GetoptError, desc:
      usage (defaultport, defaultmaxdown, desc)

   for option, val in options:
      if option == '-c':
         try:
            maxdown = int (val)
            if maxdown <= 0:
               raise ValueError
         except ValueError:
            usage (defaultport, defaultmaxdown, 
                   "invalid download count: %r. "
                   "Please specify an integer >= 0." % val)

      elif option == '-i':
         ip_addr = val

      elif option == '-p':
         try:
            port = int (val)
         except ValueError:
            usage (defaultport, defaultmaxdown,
                   "invalid port number: %r. Please specify an integer" % val)

      elif option == '-s':
         filenames.append (__file__)

      elif option == '-h':
         usage (defaultport, defaultmaxdown)

      elif option == '-u':
         compressed = False

      else:
         usage (defaultport, defaultmaxdown, "Unknown option: %r" % option)

   if len (filenames) == 1:
      filename = os.path.abspath (filenames[0])
   else:
      usage (defaultport, defaultmaxdown,
             "Can only serve single files/directories.")

   if not os.path.exists (filename):
      usage (defaultport, defaultmaxdown,
             "%s: No such file or directory" % filenames[0])

   if not (os.path.isfile (filename) or os.path.isdir (filename)):
      usage (defaultport, defaultmaxdown,
             "%s: Neither file nor directory" % filenames[0])

   serve_files (filename, maxdown, ip_addr, port)

   # wait for child processes to terminate
   if cpid != 0:
      try:
         while 1:
            os.wait ()
      except OSError:
         pass



if __name__=='__main__':
   try:
      main ()
   except KeyboardInterrupt:
      pass


