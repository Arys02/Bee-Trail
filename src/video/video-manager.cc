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
    width_ = capture_.get(CV_CAP_PROP_FRAME_WIDTH);
    height_ = capture_.get(CV_CAP_PROP_FRAME_HEIGHT);
  }

  VideoManager::VideoManager()
    : capture_(0)
  {
    name_window_ = "Bee-Trail";
    namedWindow(name_window_, 1);
    moveWindow("Bee-Trail", 0, 0);
    width_ = capture_.get(CV_CAP_PROP_FRAME_WIDTH);
    height_ = capture_.get(CV_CAP_PROP_FRAME_HEIGHT);
    std::cout << "width = " << width_;
    std::cout << "height = " << height_;
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
    VideoManager::draw_square(int size, int x, int y, Mat frame,
        int r, int g, int b)
    {
      for (int i = x; i < x + size; i ++)
        for (int j = y; j < y + size; j ++)
        {
          auto s = frame.size();

          if (i >= 0 && j >= 0 && i < s.width && j < s.height)
          {
            Vec3b color = frame.at<Vec3b>(Point(i, j));
            color.val[0] = r;
            color.val[1] = g;
            color.val[2] = b;
            frame.at<Vec3b>(Point(i, j)) = color;
          }
        }
    }

  /*
  template <typename T>
  void VideoManager::pretty_print(Pso<T>& pso, Mat frame)
    {
      for (auto p : pso.list_particle_get())
      {
        double x = p->pos_get().x;
        double y = p->pos_get().y;

        draw_square(2, x, y, frame, 0, 255, 0);
      }
    }
    */

  void VideoManager::display_frame(cv::Mat frame, int& stop)
  {
    cv::imshow("Bee-Trail", frame);
    stop = cv::waitKey(30) >= 0;
  }


  double VideoManager::width_get()
  {
    return width_;
  }

  double VideoManager::height_get()
  {
    return height_;
  }
}
