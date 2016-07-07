#pragma once
#include <string>
#include "opencv2/opencv.hpp"
#include "swarm/particle.hh"
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
      using p_vector = std::vector<std::shared_ptr<Particle>>;


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

      /*!
       * \brief Add a green square at position p on frame
       * \param p : position
       * \param frame : frame to modify
       */
      void pretty_print(p_vector p, cv::Mat frame);

      /*!
       * \brief Display frame on a window named "Bee-Trail"
       * \param frame : frame to display
       * \param stop : reference to int set to true if user presses a key
       */
      void display_frame(cv::Mat frame, int& stop);


      /*!
       * \brief video width getter
       */
      double width_get();

      /*!
       * \brief video width getter
       */
      double height_get();

    private:
      cv::VideoCapture capture_;
      std::string name_window_;
      double width_;
      double height_;
  };
}
