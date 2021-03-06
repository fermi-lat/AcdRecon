#ifndef ACDTKRPARAMS_H
#define ACDTKRPARAMS_H


#include "CLHEP/Geometry/Point3D.h"
#include "CLHEP/Geometry/Vector3D.h"
#include "CLHEP/Matrix/SymMatrix.h"

#include "Event/Recon/TkrRecon/TkrTrackParams.h"

/**
 *  @class AcdTkrParams
 *
 *  @brief Track parameters at a point
 *
 *  This includes the covarience matrix projected to that reference point.
 *  This class is here to pass around infomation needed for error projection.
 *
 *  @author Eric Charles
 *  
 */

class AcdTkrParams {
  
typedef HepGeom::Point3D<double> HepPoint3D;
typedef HepGeom::Vector3D<double> HepVector3D;
  
public:
  
  /**
   *  @brief Convert from TkrTrackParams to ACD specific rep
   *
   * @param params the track data in the Tkr representation
   * @param zRef z value of the conversion point
   * @param up track direction
   * @param refPoint reference point ( refPoint.z == zRef )
   * @param dir track direction at reference point
   * @param cov reduced covarience matrix at reference point
   * @return true from success, false otherwise
   */
  static bool convertToAcdRep(const Event::TkrTrackParams& params, const double& zRef, bool up,
			      HepPoint3D& refPoint, HepVector3D& dir, CLHEP::HepSymMatrix& cov);

public:

  /// Null C'tor
  AcdTkrParams();
  
  /// C'tor from point, vector and cov. matrix
  AcdTkrParams(const HepPoint3D& refPoint, const HepVector3D& dir, 
	       const CLHEP::HepSymMatrix& cov);

  /// C'tor from track parameters, Z reference value and direction
  AcdTkrParams(const Event::TkrTrackParams& params, const double& zRef, bool up);

  /// Fill from track parameters
  void set(const Event::TkrTrackParams& params, const double& zRef, bool up);

  /// Make it look like a vector (params), or like a matrix (covarience), index starts at 1, b/c CLHEP is antiquated
  double operator()(int i) const;
  const double& operator()(int i, int j) const;

  // access
  inline const HepPoint3D& refPoint() const { return m_refPoint; }
  inline const HepVector3D& dir() const { return m_dir; }
  inline const CLHEP::HepSymMatrix& cov() const { return m_cov; }
  
private:

  /// the reference point of the track
  HepPoint3D   m_refPoint;      
  /// the direction of the track
  HepVector3D  m_dir;             
  
  /// 3x3 symetric covarience matrix on the position defined @ the reference point
  CLHEP::HepSymMatrix m_cov;              
  
};

#endif
