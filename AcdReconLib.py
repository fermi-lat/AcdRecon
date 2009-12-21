#$Header: /nfs/slac/g/glast/ground/cvs/GlastRelease-scons/AcdRecon/AcdReconLib.py,v 1.1 2008/07/09 21:13:39 glastrm Exp $
def generate(env, **kw):
    if not kw.get('depsOnly', 0):
        env.Tool('addLibrary', library = ['AcdRecon'])
    env.Tool('EventLib')
    env.Tool('guiLib')
    env.Tool('identsLib')
    env.Tool('AcdUtilLib')
    env.Tool('addLibrary', library = env['rootLibs'])

def exists(env):
    return 1;
