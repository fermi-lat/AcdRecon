#$Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/AcdReconLib.py,v 1.2 2009/12/21 20:09:43 jrb Exp $
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
