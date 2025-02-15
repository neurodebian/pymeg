'''density calc returns the 1/euclid distance of the cartesian points supplied.
returns the distance square matrix of size numofpointsXnumofpoints.
ex.
c = array([[1, 1, 1],
           [2, 2, 2],
           [3, 3, 3],
           [2, 2, 2]])
           
d = density.calc(c)
           
d...
array([[ 0.        ,  0.57735027,  0.28867513,  0.57735027],
       [ 0.57735027,  0.        ,  0.57735027,  1.        ],
       [ 0.28867513,  0.57735027,  0.        ,  0.57735027],
       [ 0.57735027,  1.        ,  0.57735027,  0.        ]])

gof = array([.92,.85,.99,.95])
gofscale = .9
s = gof-gofscale
sf = (1/(1-gofscale))*s
ds = d*sf

ds...
array([[ 0.        , -0.28867513,  0.25980762,  0.28867513],
       [ 0.11547005, -0.        ,  0.51961524,  0.5       ],
       [ 0.05773503, -0.28867513,  0.        ,  0.28867513],
       [ 0.11547005, -0.5       ,  0.51961524,  0.        ]])

meanvalue = mean(ds, axis=0)
and meanvalue is the value written to the MRI.
mean(ds,axis=0)
Out[89]: array([ 0.07216878, -0.26933757,  0.32475953,  0.26933757])
'''

def handler(points,mr,gofscale,gof,sigma):
    from pdf2py import readwrite
    from meg import density
    from mri import transform
    from scipy import ndimage
    from nifti import NiftiImage
    from numpy import float32, int16, array


    report = {}
    fids = eval(mr.description)
    lpa = fids[0]
    rpa = fids[1]
    nas = fids[2]
    #self.points = array([[0,0,0],[10,0,0],[0,20,0]])#DEBUG-----------------
    xyz = transform.meg2mri(lpa,rpa,nas, dipole=points)
    #readwrite.writedata(xyz, os.path.dirname(mripath)+'/'+'xyz')
    print 'lpa, rpa, nas', lpa, rpa, nas
    print mr.pixdim


    #do some scaling of the dips using the GOF as a weight.
    VoxDim = mr.voxdim[::-1]
    xyzscaled = (xyz/VoxDim).T
    print xyzscaled
    d = density.calc(xyz)
    gofscale = float32(gofscale)
    print 'gofscale',gofscale
    s= gof-gofscale
    sf=(1/(1-gofscale))*s
    ds = d*sf


    #apply a 1D gaussian filter
    z = density.val2img(mr.data, ds, xyzscaled)
    #sigma = float32(self.sigmaval.GetValue())
    print 'sigma',sigma
    #sigma = 3
    print 'filtering 1st dimension'
    f = ndimage.gaussian_filter1d(z, sigma*1/VoxDim[0], axis=0)
    print 'filtering 2nd dimension'
    f = ndimage.gaussian_filter1d(f, sigma*1/VoxDim[1], axis=1)
    print 'filtering 3rd dimension'
    f = ndimage.gaussian_filter1d(f, sigma*1/VoxDim[2], axis=2)

    scaledf = int16((z.max()/f.max())*f*1000)
    print 'writing nifti output image'
    overlay = NiftiImage(int16(scaledf))

    overlay.setDescription(mr.description)
    overlay.setFilename(mr.filename+'dd')
    overlay.setQForm(mr.getQForm())

    return overlay

