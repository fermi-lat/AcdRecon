# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/SConscript,v 1.15 2010/04/28 18:54:42 lsrea Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdRecon-05-01-06-gr01
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('AcdReconLib', depsOnly = 1)
AcdRecon = libEnv.SharedLibrary('AcdRecon', listFiles(['src/*.cxx','src/Dll/*.cxx']))

progEnv.Tool('AcdReconLib')

if baseEnv['PLATFORM'] != 'win32':
	progEnv.AppendUnique(LINKFLAGS = '-u  GuiSvc_loadRef')

if baseEnv['PLATFORM'] == 'win32':
	progEnv.AppendUnique(LINKFLAGS = ' /include:_GuiSvc_loadRef')

test_AcdRecon = progEnv.GaudiProgram('test_AcdRecon',
                                     listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerTargets', package = 'AcdRecon',
             libraryCxts=[[AcdRecon, libEnv]],testAppCxts=[[test_AcdRecon,progEnv]],
             includes = listFiles(['AcdRecon/*.h']))




