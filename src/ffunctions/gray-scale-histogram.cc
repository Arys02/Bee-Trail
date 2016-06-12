#include "ffunctions/gray-scale-histogram.hh"
#include <iostream>

namespace beetrail
{
  using Vector2 = cv::Point2d;

  //GrayScaleHistogram::GrayScaleHistogram(cv::Mat image, int square_width, cv::Mat* frame) //:

    //square(square_width), image_hist()
  GrayScaleHistogram::GrayScaleHistogram(cv::Mat image, int square_width)
  {
    square = square_width;
    to_hist(image, &image_hist);
    frame_ = frame;
  }

  double GrayScaleHistogram::operator()(Vector2 pos)
  {
    cv::Mat zone_of_interest;
    if (square > frame_->size().width || square > frame_->size().height)
      zone_of_interest = *frame_;
    else
      zone_of_interest = get_subimage(*frame_, pos, this->square);

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

        /*

    for (int i = 0 ; i < bgr_planes[0].rows; i++)
    {
      for (int j = 0 ; j < bgr_planes[0].cols ; j++)
      {
        int b = bgr_planes[0].at<int>(i, j);
        int r = bgr_planes[1].at<int>(i, j);
        int g = bgr_planes[2].at<int>(i, j);
        int grey_value = (int) ((double) r * 0.3 + (double) g * 0.59
            + (double) b * 0.11);

        //int a = bgr_planes[0].at<int>(i, j);
        if (bgr_planes[0].at<int>(i, j))
        {
          int a = bgr_planes[0].at<int>(i, j);

          //std::cout << "--------- llloooooolll --------- \n";
        }

        //else 
         // std::cout << "i " << i << " j " << j << "\n";
        //= grey_value;
        //
      }
    }

    std::cout << "Avant : " << std::endl;
    std::cout << "b_hist = " << b_hist << std::endl;
    std::cout << "Pointer = " << *histogram << std::endl;
    std::cout << std::endl;
    cv::calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1,
        &histSize, &histRange, uniform, accumulate);

    b_hist.copyTo(*histogram);
    std::cout << "Après : " << std::endl;
    std::cout << "b_hist = " << b_hist << std::endl;
    std::cout << "Pointer = " << *histogram << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    b_hist.release();
    //std::cout << "xd";

    // A la destruction de b_hist, ça explose ffs */
    cv::calcHist(&gray_image, 1, 0, cv::Mat(), b_hist, 1,
        &histSize, &histRange, uniform, accumulate);

    b_hist.copyTo(*histogram);
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
      origin_x -= (end_x - width - 1);
      end_x = width - 1;
    }

    if (end_y > height - 1)
    {
      origin_y -= (end_y - height - 1);
      end_y = height - 1;
    }

    cv::Rect region(origin_x, origin_y, end_x - origin_x, end_y - origin_y);

    return base_image(region);
  }
}
