#pragma once
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/opencv.hpp"

/// \authors {Charles Yaiche, Nicolas Chariglione}
/// \file video-manager.hh
/// \brief Countain opencv wrapper class
/// \version 0.1

/*! \namespace beetrail
 *  namespace getting all classes for the beetrail project
 */
namespace beetrail
{
  using Vector2 = cv::Point2d;

  /*!
   * \class Utilities
   * \brief Class containing functions used in multiple fitness function
   * implementations
   *
   */
  class Utilities
  {
    public:
      /*!
       * \brief Get zone around a position in an image
       *
       * Extract a zone on subimage around position pos. If the zone is out of 
       * the frame bounds, automatically move the middle of the subimage so it
       * fits
       *
       * \param base_image Image containing zone of interest
       * \param pos Center of the zone of interest
       * \param width Zone width
       * \param height Zone height
       *
       * \return cv::Mat Subimage extracted
       *
       */
      static cv::Mat get_subimage(cv::Mat base_image, Vector2 pos, int width,
          int height);

      /*!
       * \brief Get a gray image
       *
       * Generates a gray image from source image
       *
       * \param src Reference to image to modify
       *
       * \return cv::Mat Gray image
       *
       */
      static cv::Mat grayify(const cv::Mat& src);
  };
}
