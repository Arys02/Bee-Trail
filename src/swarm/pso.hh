#pragma once
#include <string>
#include <memory>
#include "opencv2/opencv.hpp"
#include "particule.hh"
#include "pso-settings.hh"
#include "../ffunctions/image-descriptor.hh"

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
       * Constructor of Particul swarm optimization algorithme
       * \param pso_opt :
       * \param img_desc_ :
       *
       */
      Pso();
      Pso(std::shared_ptr<PsoSettings> pso_opt,
          std::shared_ptr<ImageDescriptor> img_desc);

      /*!
       * \brief
       * \param lol
       */
      void update(cv::Mat frame);

      std::shared_ptr<PsoSettings> pso_opt_get();

      std::shared_ptr<ImageDescriptor> img_desc_get();



    private:
      //Vector<Particule> list_particule_;
      std::shared_ptr<PsoSettings> pso_opt_;
      std::shared_ptr<ImageDescriptor> img_desc_;
      //std::sharedptr best particule
  };
}
