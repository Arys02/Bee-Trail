#include "video-manager.hh"

/// \file video-manager.cc

namespace beetrail
{
  using namespace cv;

  VideoManager::VideoManager(std::string path)
    : capture_(path.c_str())
  {
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

  bool
    VideoManager::check_file()
    {
      return capture_.isOpened();
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

  void
    VideoManager::draw_square(int size, int x, int y, Mat frame)
    {
      for (int i = x; i < x + size; i ++)
        for (int j = y; j < y + size; j ++)
        {
          auto s = frame.size();

          std::cout << "i : " << i << ", j :" << j << "\n";
          std::cout << "x : " << x << ", y :" << y << "\n";
          std::cout << "size : " << size << "\n";
          if (i < s.height && j < s.width)
          {
            Vec3b color = frame.at<Vec3b>(Point(i, j));
            color.val[0] = 0;
            color.val[1] = 255;
            color.val[2] = 0;
            frame.at<Vec3b>(Point(i, j)) = color;

          }
        }
    }
}
