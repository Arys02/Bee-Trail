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
    //std::cout << "speed = " << speed_ << std::endl;

    /*if (speed_.x > max_comp || speed_.x < -max_comp)
    {
      k = 10 / speed_.x;
      if (speed_.x > 0) { speed_.x = max_comp; }
      else { speed_.x = - max_comp; }
      speed_.y *= k > 0 ? k : -k;
    }

    if (speed_.y > max_comp || speed_.y < -max_comp)
    {
      k = 10 / speed_.y;
      if (speed_.y > 0) { speed_.y = max_comp; }
      else { speed_.y = -max_comp; }

      speed_.x *= k > 0 ? k : -k;
    } */
    cap_speed(10);

    pos_ = pos_ + speed_;
    //std::cout << "X = " << pos_.x << ", Y = " << pos_.y << std::endl;
  }

  void Particle::cap_speed(double max)
  {
    double k;

    if (abs(speed_.x) > max)
    {
      k = abs(10 / speed_.x);
      speed_.x = speed_.x < 0 ?
        -max :
        max;

      speed_.y *= k;
    }

    if (abs(speed_.y) > max)
    {
      k = abs(10 / speed_.y);
      speed_.y = speed_.y < 0 ?
        -max :
        max;

      speed_.x *= k;
    }
  }
}
