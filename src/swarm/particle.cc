#include "particle.hh"

namespace beetrail
{
  //using namespace cv;
  //using Vector2 = cv::Point2d;


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

  Vector2 Particle::accel_get()
  {
    return accel_;
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

  void Particle::accel_set(Vector2 new_accel)
  {
    accel_ = new_accel;
  }



  void Particle::update(std::shared_ptr<Particle> best_particule)
  {
    /* Init variables locally (+ annoying casts) */

    /* Constants */
    double accel1 = PsoSettings::get_acceleration1();
    double accel2 = PsoSettings::get_acceleration2();
    double weight = PsoSettings::get_weight();
    double r = (double) (rand() % 1000) / (double) 1000;

    /* Best positions */
    Vector2 best_pos = best_pt_;
    Vector2 best_swarm_pos = best_particule->pos_;

    std::cout << "r = " << r << std::endl;
    std::cout << "accel1 = " << accel1 << std::endl;
    std::cout << "accel2 = " << accel2 << std::endl;
    std::cout << "weight = " << weight << std::endl;
    std::cout << "weight * speed + accel1 * r * (best_pos - pos) + accel2 * r *";
      std::cout << "(best_swarm_pos - pos)" << std::endl;
    std::cout << std::endl;

      /* Compute new speed */
    std::cout << "old speed: " << speed_ << std::endl;
    speed_ = weight * speed_
      + accel1 * r * (best_pos - pos_)
      + accel2 * r * (best_swarm_pos - pos_);
    std::cout << "new speed: " << speed_ << std::endl;

    std::cout << "old_pos: " << pos_ << std::endl;
    pos_ = pos_ + speed_;
    std::cout << "new_pos: " << pos_ << std::endl;

    if (pos_ < 0)
      pos_ = 0;
  }
}
