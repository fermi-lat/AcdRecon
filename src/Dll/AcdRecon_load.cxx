/** 
* @file AcdRecon_load.cxx
* @brief This is needed for forcing the linker to load all components
* of the library.
*
*  $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/src/Dll/AcdRecon_load.cxx,v 1.2 2002/09/09 19:13:07 heather Exp $
*/

#include "GaudiKernel/DeclareFactoryEntries.h"
#include "../AcdReconAlg.h"
// #include "../AcdDisplay.h"   // need to separated out AcdDisplay.h 

DECLARE_ALGORITHM_FACTORY( AcdReconAlg );
// DECLARE_ALGORITHM_FACTORY( AcdDisplay );  // temp done in AcdDisplay.cxx

DECLARE_FACTORY_ENTRIES( AcdRecon ) {
    DECLARE_ALGORITHM( AcdReconAlg );
    DECLARE_ALGORITHM( AcdDisplay );
} 
