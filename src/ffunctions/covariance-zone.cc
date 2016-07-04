#include "covariance-zone.hh"

namespace beetrail
{
  using namespace Eigen;
  using Vector2 = cv::Point2d;

  CovarianceZone::CovarianceZone(cv::Mat image, cv::Mat* frame) :
    square_width(image.size().width),
    square_height(image.size().height),
    image_covariant_matrix(make_covariance_matrix(image)),
    frame_(frame)
  {
  }

  double CovarianceZone::operator()(Vector2 pos)
  {
    /* Get subimage */
    /* Put subimage in matrixXd */
    /* Calculate covariance of this matrix */
    /* Return covariance distance between this matrix and image_covariant_matr*/
    return 0;
  }

  double CovarianceZone::covariance_distance(MatrixXd a, MatrixXd b)
  {
    return 0;
  }

  cv::Mat CovarianceZone::get_subimage(cv::Mat image, Vector2 pos, int square)
  {
    return image;
  }

  MatrixXd CovarianceZone::make_covariance_matrix(cv::Mat m)
  {
  }

  MatrixXd CovarianceZone::transform_mat(cv::Mat m)
  {
  }
}
