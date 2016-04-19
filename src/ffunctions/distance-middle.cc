#include "ffunctions/distance-middle.hh"

namespace beetrail
{
  int DistanceMiddle::compare_positions(Vector2 p1, Vector2 p2)
  {
    Vector2 middle = Vector2(320, 240);


    double norm_p1 = abs(cv::norm(p1) - cv::norm(middle));
    double norm_p2 = abs(cv::norm(p2) - cv::norm(middle));

    return norm_p1 < norm_p2;
  }

  int DistanceMiddle::compare_particles(std::shared_ptr<Particle> p1,
      std::shared_ptr<Particle> p2)
  {
    if (p1 && p2)
      return compare_positions(p1->pos_get(), p2->pos_get());

    return p1 != nullptr;
  }
}
