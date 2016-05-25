#pragma once
#include <string>
#include "opencv2/opencv.hpp"
#include "swarm/pso.hh"
#include <unistd.h>

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
  class VideoManager
  {
    public:
      /*!
       * \brief Constructor
       *
       * Constructor of VideoManager
       * \param path : the path of the video file
       *
       */

      VideoManager(std::string path);

      /*!
       * \brief Constructor
       *
       * Constructor of VideoManager
       * will open the default camera
       *
       */
      VideoManager();
      /*!
       * \brief frame_ getter
       *  will get a new frame from capture__
       * \return Matrix image(frame) from getter
       */
      cv::Mat frame_get();

      /*!
       * \brief check if capture_ is well opened
       * \return true if capture_ is open false otherwise
       */

      bool check_file();


      /*!
       * \brief name_window getter
       */

      std::string name_window_get();

      /*!
       * \brief capture__ getter
       */
      cv::VideoCapture capture_get();

      /*!
       * \brief draw a square on a frame
       * \param size : size of the square
       * \param x, y : coordonate on the frame where to draw
       * \param frame : frame
       */
      void draw_square(int size, int x, int y, cv::Mat frame,
          int r, int g, int b);

      void pretty_print(Pso& pso, cv::Mat frame);

      void display_frame(cv::Mat frame, int& stop);

      double width_get();

      double height_get();

    private:
      cv::VideoCapture capture_; /*!< Videocapture type*/
      std::string name_window_; /*!< Name of the generate window*/
      double width_;
      double height_;
  };
}
