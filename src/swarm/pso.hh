#pragma once
#include <string>
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "particle.hh"
#include "../ffunctions/image-descriptor.hh"
#include <math.h>
#include "ffunctions/distance-middle.hh"

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
   * \class VideoManager
   * \brief wrapper for opencv
   *
   *  this class will make easier the frame managment
   *  of the PSO
   */
  template <typename FF>
  class Pso
  {

    public :
      enum topology
      {
        star = 0,
        ring = 1
      };

    public:

      /*!
       * \brief Constructor
       *
       * Constructor of Particul swarm optimization algorithm
       * \param pso_opt :
       * \param img_desc_ :
       *
       */
      Pso(int nb_particles , FF& fit_fun);

      //Pso(int nb_particles, enum topology topology);

      /*!
       * \brief
       * \param lol
       */
      void update(cv::Mat frame);

      void evaluate(cv::Mat frame);


      std::vector<std::shared_ptr<Particle>> list_particle_get();

    public:
      void init(int width, int height);

      std::vector<std::shared_ptr<Particle>> list_particle_;
      Vector2 best_pos_;


      int nb_particles_;
      enum topology topology_;
      int frames_per_second_;
      bool pretty_printer_on_;
      bool time_count_on_;

      double accel1_;
      double accel2_;
      double weight_;

      FF& fit_fun_;

  };
}

#include "pso.hxx"
