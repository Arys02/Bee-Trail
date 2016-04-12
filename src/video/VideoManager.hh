#pragma once
#include <string>
#include "opencv2/opencv.hpp"

namespace beetrail
{
  class VideoManager
  {
    public:
      VideoManager(std::string path);
      VideoManager();
      cv::Mat frame_get();
      bool check_file();

      std::string name_window_get();
      cv::VideoCapture capture_get();

    private:
        cv::VideoCapture capture_;
        std::string name_window_;
  };
}
