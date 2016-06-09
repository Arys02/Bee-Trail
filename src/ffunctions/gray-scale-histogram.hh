
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

    private:
      int square;
      cv::Mat image_hist;

      static void to_hist(cv::Mat image, cv::Mat *histogram);
      static cv::Mat get_subimage(cv::Mat, Vector2 pos, int square);
  };
}
