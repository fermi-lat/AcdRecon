#ifndef ACDRECONSTRUCT_H
#define ACDRECONSTRUCT_H

#include "CLHEP/Geometry/Point3D.h"
#include "CLHEP/Geometry/Vector3D.h"
#include "idents/AcdId.h"
#include "idents/AcdGapId.h"
#include "idents/VolumeIdentifier.h"
#include "geometry/Point.h"
#include "geometry/Vector.h"
#include "../AcdRecon/AcdGap.h"

#include <map>
#include <list>

namespace AcdRecon {
  
  /// This struct stores the data about the point of closest approach to active elements that we pass around internally
  struct PocaData {
  public:
    PocaData(){reset(2000.);}      
    void reset(double maxDist) {
      m_id = idents::AcdId();
 
      m_arcLengthCenter = 0.;
      m_docaCenter = maxDist;
      m_pocaCenter = Point(); 

      m_arcLengthPlane = 0.;
      m_activeX = -maxDist;
      m_activeY = -maxDist;
      m_active2D = -maxDist;
      m_inPlane = Point();
      m_localCovXX = 0;
      m_localCovXY = 0;
      m_localCovYY = 0;
      m_cosTheta = 0.;
      m_path = 0;

      m_arcLength = 0.;
      m_active3D = -maxDist;
      m_active3DErr = 0;
      m_poca = Point(); 
      m_pocaVector = Vector();

      m_region = -1;
    }
    idents::AcdId m_id;       // The AcdId of the hit element

    double m_arcLengthCenter; // Length along the track to the POCA to the center of the tile
    double m_docaCenter;      // The distance of closest aproach to the center of the tile
    Point m_pocaCenter; 

    double m_arcLengthPlane;  // Length along the track to the plane of the detector
    double m_activeX;         // 2D active distance local X
    double m_activeY;         // 2D active distance local y
    double m_active2D;        // The distance of closest aproach to the relevent edge in 2D
    Point m_inPlane;          // 3D point that track crosses detector plane
    double m_localX;          // The local coordinates
    double m_localY; 
    double m_localCovXX;      // The local covarience terms
    double m_localCovXY;
    double m_localCovYY;
    double m_cosTheta;        // angle between track and plane normal
    double m_path;            // pathlength of track in plane

    double m_arcLength;       // Length along the track to the poca
    double m_active3D;        // The distance of closest aproach to the relevent edge in 3D
    double m_active3DErr;     // The error on distance of closest aproach to the relevent edge in 3D
    Point m_poca;             // Point of closest approach
    Vector m_pocaVector;      // Vector from Track to POCA

    int m_region;             // One of the enums defined in Event/Recon/AcdRecon/AcdTkrPoca.h 
  };  
  typedef std::map<idents::AcdId,PocaData>         PocaDataMap;
  typedef std::map<idents::AcdId,PocaData*>        PocaDataPtrMap;
 
  /// This struct stores the data about the intersection with the nominal ACD
  struct ExitData {
  public:
    ExitData ()
      :m_face(-1),m_arcLength(-1.){;}
    void reset() {
      m_arcLength = -1.;
      m_face = -1;
    }
    int    m_face;        // 0:top 1:-X 2:-Y 3:+X 4:+Y 5:bottom
    double m_arcLength;   // Length along the track to the m_x
    Point  m_x;           // Intersection Point
  };

  /// this struct stores the track pointing data that we pass around
  struct TrackData {
  public:
    TrackData():m_point(),m_dir(),m_energy(0.),m_index(-1),m_upward(true){;}
    TrackData(const HepPoint3D& point, const HepVector3D& dir, double energy, int index, bool up)
      :m_point(point),m_dir(dir),m_energy(energy),m_index(index),m_upward(up){;}
    HepPoint3D  m_point;       // the start (or end) point of the track
    HepVector3D m_dir;         // the direction of the track
    double      m_energy;      // the energy of the track at the start point
    int         m_index;       // the index number of this track
    bool        m_upward;      // which side of track
  };

  // this is to define if a channel has a hit or not
  typedef std::map<idents::AcdId,unsigned int> AcdHitMap;

}

#endif