
#include "video/video-manager.hh"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/opencv.hpp"
#include "utilities.hh"

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
   * \class GrayScaleHistogram
   * \brief Fitness function using gray scale histograms
   *
   * Function comparing the zone around a position and a base image by using
   * gray scale histograms.
   */
  class GrayScaleHistogram
  {
    public:

      using Vector2 = cv::Point2d;
      /*!
       * \brief Constructor
       *
       * Constructor of GrayScaleHistogram object
       * \param image Base image to be compared to zones
       * \param square_width Zone around the particule side size 
       * \param frame Pointer to the frame in which zones will be extracted
       *
       */
      GrayScaleHistogram(cv::Mat image, int square_width, cv::Mat* frame);

      /*!
       * \brief Distance between zone and base image
       *
       * Function computing distance between zone around position pos on frame
       * First gets zone around position, then computes its gray scale histogram
       * and finally compute distance between base image histogram and this
       * zone histogram by using openCV correlation method
       *
       * \param pos Position in frame (center of the zone)
       *
       * \return double Distance computed
       *
       */
      double operator()(Vector2 pos);

    private:
      int square;
      cv::Mat image_hist;
      cv::Mat* frame_;

      /*!
       * \brief Compute image histogram
       *
       * Compute an image gray scale histogram
       *
       * \param image Image to compute histogram from
       * \param histogram Pointer to address in which histogram will be put
       *
       */
      static void to_hist(cv::Mat image, cv::Mat *histogram);
  };
}
