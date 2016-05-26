#pragma once
#include <string>
#include <memory>
#include "opencv2/opencv.hpp"
#include "../ffunctions/image-descriptor.hh"
#include <math.h>

/// \authors {Charles Yaiche, Nicolas Chariglione}
/// \file particle.hh
/// \brief Countain particle class for the PSO
/// \version 0.1

/*! \namespace beetrail
 *  namespace getting all classes for the beetrail project
 */
namespace beetrail
{
  //using namespace cv;

  using Vector2 = cv::Point2d;

  /*!
   * \class particle 
   * \brief wrapper for opencv
   *
   *  this class will make easier the frame managment
   *  of the PSO
   */
  template <typename T>
  class Pso;
  class Particle
  {
    public:
      /*!
       * \brief Constructor
       *
       * Constructor of Particle 
       * \param pos : initial position of the particle
       * \param speed : initial of the particle 
       * \param accel : initial of the particle 
       *
       */

      Particle(Vector2 pos, Vector2 speed, Pso<T>* pso)
        : best_pt_(pos), pos_(pos), speed_(speed), pso_(pso)
      { }

      Vector2 best_pt_get();
      void best_pt_set(Vector2 new_pt);

      Vector2 pos_get();
      void pos_set(Vector2 new_pos);

      Vector2 speed_get();
      void speed_set(Vector2 new_speed);

      void update(Vector2 best_swarm_point);

    public:
      void cap_speed(double max);
      Vector2 best_pt_;
      Vector2 pos_;
      Vector2 speed_;

      Pso* pso_;
  };
}
