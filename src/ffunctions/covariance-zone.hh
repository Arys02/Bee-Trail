#pragma once
#include <Eigen/Core>
#include <opencv/highgui.h>
#include "utilities.hh"
#include <iostream>
#include <opencv2/core/eigen.hpp>

namespace beetrail
{
  using namespace Eigen;
  using Vector2 = cv::Point2d;


  class CovarianceZone
  {
    public:

      CovarianceZone(cv::Mat image, cv::Mat* frame);
      double operator()(Vector2 pos);

    private:
      int square_width;
      int square_height;
      MatrixXd image_covariant_matrix;
      cv::Mat* frame_;

      static double covariance_distance(MatrixXd a, MatrixXd b);
      static MatrixXd transform_mat(cv::Mat m);
      static MatrixXd make_covariance_matrix(MatrixXd m);
  };
}
