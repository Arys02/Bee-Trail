#include "ffunctions/gray-scale-histogram.hh"
#include <iostream>

namespace beetrail
{
  using Vector2 = cv::Point2d;

  GrayScaleHistogram::GrayScaleHistogram(cv::Mat image, int square_width, cv::Mat* frame)
  {
    square = square_width;
    to_hist(image, &image_hist);
    std::cout << image_hist << std::endl;
    frame_ = frame;
  }

  double GrayScaleHistogram::operator()(Vector2 pos)
  {
    cv::Mat zone_of_interest = Utilities::get_subimage(*frame_, pos,
        this->square, this->square);

    /* Compare histograms */
    cv::Mat zone_hist;
    to_hist(zone_of_interest, &zone_hist);

    /* Same histograms comparison returns 1 */
    double comparison =
      1 - cv::compareHist(zone_hist, image_hist, CV_COMP_CORREL);
    comparison = comparison < 0 ? - comparison : comparison;

    //std::cout << "Histogram comparison: " << comparison << std::endl;

    return comparison;
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

    *histogram = b_hist;
  }
}
