#include "particle.hh"

namespace beetrail
{
  Vector2 Particle::best_pt_get()
  {
    return best_pt_;
  }

  Vector2 Particle::pos_get()
  {
    return pos_;
  }

  Vector2 Particle::speed_get()
  {
    return speed_;
  }

  void Particle::best_pt_set(Vector2 new_pt)
  {
    best_pt_ = new_pt;
  }

  void Particle::pos_set(Vector2 new_pos)
  {
    pos_ = new_pos;
  }

  void Particle::speed_set(Vector2 new_speed)
  {
    speed_ = new_speed;
  }

  void Particle::update(Vector2 best_swarm_pos)
  {
    /* Init variables locally (+ annoying casts) */

    /* Constants */
    double accel1 = PsoSettings::get_acceleration1();
    double accel2 = PsoSettings::get_acceleration2();
    double weight = PsoSettings::get_weight();
    double r = (double) (rand() % 1000) / (double) 1000;

    /* Best positions */
    Vector2 best_pos = best_pt_;

      /* Compute new speed */
    speed_ = weight * speed_
      + accel1 * r * (best_pos - pos_)
      + accel2 * r * (best_swarm_pos - pos_);
    std::cout << "speed = " << speed_ << std::endl;

    pos_ = pos_ + speed_;
    std::cout << "X = " << pos_.x << ", Y = " << pos_.y << std::endl;
  }
}
