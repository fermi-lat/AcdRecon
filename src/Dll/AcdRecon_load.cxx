/** 
* @file AcdRecon_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/src/Dll/AcdRecon_load.cxx,v 1.3 2004/08/24 21:10:48 hansl Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES( AcdRecon ) {
    DECLARE_ALGORITHM( AcdReconAlg );
    DECLARE_ALGORITHM( AcdDisplay );
    DECLARE_TOOL ( AcdTkrIntersectTool );
} 
