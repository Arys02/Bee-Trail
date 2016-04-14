#include "particle.hh"

namespace beetrail
{
  using namespace cv;
  using Vector2 = Point2f;

  Point Particle::best_pt_get()
  {
    return best_pt_;
  }

  Point Particle::best_pt_swarm_get()
  {
    return best_pt_swarm_;
  }

  Point Particle::pos_get()
  {
    return pos_;
  }

  Vector2 Particle::speed_get()
  {
    return speed_;
  }

  Vector2 Particle::accel_get()
  {
    return accel_;
  }

  void Particle::best_pt_set(Point new_pt)
  {
    best_pt_ = new_pt;
  }

  void Particle::best_pt_swarm_set(Point new_pt)
  {
    best_pt_swarm_ = new_pt;
  }

  void Particle::pos_set(Point new_pos)
  {
    pos_ = new_pos;
  }

  void Particle::speed_set(Vector2 new_speed)
  {
    speed_ = new_speed;
  }

  void Particle::accel_set(Vector2 new_accel)
  {
    accel_ = new_accel;
  }

}
