#include "AcdPha2MipTool.h"
#include "GaudiKernel/MsgStream.h"

#include "GaudiKernel/ToolFactory.h"
#include "GaudiKernel/DeclareFactoryEntries.h"

#include "Event/Recon/AcdRecon/AcdHit.h"
#include "Event/Digi/AcdDigi.h"

#include "idents/AcdId.h"

DECLARE_TOOL_FACTORY(AcdPha2MipTool)

AcdPha2MipTool::AcdPha2MipTool
 ( const std::string & type, 
   const std::string & name,
   const IInterface * parent )
 : AlgTool( type, name, parent )
 { declareInterface<AcdIPha2MipTool>(this) ; }

AcdPha2MipTool::~AcdPha2MipTool()
{} 

// This function extracts geometry constants from xml
// file using GlastDetSvc
StatusCode AcdPha2MipTool::initialize()
 {
  MsgStream log(msgSvc(), name());
  StatusCode sc = StatusCode::SUCCESS;
  log<<MSG::INFO<<"BEGIN initialize()"<<endreq ;
  
  return sc;
 }

StatusCode AcdPha2MipTool::makeAcdHits( const Event::AcdDigiCol& digis,
					Event::AcdHitCol& hits,
					AcdRecon::AcdHitMap& hitMap)
  //
  //
  // TDS input:
  // TDS output:
{
  MsgStream log(msgSvc(),name()) ;

  // loop on digis
  for ( Event::AcdDigiCol::const_iterator it = digis.begin();
	it != digis.end(); it++ ) {
    const Event::AcdDigi* aDigi = *it;
    // sanity check
    if ( aDigi == 0 ) return StatusCode::FAILURE ;
    
    // get the hit mask bits
    unsigned int hitMask = 0;
    hitMask |= aDigi->getAcceptMapBit(Event::AcdDigi::A) ? AcceptMapBit_AMask : 0;
    hitMask |= aDigi->getAcceptMapBit(Event::AcdDigi::B) ? AcceptMapBit_BMask : 0;
    hitMask |= aDigi->getVeto(Event::AcdDigi::A) ? VetoBit_AMask : 0;
    hitMask |= aDigi->getVeto(Event::AcdDigi::B) ? VetoBit_BMask : 0;
    hitMask |= aDigi->getCno(Event::AcdDigi::A) ? CNO_AMask : 0;
    hitMask |= aDigi->getCno(Event::AcdDigi::B) ? CNO_BMask : 0;	
    hitMap[aDigi->getId()] = hitMask;
    
    Event::AcdHit* newHit(0);
    StatusCode sc = makeAcdHit(*aDigi,newHit);

    if ( sc.isFailure() ) return sc;
    if ( newHit != 0 ) {
      hits.push_back(newHit);
    }
  } 
  return StatusCode::SUCCESS ;
}

StatusCode AcdPha2MipTool::makeAcdHit ( const Event::AcdDigi& digi,
					Event::AcdHit*& hit) {
  float mipsPmtA(0.);
  float mipsPmtB(0.);
  bool ok = getCalibratedValues(digi,mipsPmtA,mipsPmtB);
  if ( !ok ) return StatusCode::FAILURE;
  hit = new Event::AcdHit(digi,mipsPmtA,mipsPmtB);
  return StatusCode::SUCCESS;
}

bool AcdPha2MipTool::getCalibratedValues(const Event::AcdDigi& digi, float& mipsPmtA, float& mipsPmtB) const {

  static const unsigned short FullScale = 4095;
  mipsPmtA = 0.;
  mipsPmtB = 0.;

  // get calibration consts
  float pedValA(0.), pedValB(0.);
  float mipValA(0.), mipValB(0.);
				 
  if ( ! getPeds(digi.getId(),pedValA,pedValB) ) {
    MsgStream log(msgSvc(), name());
    log << MSG::ERROR << "Failed to get pedestals." << endreq;
    return false;
  }
  if ( ! getMips(digi.getId(),mipValA,mipValB) ) {
    MsgStream log(msgSvc(), name());
    log << MSG::ERROR << "Failed to get gains." << endreq;
    return false;
  }
     
  // do PMT A
  bool hasHitA = digi.getAcceptMapBit(Event::AcdDigi::A);
  Event::AcdDigi::Range rangeA = digi.getRange(Event::AcdDigi::A);  
  unsigned short phaA = hasHitA ? ( rangeA == Event::AcdDigi::LOW ? (unsigned short)digi.getPulseHeight(Event::AcdDigi::A) : FullScale ) : 0;
  if ( phaA != 0 && mipValA > 0. ) {
    float pedSubtracted_A = phaA - pedValA;
    mipsPmtA = pedSubtracted_A / mipValA;
  }
  // do PMT B
  bool hasHitB = digi.getAcceptMapBit(Event::AcdDigi::B);
  Event::AcdDigi::Range rangeB = digi.getRange(Event::AcdDigi::B);  
  unsigned short phaB = hasHitB ? ( rangeB == Event::AcdDigi::LOW ? (unsigned short)digi.getPulseHeight(Event::AcdDigi::B) : FullScale ) : 0;
  if ( phaB != 0  && mipValB > 0. ) {
    float pedSubtracted_B = phaB == 0 ? 0 : phaB - pedValB;
    mipsPmtB = pedSubtracted_B / mipValB;
  }
 
  return true;
}
