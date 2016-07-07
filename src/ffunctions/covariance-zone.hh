#pragma once
#include <Eigen/Core>
#include <opencv/highgui.h>
#include "utilities.hh"
#include <iostream>
#include <opencv2/core/eigen.hpp>

/// \authors {Charles Yaiche, Nicolas Chariglione}
/// \file video-manager.hh
/// \brief Countain opencv wrapper class
/// \version 0.1

/*! \namespace beetrail
 *  namespace getting all classes for the beetrail project
 */
namespace beetrail
{
  using namespace Eigen;
  using Vector2 = cv::Point2d;


  /*!
   * \class CovarianceZone
   * \brief Fitness function using image features and covariance matrices
   *
   * Function comparing the zone around a position and a base image by using
   * gray scale histograms.
   * It extracts a zone around a position and puts for each pixel some features
   * in a matrix. Result is the computaiton of the distance between the feature
   * matrix and the base image feature matrix
   *
   */
  class CovarianceZone
  {
    public:

      /*!
       * \brief Constructor
       *
       * Constructor of CovarianceZone object
       * \param image Base image to be compared to zones
       * \param square_width Zone around the particule side size 
       * \param frame Pointer to the frame in which zones will be extracted
       *
       */
      CovarianceZone(cv::Mat image, int square, cv::Mat* frame);

      /*!
       * \brief Distance between zone and base image
       *
       * Function computing distance between zone around position pos on frame
       * Uses zone's pixels RGB, gradient and intensity and matrix covariance
       *
       * \param pos Position in frame (center of the zone)
       *
       * \return double Distance computed
       *
       */
      double operator()(Vector2 pos);

    private:
      int square_width;
      int square_height;
      MatrixXd image_covariant_matrix;
      cv::Mat* frame_;

      /*!
       * \brief Distance between two covariance matrices
       *
       * Function computing distance between two covariance matrices
       *
       * \param a First matrix
       * \param b Second matrix
       *
       * \return double Distance computed
       *
       */
      static double covariance_distance(MatrixXd a, MatrixXd b);

      /*!
       * \brief Compute an image covariant feature matrix
       *
       * Compute an image covariant feature matrix
       *
       * \param m Reference to base image
       *
       * \return MatrixXd Covariant feature matrix computed
       *
       */
      static MatrixXd compute_matrix(const cv::Mat& m);

      /*!
       * \brief Compute a matrix's covariance matrix
       *
       * Compute matrix's covariance matrix
       *
       * \param m Input matrix
       *
       * \return MatrixXd Covariant matrix computed
       *
       */
      static MatrixXd make_covariance_matrix(MatrixXd m);

      /*!
       * \brief Generates an image's feature matrix
       *
       * Generates an image's feature matrix.
       * Features are pixel RGB, gradient and intensity
       *
       * \param image Reference to input image
       *
       * \return MatrixXd Feature matrix generated 
       *
       */
      static MatrixXd get_feature_mat(const cv::Mat& image);

      /*!
       * \brief Generates an image gradient (left to right gradient)
       *
       * Generates an image gradient (left to right gradient) using openCV
       *
       * \param m Reference to input image
       *
       * \return cv::Mat Gradient image generated
       *
       */
      static cv::Mat get_x_gradient(const cv::Mat& m);

      /*!
       * \brief Generates an image gradient (top to bottom gradient)
       *
       * Generates an image gradient (top to bottom gradient) using openCV
       *
       * \param m Reference to input image
       *
       * \return cv::Mat Gradient image generated
       *
       */
      static cv::Mat get_y_gradient(const cv::Mat& m);
  };
}
