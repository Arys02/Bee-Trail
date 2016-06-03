#include "ffunctions/distance-middle.hh"

namespace beetrail
{
  double DistanceMiddle::compare_positions(cv::Mat frame, Vector2 p)
  {
    Vector2 middle = Vector2(320, 240);

    return sqrt(pow(p.x - middle.x, 2) + pow(p.y - middle.y, 2));

    //return abs(cv::norm(p) - cv::norm(middle));
  }

  double DistanceMiddle::operator()(cv::Mat frame, Vector2 p)
  {
    return compare_positions(frame, p);
  }
}
