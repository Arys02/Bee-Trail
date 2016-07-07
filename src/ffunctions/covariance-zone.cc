#include "covariance-zone.hh"

namespace beetrail
{
  using namespace Eigen;
  using Vector2 = cv::Point2d;

  CovarianceZone::CovarianceZone(cv::Mat image, int square, cv::Mat* frame) :
    square_width(square),
    square_height(square),
    image_covariant_matrix(compute_matrix(image)),
    frame_(frame)
  {
  }

  double CovarianceZone::operator()(Vector2 pos)
  {
    if (frame_ != nullptr)
    {
      cv::Mat subimage = Utilities::get_subimage(*frame_, pos, square_width,
          square_height);
      MatrixXd matrix = compute_matrix(subimage);

      double d = std::abs(covariance_distance(matrix, image_covariant_matrix));

      return d;
    }

    return 0;
  }

  MatrixXd CovarianceZone::compute_matrix(const cv::Mat& m)
  {
    MatrixXd mat = get_feature_mat(m);
    return make_covariance_matrix(mat);
  }


  double CovarianceZone::covariance_distance(MatrixXd a, MatrixXd b)
  {
    return 1.0 - (double) ((a * b).trace() / (a.norm() * b.norm()));
  }

  MatrixXd CovarianceZone::make_covariance_matrix(MatrixXd m)
  {
    MatrixXd centered = m.rowwise() - m.colwise().mean();
    if (m.rows() != 1)
    {
      MatrixXd cov = (centered.adjoint() * centered) / double(m.rows() - 1);

      return cov;
    }

    std::cerr << "Matrix to compute the covariance width is = 1." << std::endl;
    return m;
  }

  MatrixXd CovarianceZone::get_feature_mat(const cv::Mat& image)
  {
    /* Construct feature matrix with r, g, b, xgradient, ygradient */
    cv::Mat intensity_image = Utilities::grayify(image);
    cv::Mat x_gradient_image = get_x_gradient(intensity_image);
    cv::Mat y_gradient_image = get_y_gradient(intensity_image);

    int width = 6; /* R, G, B, I, Xg, Yg */
    int height = image.size().width * image.size().height;

    MatrixXd feature_matrix(height, width);

    int image_width = image.size().width;
    int image_height= image.size().height;
    for(int i = 0 ; i < image_width ; i++)
    {
      for (int j = 0 ; j < image_height ; j++)
      {
        double b = (double) image.at<cv::Vec3b>(j, i)[0];
        double g = (double) image.at<cv::Vec3b>(j, i)[1];
        double r = (double) image.at<cv::Vec3b>(j, i)[2];
        double intensity = (double) intensity_image.at<cv::Vec3b>(j, i)[0];
        double x_grad = (double) x_gradient_image.at<cv::Vec3b>(j, i)[0];
        double y_grad = (double) y_gradient_image.at<cv::Vec3b>(j, i)[0];
        RowVectorXd vec(width);
        vec << r, g, b, intensity, x_grad, y_grad;
        feature_matrix.row(image_height * i + j) << vec;
      }
    }

    return feature_matrix;
  }

  cv::Mat CovarianceZone::get_x_gradient(const cv::Mat& m)
  {
    cv::Mat out;
    cv::Sobel(m, out, CV_64F, 1, 0, 3);
    return out;
  }

  cv::Mat CovarianceZone::get_y_gradient(const cv::Mat& m)
  {
    cv::Mat out;
    cv::Sobel(m, out, CV_64F, 0, 1, 3);
    return out;
  }
}
