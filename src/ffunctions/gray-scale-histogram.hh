
#include "video/video-manager.hh"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "opencv2/opencv.hpp"

namespace beetrail
{
  class GrayScaleHistogram
  {
    public:

      using Vector2 = cv::Point2d;
      GrayScaleHistogram(cv::Mat image, int square_width);

      double operator()(cv::Mat frame, Vector2 pos);

      cv::MatND image_hist;
    private:
      int square;

      static cv::MatND to_hist(cv::Mat image);
      static cv::Mat get_subimage(cv::Mat, Vector2 pos, int square);
  };
}
