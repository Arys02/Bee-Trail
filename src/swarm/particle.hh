#pragma once
#include <string>
#include <memory>
#include "opencv2/opencv.hpp"
#include "pso-settings.hh"
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
      Particle(Vector2 pos, Vector2 speed, Vector2 accel)
        : pos_(pos), speed_(speed), accel_(accel)
      { }

      Vector2 best_pt_get();
      void best_pt_set(Vector2 new_pt);

      Vector2 best_pt_swarm_get();
      void best_pt_swarm_set(Vector2 new_pt);

      Vector2 pos_get();
      void pos_set(Vector2 new_pos);

      Vector2 speed_get();
      void speed_set(Vector2 new_speed);

      Vector2 accel_get();
      void accel_set(Vector2 new_accel);

      void update(Particle best_particule);

    private:
      Vector2 best_pt_;
      Vector2 pos_;
      Vector2 speed_;
      Vector2 accel_;
  };
}
