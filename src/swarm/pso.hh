#pragma once
#include <string>
#include <memory>
#include <vector>
#include "opencv2/opencv.hpp"
#include "particle.hh"
#include "pso-settings.hh"
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
  class Pso
  {
    public:
      /*!
       * \brief Constructor
       *
       * Constructor of Particul swarm optimization algorithm
       * \param pso_opt :
       * \param img_desc_ :
       *
       */
      Pso(std::shared_ptr<PsoSettings> pso_opt,
          std::shared_ptr<ImageDescriptor> img_desc);

      /*!
       * \brief
       * \param lol
       */
      void update(cv::Mat frame);

      void evaluate();

      std::shared_ptr<PsoSettings> pso_opt_get();

      std::shared_ptr<ImageDescriptor> img_desc_get();

      std::vector<std::shared_ptr<Particle>> list_particle_get();

    private:
      std::vector<std::shared_ptr<Particle>> list_particle_;
      std::shared_ptr<PsoSettings> pso_opt_;
      std::shared_ptr<ImageDescriptor> img_desc_;
      std::shared_ptr<Particle> best_particle_;
  };
}
