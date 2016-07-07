#pragma once
#include <math.h>
#include "swarm/particle.hh"

/// \authors {Charles Yaiche, Nicolas Chariglione}
/// \file video-manager.hh
/// \brief Countain opencv wrapper class
/// \version 0.1

/*! \namespace beetrail
 *  namespace getting all classes for the beetrail project
 */
namespace beetrail
{
  /*!
   * \class DistanceMiddle
   * \brief Dummy fitness function
   *
   *  Fitness function returning distance between position and frame middle
   */
  class DistanceMiddle
  {
    public:
      using Vector2 = cv::Point2d;

      /*!
       * \brief Return distance between p and frame middle
       *
       * \param frame Frame involved
       * \param p Position involved
       *  
       * \return double Distance computed
       */
      double operator()(cv::Mat frame, Vector2 p);
  };

}

