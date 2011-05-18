# Copyright 2008 Dan Collins

# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

# And is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with Build; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# A portion of this code was used and adapted from meg_leadfield1.m function distributed with
# the matlab fieldtrip package at fcdonders, which was adapted from Luetkenhoener, Habilschrift '92.


"""Compute leadfields
pos=R point
pos= channel location vector
ori=signal channel orientation

ex. x=leadfield.calclf(channelinstance, grid) ....
    will return the leadfield sum from both upper and lower coils

    grid is N X 3 array. Make sure to reshape it if Ndim=1 to by 1X3
    ex. IF....shape(grid) RETURNS (3,) THEN grid=grid.reshape(1,3)
    or just make grid like... grid=array([[0, 6, 3]])"""


from numpy import zeros, array, dot, cross, shape, append, reshape, size
from numpy.linalg import norm
from pdf2py import pdf
from time import time,sleep
import sys
from misc import progressbar
from multiprocessing import Pool,Process

class shared_data:
    def __init__(self,grid=None):
        self.grid = grid

class calc:
    #def __init__(self,datapdf,channelinstance,grid, centerofsphere=None):
    def __init__(self,channelinstance=None,grid=None,centerofsphere=None,chlpos=None,chupos=None,chldir=None,chudir=None):
        #'''calc leadfield script to use pos.py and getlf class to get the sum of upper and lower coils
        #returns leadfield
        #grid=voxel location. dimensions: N X 3'''
        #self.ext = 'pymlf'

        #if channelinstance == None:
            #if chlpos == None or chupos == None or chldir == None or chudir == None:
                #print('if channelobject not supplied, you need to supply ch position and direction for upper and lower coil')
                #raise Exception('InputError')
        #else:
            #chlpos=channelinstance.chlpos;
            #chldir=channelinstance.chldir;
            #chupos=channelinstance.chupos;
            #chudir=channelinstance.chudir;


        ##check grid and guess if units are correct
        #if grid.max() < 15 and grid.min() > -15:
            #print ''
            #print 'Warning...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'
            #print 'Warning...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'
            #print 'Warning...!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n'
            #print 'Your grid point values are small. Max ==', grid.max(), 'Are you sure they are in mm\n'

        #ts = time()
        #coilsperch=2; #gradiometer config
        #channelinstance.getposition()

        #if centerofsphere == None:
            #self.spherecenter = array([0,0,40])#c=cos.center()
            ##self.spherecenter = c.spherecenter
        #else:
            #self.spherecenter = centerofsphere

        #if array(self.spherecenter).max() < 10:
            #print 'COS Warning!!! Your center of sphere is quite close to 0,0,0. Make sure your units are in mm'



        #gridshape=shape(grid)
        #if len(shape(grid)) == 1:
            #grid = grid.reshape([1,3])

        #print 'make sure your grid units are in mm'
        #if size(grid,1) != 3: #check grid dimensions
            #if size(grid,0) != 3:
                #print 'grid dimensions wrong'
                #return
            #grid = grid.transpose()
            #print 'reshaping grid'

        ##--------------------------------
        import logging,multiprocessing

        logging.basicConfig(level=logging.DEBUG,format='(%(threadName)-10s) %(message)s',)
        mgr = multiprocessing.Manager()
        namespace = mgr.Namespace()
        from Queue import Queue
        x = 1
        global x
        pool = Pool(processes=2)#,initializer=code)              # start 4 worker processes
        q = Queue()
        a = 1;b = 2

        #result = pool.apply_async(code, args=(q,))#, args=([grid,chlpos,chldir,cos],[grid,chupos,chudir,cos]))#, args=(grid,chlpos,chupos,cos))     # evaluate "f(10)" asynchronously
        #result = Process(target=code)
        #print result.get(timeout=1)           # prints "100" unless your computer is *very* slow
        pool.map(code, ['a','b'])#(grid,chlpos,chupos,cos), [2])          # prints "[0, 1, 4,..., 81]"
        print 'done'
        return
        #print 'Calculating Lower Coil LeadFields for', size(grid,0), 'grid points\n'
        #lowerlf = code(grid, chlpos ,chldir, cent = self.spherecenter)

        #te = time()
        #print 'elapsed time', te-ts, 'seconds'
        #return

        #print 'Calculating Upper Coil LeadFields for', size(grid,0), 'grid points\n'
        #upperlf = code(grid, chupos ,chudir, cent = self.spherecenter)


        #sizegrid=len(grid)
        #leadfieldfinal=(lowerlf.lf+upperlf.lf)
        #print shape(leadfieldfinal),sizegrid,len(leadfieldfinal)

        #leadfieldfinal=leadfieldfinal.reshape([sizegrid, len(leadfieldfinal)/3/sizegrid,3])#,sizegrid], order='FORTRAN') #need to double check result to make sure rows and columns are right
        #te = time()
        ##print ' ' #sys.stdout.flush()
        #print 'elapsed time', te-ts, 'seconds'

        #self.leadfield = leadfieldfinal
        #self.grid = grid

