#include "ffunctions/distance-middle.hh"

namespace beetrail
{
  double DistanceMiddle::compare_positions(Vector2 p)
  {
    Vector2 middle = Vector2(320, 240);
    return sqrt(pow(p.x - middle.x, 2) + pow(p.y - middle.y, 2));
  }

  double DistanceMiddle::operator()(Vector2 p)
  {
    return DistanceMiddle::compare_positions(p);
  }
}
