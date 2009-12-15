/** 
* @file AcdRecon_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/src/Dll/AcdRecon_load.cxx,v 1.5.588.1 2009/06/08 17:41:34 echarles Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"

DECLARE_FACTORY_ENTRIES( AcdRecon ) {
    DECLARE_ALGORITHM( AcdReconAlgV2 );
    DECLARE_ALGORITHM( AcdReconAlg );
    DECLARE_ALGORITHM( AcdDisplay );
    DECLARE_TOOL ( AcdPha2MipTool );
    DECLARE_TOOL ( AcdTkrIntersectTool );
    DECLARE_TOOL ( AcdTkrIntersectToolV2 );
    DECLARE_TOOL ( AcdPocaTool );
    DECLARE_TOOL ( AcdPocaToolV2 );
} 
