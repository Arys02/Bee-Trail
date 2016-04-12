#include "video/VideoManager.hh"

namespace beetrail
{
  using namespace cv;

  VideoManager::VideoManager(std::string path) {
    if (path == "")
      capture_ = VideoCapture(0);
    else
      capture_ = VideoCapture(path);
    name_window_ = "Bee-Trail";
    namedWindow(name_window_, 1);
  }


  Mat VideoManager::get_frame()
  {
    Mat frame;
    capture_ >> frame;
    return frame;
  }
}
