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
    /* Constants */
    double r = (double) (rand() % 1000) / (double) 1000;

    /* Compute new speed */
    speed_ = weight_ * speed_
      + accel1_ * r * (best_pt_ - pos_)
      + accel2_ * r * (best_swarm_pos - pos_);

    std::cout << "Pos: " << std::endl;
    std::cout << "Global best: " << best_swarm_pos << ". Best: " << best_pt_ <<
      std::endl;
    std::cout << "Computed speed: " << speed_ << std::endl;
    cap_speed(10);
    std::cout << "New speed: " << speed_ << std::endl;
    pos_ = pos_ + speed_;
  }

  void Particle::cap_speed(double max)
  {
    double k;

    if (std::abs(speed_.y) > max)
    {
      k = std::abs(max / speed_.y);
      speed_.y = speed_.y > 0 ? max : - max;

      speed_.x = k * speed_.x;
    }

    if (std::abs(speed_.x) > max)
    {
      k = abs(max / speed_.x);
      speed_.x = speed_.x > 0 ? max : - max;

      speed_.y = k * speed_.y;
    }

  }
}
