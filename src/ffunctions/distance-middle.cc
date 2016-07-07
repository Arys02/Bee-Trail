#include "ffunctions/distance-middle.hh"

namespace beetrail
{
  double DistanceMiddle::operator()(cv::Mat frame, Vector2 p)
  {
    Vector2 middle = Vector2(p.size().widthm p.size().height);

    return sqrt(pow(p.x - middle.x, 2) + pow(p.y - middle.y, 2));
  }
}
