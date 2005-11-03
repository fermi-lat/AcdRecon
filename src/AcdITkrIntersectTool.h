
#ifndef __AcdITkrIntersectTool_H
#define __AcdITkrIntersectTool_H 1

#include "GaudiKernel/IAlgTool.h"
#include "Event/Recon/TkrRecon/TkrTrack.h"
#include "Event/Recon/AcdRecon/AcdTkrIntersection.h"

/**   
* @class AcdITkrIntersectTool
*
* Base class for clustering tools
*
* $Header: /nfs/slac/g/glast/ground/cvs/AcdRecon/src/Attic/AcdITkrIntersectTool.h,v 1.1.2.1 2005/11/02 23:39:34 echarles Exp $
*/

static const InterfaceID IID_AcdITkrIntersectTool("AcdITkrIntersectTool",1,0) ;

class AcdITkrIntersectTool : virtual public IAlgTool {

 public:
  
  // retrieve Gaudi interface ID
  static const InterfaceID& interfaceID()
    { return IID_AcdITkrIntersectTool; }
  
  AcdITkrIntersectTool() {}
  virtual ~AcdITkrIntersectTool() {}
  
  //! main method
  virtual StatusCode findIntersections ( const Event::TkrTrackCol *,
					 Event::AcdTkrIntersectionCol *,
					 std::map<idents::AcdId,unsigned char>& ) =0 ;
} ;

#endif



