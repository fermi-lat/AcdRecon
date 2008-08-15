# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdRecon/SConscript,v 1.2 2008/07/15 02:30:09 glastrm Exp $
# Authors: Heather Kelly <heather@slac.stanford.edu>, Eric Charles <echarles@slac.stanford.edu>
# Version: AcdRecon-04-03-02
import os
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('AcdReconLib', depsOnly = 1)
AcdRecon = libEnv.SharedLibrary('AcdRecon', listFiles(['src/*.cxx']) + listFiles(['src/Dll/*.cxx']))

progEnv.Tool('AcdReconLib')

if baseEnv['PLATFORM'] != 'win32':
	progEnv.AppendUnique(LINKFLAGS = '-u  GuiSvc_loadRef')

if baseEnv['PLATFORM'] == 'win32':
	progEnv.AppendUnique(LINKFLAGS = ' /include:_GuiSvc_loadRef')

test_AcdRecon = progEnv.GaudiProgram('test_AcdRecon', listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerObjects', package = 'facilities', libraries = [AcdRecon], testApps = [test_AcdRecon],includes = listFiles(['AcdRecon/*.h']))
