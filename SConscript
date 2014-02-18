# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/SConscript,v 1.44 2014/02/17 22:07:21 echarles Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdRecon-05-08-01
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('addLinkDeps', package='AcdRecon', 
	    toBuild='component')
AcdRecon = libEnv.ComponentLibrary('AcdRecon', 
				   listFiles(['src/*.cxx']))

progEnv.Tool('AcdReconLib')

test_AcdRecon=progEnv.GaudiProgram('test_AcdRecon',
				   listFiles(['src/test/*.cxx']),
				   test = 1, package='AcdRecon')

progEnv.Tool('registerTargets', package = 'AcdRecon',
             libraryCxts=[[AcdRecon, libEnv]],
	     testAppCxts=[[test_AcdRecon,progEnv]],
             includes = listFiles(['AcdRecon/*.h']),
	     jo = ['src/test/jobOptions.txt'])




