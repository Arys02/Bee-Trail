#include "covariance-zone.hh"

namespace beetrail
{
  using namespace Eigen;
  using Vector2 = cv::Point2d;

  CovarianceZone::CovarianceZone(cv::Mat image, cv::Mat* frame) :
    square_width(image.size().width),
    square_height(image.size().height),
    image_covariant_matrix(make_covariance_matrix(transform_mat(image))),
    frame_(frame)
  {
  }

  double CovarianceZone::operator()(Vector2 pos)
  {
    if (frame_ != nullptr)
    {
      cv::Mat subimage = Utilities::get_subimage(*frame_, pos, square_width,
          square_height);
      subimage = Utilities::grayify(subimage);

      MatrixXd matrix = transform_mat(subimage);

      matrix = make_covariance_matrix(matrix);

      return covariance_distance(matrix, image_covariant_matrix);
    }
    std::cerr << "Frame is null. Cannot compute covariance zone" << std::endl;


    /* Put subimage in matrixXd */
    /* Calculate covariance of this matrix */
    /* Return covariance distance between this matrix and image_covariant_matr*/
    return 0;
  }

  double CovarianceZone::covariance_distance(MatrixXd a, MatrixXd b)
  {
    return 0;
  }

  MatrixXd CovarianceZone::make_covariance_matrix(MatrixXd m)
  {
    std::cout << "Base matrix = " << m << std::endl << std::endl;
    MatrixXd centered = m.rowwise() - m.colwise().mean();
    if (m.rows() != 1)
    {
      MatrixXd cov = (centered.adjoint() * centered) / double(m.rows() - 1);
      std::cout << "Cov matrix = " << cov << std::endl;

      return cov;
    }

    std::cerr << "Matrix to compute the covariance width is = 1." << std::endl;
    return m;
  }

  MatrixXd CovarianceZone::get_feature_mat(const cv::Mat& image)
  {
    /* Construct feature matrix with r, g, b, xgradient, ygradient */
    cv::Mat x_gradient_image = get_x_gradient(image);
    cv::Mat y_gradient_image = get_y_gradient(image);
    cv::Mat intensity_image = Utilities::grayify(image);

    int width = 6; /* R, G, B, I, Xg, Yg */
    int height = image.size().width * image.size().height;

    MatrixXd feature_matrix(width, height);

    for(int i = 0 ; i < image.size().width ; i++)
    {
      for (int j = 0 ; j < image.size().height ; j++)
      {
        double b = (double) image.at<cv::Vec3b>(i, j)[0];
        double g = (double) image.at<cv::Vec3b>(i, j)[1];
        double r = (double) image.at<cv::Vec3b>(i, j)[2];
        double i = (double) intensity_image.at<int>(i, j);
        double x_grad = x_gradient_image.at<double>(i, j);
        double y_grad = y_gradient_image.at<double>(i, j);
        RowVectorXd vec(6);
        vec << r, g, b, i, x_grad, y_grad;

        feature_matrix << vec;
      }
    }

    return feature_matrix;
  }

  MatrixXd CovarianceZone::transform_mat(const cv::Mat& m)
  {
    MatrixXd matrix;
    cv::cv2eigen(m, matrix);
    return matrix;
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
