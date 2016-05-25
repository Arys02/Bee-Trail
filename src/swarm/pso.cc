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
      // TODO change magic number for windows size
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

      p->update(best_pos_);
    }

    return;
  }

  std::vector<std::shared_ptr<Particle>> Pso::list_particle_get()
  {
    return list_particle_;
  }

}
