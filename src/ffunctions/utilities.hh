#pragma once
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/opencv.hpp"

namespace beetrail
{
  using Vector2 = cv::Point2d;

  class Utilities
  {
    public:
      static cv::Mat get_subimage(cv::Mat base_image, Vector2 pos, int width,
          int height);

      static cv::Mat grayify(cv::Mat src);
  };
}
