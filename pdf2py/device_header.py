# Copyright 2008 Dan Collins
#

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

#try:from scipy.io.numpyio import *
#except ImportError: from extra.numpyio import *
from pdf2py import io_wrapper
fread = io_wrapper.fread
fwrite = io_wrapper.fwrite
from numpy import char, reshape
from pdf2py import align
import os, subprocess

class read:
    def __init__(self, fid):
        align.check(fid);
        self.size = fread(fid, 1, 'I', 'I', 1);
        self.checksum = fread(fid, 1, 'i', 'i', 1);
        self.reserved = ''.join(list(fread(fid, 32, 'c', 'c', 1)));

class write:
    def __init__(self, fid, device_hdr):
        align.check(fid);
        fwrite(fid, 1, device_hdr.size, 'I', 1);
        fwrite(fid, 1, device_hdr.checksum, 'i', 1);
        #self.reserved = ''.join(list(fread(fid, 32, self.reserved, 'c', 1)));
        fid.seek(32, os.SEEK_CUR);
