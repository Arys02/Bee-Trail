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



  void Particle::update(Particle best_particule)
  {
    /* Init variables locally (+ annoying casts) */

    /* Constants */
    double accel1 = PsoSettings::get_acceleration1();
    double accel2 = PsoSettings::get_acceleration2();
    double weight = PsoSettings::get_weight();
    double r = (double) rand() / (double) 1000;

    /* Best positions */
    Vector2 best_pos = best_pt_;
    Vector2 best_swarm_pos = best_particule.pos_;


      /* Compute new speed */
    speed_ = weight * speed_
      + accel1 * r * (best_pos - pos_)
      + accel2 * r * (best_swarm_pos - pos_);

    pos_ = Vector2(pos_.x * speed_.x, pos_.y * speed_.y);
  }
}
