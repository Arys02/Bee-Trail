#pragma once
#include <string>
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "particle.hh"
#include <math.h>
#include "ffunctions/distance-middle.hh"
#include "tbb/tbb.h"
#include <thread>
#include <chrono>
#include <sstream>

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

    public:

      /*!
       * \brief Constructor
       *
       * Constructor of Particul swarm optimization algorithm
       * \param nb_particles_ : number of particles in the swarm
       * \param fit_fun : fitness function
       *
       */
      Pso(int nb_particles , FF& fit_fun);

      /*!
       * \brief Call update on each particles
       */
      void update();

      /*!
       * \brief Evaluate the new best position for eache particules
       *  using the fitness function
       */
      void evaluate();



      /*!
       * \brief Getter of then vector of particles
       */
      std::vector<std::shared_ptr<Particle>> list_particle_get();

    public:
      /*!
       * \brief initialize the pso
       * \param width, height : size of the pso environment
       */
      void init(int width, int height);

      std::vector<std::shared_ptr<Particle>> list_particle_;
      Vector2 best_pos_;


      int nb_particles_;
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
