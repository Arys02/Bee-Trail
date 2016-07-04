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
      cv::Mat subimage = Utilities::get_subimage(*frame, pos, square_width,
          square_height);

      MatrixXd matrix = transform_mat(subimage);

      matrix = make_covariance_matrix(matrix);

      return covariance_distance(matrix, image_covariant_matrix);
    }
    std::err << "Frame is null. Cannot compute covariance zone" << std::endl;


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
  }

  MatrixXd CovarianceZone::transform_mat(cv::Mat m)
  {
  }
}
