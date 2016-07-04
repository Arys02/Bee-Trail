#pragma once
#include <opencv/highgui.h>

namespace beetrail
{
  using Vector2 = cv::Point2d;

  class Utilities
  {
    public:
      static cv::Mat get_subimage(cv::Mat base_image, Vector2 pos, int width,
          int height);
  };
}