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
    /* TODO; set width_ and height_ */
  }

  VideoManager::VideoManager()
    : capture_(0)
  {
    name_window_ = "Bee-Trail";
    namedWindow(name_window_, 1);
    moveWindow("Bee-Trail", 0, 0);
    width_ = capture_.get(CV_CAP_PROP_FRAME_WIDTH);
    height_ = capture_.get(CV_CAP_PROP_FRAME_HEIGHT);
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

  void
    VideoManager::pretty_print(std::shared_ptr<Pso> pso, Mat frame)
    {
      for (std::shared_ptr<Particle> p : pso->list_particle_get())
      {
        double x = p->pos_get().x;
        double y = p->pos_get().y;

        if (x >= 0 && x < width_ && y >= 0 && y < height_)
          draw_square(2, x, y, frame);
      }
    }

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
