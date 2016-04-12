#include "VideoManager.hh"

namespace beetrail
{
  using namespace cv;

  VideoManager::VideoManager(std::string path)
  {
    if (path == "")
      capture_ =  VideoCapture(0);
    else
      capture_ = VideoCapture(path);
    name_window_ = "Bee-Trail";
    namedWindow(name_window_, 1);
  }

  VideoManager::VideoManager()
    : capture_(0)
  {
    name_window_ = "Bee-Trail";
    namedWindow(name_window_, 1);
  }


  std::string
  VideoManager::name_window_get()
  {
    return name_window_;
  }

  Mat
  VideoManager::frame_get()
  {
    Mat frame;
    capture_ >> frame;
    return frame;
  }

  VideoCapture
  VideoManager::capture_get()
  {
    return capture_;
  }
}
