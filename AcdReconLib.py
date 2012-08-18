#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdRecon/AcdReconLib.py,v 1.2 2009/12/21 20:09:43 jrb Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['AcdRecon'])
        if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
	    env.Tool('findPkgPath', package = 'AcdRecon') 
    env.Tool('EventLib')
    env.Tool('guiLib')
    env.Tool('identsLib')
    env.Tool('AcdUtilLib')
    env.Tool('addLibrary', library = env['rootLibs'])
    if env['PLATFORM']=='win32' and env.get('CONTAINERNAME','')=='GlastRelease':
        env.Tool('findPkgPath', package='GuiSvc')
        env.Tool('findPkgPath', package='TkrUtil')
        env.Tool('findPkgPath', package='LdfEvent')

def exists(env):
    return 1;
