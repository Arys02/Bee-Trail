#include "pso.hh"

namespace beetrail
{

  Pso::Pso(int nb_particles)
    : nb_particles_(nb_particles)

  {
      topology_ = star;
      frames_per_second_ = 1;
      pretty_printer_on_ = true;
      time_count_on_ = false;
      accel1_ = 2;
      accel2_ = 2;
      weight_ = 1.1;

      this->init();

      /* Update best swarm position and best position for each particle */
  }

  void Pso::init()
  {
    //list_particle_ = std::vector<std::shared_ptr<Particle>>();

    srand(time(NULL));

    for (int i = 0 ; i < nb_particles_ ; i++)
    {
      int randomX = random() % 640;
      int randomY = random() % 480;

      Particle p(Vector2(randomX, randomY), Vector2(2, 2), this);

      list_particle_.push_back(std::make_shared<Particle>(Particle(
              Vector2(randomX, randomY), Vector2(2, 2), this)));
    }

    //TODO Will be changed when calling evaluation function on this random swarm
    /* Tmp solution to best_particle find */
    int r = random() % nb_particles_;
    best_pos_ = list_particle_[r]->best_pt_get();
    evaluate();
  }


  void Pso::evaluate()
  {
    /* Update best position for each particle and swarm */
    for (auto p : list_particle_)
    {
      /* Evaluate local best particle */
      Vector2 local_best = p->best_pt_get();
      Vector2 current_pos = p->pos_get();

      if (DistanceMiddle::compare_positions(current_pos) <
          DistanceMiddle::compare_positions(local_best))
      {
        p->best_pt_set(current_pos);
      }

      /* Update global best if current particule is better */
      local_best = p->best_pt_get();
      if (DistanceMiddle::compare_positions(local_best) <
          DistanceMiddle::compare_positions(best_pos_))
      {
        best_pos_ = local_best;
      }
    }

  }

  void Pso::update(cv::Mat frame)
  {
    /* Set best position for swarm and each particle */
    evaluate();
    for (auto p : list_particle_)
    {
      /*
      double r = (double) (rand() % 1000) / (double) 1000;
      p->speed_ = weight_ * p->speed_
      + accel1_ * r * (p->best_pt_ - p->pos_)
      + accel2_ * r * (best_pos_ - p->pos_);


       cap_speed(10, p);
       */


      p->update(best_pos_);
    }

    return;
  }

  /*
 void Pso::cap_speed(double max, std::shared_ptr<Particle> p)
  {
    double k;
    if (abs(p->speed_.x) > max)
    {
      k = abs(10 / p->speed_.x);
      p->speed_.x = p->speed_.x < 0 ? -max : max;
      p->speed_.y *= k;
    }

    if (abs(p->speed_.y) > max)
    {
      k = abs(10 / p->speed_.y);
      p->speed_.y = p->speed_.y < 0 ? -max : max;
      p->speed_.x *= k;
    }
  }


 *
 * void Particle::update(Vector2 best_swarm_pos)
  {

    // Constants 
    double r = (double) (rand() % 1000) / (double) 1000;

    // Compute new speed 
    speed_ = weight * speed_
      + accel1 * r * (best_pt_ - pos_)
      + accel2 * r * (best_swarm_pos - pos_);
    //std::cout << "speed = " << speed_ << std::endl;

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
      speed_.x = speed_.x < 0 ? -max : max;
      speed_.y *= k;
    }

    if (abs(speed_.y) > max)
    {
      k = abs(10 / speed_.y);
      speed_.y = speed_.y < 0 ? -max : max;
      speed_.x *= k;
    }
  }

 *
 *
 * */




  std::vector<std::shared_ptr<Particle>> Pso::list_particle_get()
  {
    return list_particle_;
  }

}
