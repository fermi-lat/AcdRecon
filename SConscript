# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/SConscript,v 1.12 2009/12/21 20:11:55 jrb Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdRecon-05-01-04
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




