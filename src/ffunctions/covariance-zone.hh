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

      CovarianceZone(cv::Mat image, int square, cv::Mat* frame);
      double operator()(Vector2 pos);

    private:
      int square_width;
      int square_height;
      MatrixXd image_covariant_matrix;
      cv::Mat* frame_;

      static double covariance_distance(MatrixXd a, MatrixXd b);
      static MatrixXd compute_matrix(const cv::Mat& m);
      static MatrixXd transform_mat(const cv::Mat& m);
      static MatrixXd make_covariance_matrix(MatrixXd m);
      static MatrixXd get_feature_mat(const cv::Mat& image);
      static cv::Mat get_x_gradient(const cv::Mat& m);
      static cv::Mat get_y_gradient(const cv::Mat& m);
  };
}
