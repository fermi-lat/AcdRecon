# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/SConscript,v 1.43 2014/01/16 22:13:57 echarles Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdRecon-05-08-00
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




