
#ifndef __AcdPha2MipTool_H
#define __AcdPha2MipTool_H 1

#include "AcdIPha2MipTool.h"
#include "GaudiKernel/ToolFactory.h"
#include "GaudiKernel/AlgTool.h"
#include "GaudiKernel/SmartDataPtr.h"
#include "GaudiKernel/ISvcLocator.h"

#include "AcdUtil/IAcdCalibSvc.h"

class MsgStream;
class HepMatrix;

/**   
* @class AcdPha2MipTool
*
* Class for extrapolating the Tracks to their intersections w/ the ACD
*
* $ $
*/


class AcdPha2MipTool : public AcdIPha2MipTool,  public AlgTool {
	
public:
  
  AcdPha2MipTool
  ( const std::string & type, 
    const std::string & name,
    const IInterface * parent ) ;
  virtual ~AcdPha2MipTool() ;
  
  /// @brief Intialization of the tool
  virtual StatusCode initialize();
  
  /// @brief Make collection of hits and fill the hit map
  virtual StatusCode makeAcdHits ( const Event::AcdDigiCol&,
				   Event::AcdHitCol&,
				   AcdRecon::AcdHitMap&);
  
  /// @brief Make a single hit
  virtual StatusCode makeAcdHit ( const Event::AcdDigi&,
				  Event::AcdHit*& );

protected:
  
  bool getCalibratedValues(const Event::AcdDigi& digi, float& mipsPmtA, float& mipsPmtB) const;

  bool getPeds(const idents::AcdId& id, float& valA, float& valB) const;
  bool getMips(const idents::AcdId& id, float& valA, float& valB) const;

private:

  Event::AcdHitCol* output;

  std::string  m_calibSvcName;

  AcdUtil::IAcdCalibSvc* m_calibSvc;
  

} ;

#endif
	
	
