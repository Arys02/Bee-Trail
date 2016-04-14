#pragma once
#include <string>
#include <memory>
#include "opencv2/opencv.hpp"
#include "pso-settings.hh"
#include "../ffunctions/image-descriptor.hh"

/// \authors {Charles Yaiche, Nicolas Chariglione}
/// \file particle.hh
/// \brief Countain particle class for the PSO
/// \version 0.1

/*! \namespace beetrail
 *  namespace getting all classes for the beetrail project
 */
namespace beetrail
{

  using Vector2 = cv::Point2f;

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
      Particle(cv::Point pos, Vector2 speed, Vector2 accel)
        : pos_(pos), speed_(speed), accel_(accel)
      { }

      cv::Point best_pt_get();
      void best_pt_set(cv::Point new_pt);

      cv::Point best_pt_swarm_get();
      void best_pt_swarm_set(cv::Point new_pt);

      cv::Point pos_get();
      void pos_set(cv::Point new_pos);

      Vector2 speed_get();
      void speed_set(Vector2 new_speed);

      Vector2 accel_get();
      void accel_set(Vector2 new_accel);

      /*!
       * \brief
       * \param lol
       */
      // TODO update 
      //void update();

    private:
      cv::Point best_pt_;
      cv::Point best_pt_swarm_;
      cv::Point pos_;
      Vector2 speed_;
      Vector2 accel_;
  };
}