import threading
import os
def code(grid=None, pos=None, ori=None, cent=None):
    #t = shared_data()
    #print 'shared', t.grid
    print("Task(%s) processid = %s" % ('layer', os.getpid()))
    """grid=voxel location. dimensions: N X 3
    pos=position of channels. returned by pos.py
    ori=orientation of channels. returned by pos.py"""

    print grid, 'grid',pos

    print 'x', x

    #fn = '/home/danc/python/data/0611/0611SEF/e,rfhp1.0Hz,n,x,baha001-1SEF,f50lp'
    #from pdf2py import pdf
    #p = pdf.read(fn)
    return

    #def cut
        ##danc changed hdr read to convert to mm upfront.
        ##pos=pos*1000 #convert channel pos from meters to mm
        ##self.grid=grid;self.pos=pos;self.ori=ori
        #print type(grid),type(pos),type(ori),type(cent)
        #chp = pos - cent
        #loc = grid - cent
        #print 'center of sphere', cent

        #gridshape=shape(self.loc)
        #if len(gridshape) == 1:
            #self.loc.shape=self.loc[1,3]

        #self.lf=array([])
        #pbar = progressbar.ProgressBar().start()
        #for j in range(0,len(self.loc)): #for each grid point
            #"for each R point (chp) calculate the leadfield"
            #sys.stdout.flush()
            #pbar.update((float(j)/float(len(self.loc)))*100)
            #self.nchans = len(chp)
            #R=self.loc[j,:]
            #self.position=chp;position=chp
            #self.orientation=ori;orientation=ori
            #lftmp = zeros((self.nchans,3),float);
            #tmp2 = norm(R);

            #for i in range(0,self.nchans):
                #t = position[i]
                #o = orientation[i]
                #tmp1 = norm(t);
                #tmp3 = norm(t-R);
                #tmp4 = dot(t,R);
                #tmp5 = dot(t,t-R);
                #tmp6 = dot(R,t-R);
                #tmp7 = (tmp1*tmp2)**2 - tmp4**2; #% cross(r,R)**2
                ##tmp7=tmp7
                #self.alpha = 1 / (-tmp3 * (tmp1*tmp3+tmp5));
                #A = 1/tmp3 - 2*self.alpha*tmp2**2 - 1/tmp1;
                #B = 2*self.alpha*tmp4;
                #C = -tmp6/(tmp3**3);
                #self.beta = dot(A*t + B*R + C*(t-R), o)/tmp7;
                #lftmp[i,:] = cross(self.alpha*o  + self.beta*t, R);

            #self.lf = append(self.lf, 1e-7*lftmp); #% multiply with u0/4pi
if __name__ == '__main__':
    from numpy import *
    fn = '/home/danc/python/data/0611/0611SEF/e,rfhp1.0Hz,n,x,baha001-1SEF,f50lp'
    from pdf2py import pdf
    p = pdf.read(fn)
    p.data.setchannels('meg')
    grid=random.randn(3,10)
    lft = calc(p.data.channels,grid)

