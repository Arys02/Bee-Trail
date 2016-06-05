#include "ffunctions/gray-scale-histogram.hh"
#include <iostream>

namespace beetrail
{
  using Vector2 = cv::Point2d;

  GrayScaleHistogram::GrayScaleHistogram(cv::Mat image, int square_width) :
    square(square_width), image_hist(to_hist(image))
  {
  }

  double GrayScaleHistogram::operator()(cv::Mat frame, Vector2 pos)
  {
    cv::Mat zone_of_interest;
    if (square > frame.size().width || square > frame.size().height)
      zone_of_interest = frame;
    else
      zone_of_interest = get_subimage(frame, pos, this->square);

    /* Compare histograms blabla */
    cv::MatND zone_hist = to_hist(zone_of_interest);

    double comparison =
      cv::compareHist(zone_hist, image_hist, CV_COMP_CORREL);

    std::cout << "Histogram comparison: " << comparison << std::endl;

    return comparison;
  }

  cv::MatND GrayScaleHistogram::to_hist(cv::Mat image)
  {
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, CV_BGR2HSV);

    int bins = 256;
    int hsize[] = {bins};

    float branges[] = {0};
    const float *ranges[] = {branges};

    int channels[] = {0, 1};

    cv::MatND hist;
    calcHist(&gray_image, 1, channels, cv::Mat(), hist, 2, hsize, ranges, true,
        false);

    return hist;
  }

  cv::Mat GrayScaleHistogram::get_subimage(
      cv::Mat base_image, Vector2 pos, int square)
  {
    int width = base_image.size().width;
    int height = base_image.size().height;

    int origin_x = pos.x - square / 2;
    int origin_y = pos.y - square / 2;

    int end_x = pos.x + square / 2;
    int end_y = pos.y + square / 2;

    /* Check bounds and move origin to make it fit */
    if (origin_x < 0)
    {
      end_x -= origin_x;
      origin_x = 0;
    }

    if (origin_y < 0)
    {
      end_y -= origin_y;
      origin_y = 0;
    }

    if (end_x > width - 1)
    {
      origin_x -= (width - 1 - end_x);
      end_x = width - 1;
    }

    if (end_y > height - 1)
    {
      origin_y -= (height - 1 - end_y);
      end_y = height - 1;
    }

    cv::Rect region(origin_x, origin_y, end_x - origin_x, end_y - origin_y);

    return base_image(region);
  }
}
