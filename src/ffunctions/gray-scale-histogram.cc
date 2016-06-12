#include "ffunctions/gray-scale-histogram.hh"
#include <iostream>

namespace beetrail
{
  using Vector2 = cv::Point2d;

  GrayScaleHistogram::GrayScaleHistogram(cv::Mat image, int square_width) //:
    //square(square_width), image_hist()
  {
    square = square_width;
    to_hist(image, &image_hist);
  }

  double GrayScaleHistogram::operator()(cv::Mat frame, Vector2 pos)
  {
    cv::Mat zone_of_interest;
    if (square > frame.size().width || square > frame.size().height)
      zone_of_interest = frame;
    else
      zone_of_interest = get_subimage(frame, pos, this->square);

    /* Compare histograms blabla */
    cv::Mat zone_hist;
    to_hist(zone_of_interest, &zone_hist);

    double comparison =
      cv::compareHist(zone_hist, image_hist, CV_COMP_CORREL);

    std::cout << "Histogram comparison: " << comparison << std::endl;

    /* Same histograms comparison returns 1 */
    return (1 - comparison);
  }

  void GrayScaleHistogram::to_hist(cv::Mat image, cv::Mat *histogram)
  {
    cv::Mat gray_image;
    cv::cvtColor(image, gray_image, CV_BGR2GRAY);
    int histSize = 256;
    float range[] = { 0, 256};
    const float* histRange = { range };
    bool uniform = true;
    bool accumulate = false;
    cv::Mat b_hist;

    cv::calcHist(&gray_image, 1, 0, cv::Mat(), b_hist, 1,
        &histSize, &histRange, uniform, accumulate);

    b_hist.copyTo(*histogram);
  }

  cv::Mat GrayScaleHistogram::get_subimage(
      cv::Mat base_image, Vector2 pos, int square)
  {
    //pos = Vector2(851.2, 214.2);
    //square = 200;
    // base image 400w 850h

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
