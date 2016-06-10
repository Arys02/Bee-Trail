//#include "pso.hh"

namespace beetrail
{

  template <typename FF>
  Pso<FF>::Pso(int nb_particles, FF& fit_fun)
    : nb_particles_(nb_particles), fit_fun_(fit_fun)

  {
      topology_ = star;
      frames_per_second_ = 1;
      pretty_printer_on_ = true;
      time_count_on_ = false;
      accel1_ = 2;
      accel2_ = 2;
      weight_ = 1.1;
  }


  template <typename FF>
  void Pso<FF>::init(int frame_width, int frame_height)
  {
    srand(time(NULL));

    for (int i = 0 ; i < nb_particles_ ; i++)
    {
      int randomX = random() % frame_width;
      int randomY = random() % frame_height;

      // TODO Set random acceleration?
      Particle p(Vector2(randomX, randomY), Vector2(2, 2) , this);

      list_particle_.push_back(std::make_shared<Particle>(p));
    }

    //TODO Will be changed when calling evaluation function on this random swarm
    /* Tmp solution to best_particle find */
    int r = random() % nb_particles_;
    best_pos_ = list_particle_[r]->best_pt_get();
    //evaluate();
  }


  template <typename FF>
  void Pso<FF>::evaluate()
  {
    /* Update best position for each particle and swarm */
    for (auto p : list_particle_)
    {
      /* Evaluate local best particle */
      Vector2 local_best = p->best_pt_get();
      Vector2 current_pos = p->pos_get();

      if (fit_fun_(current_pos) <
          fit_fun_(local_best))
      {
        p->best_pt_set(current_pos);
      }

      /* Update global best if current particule is better */
      local_best = p->best_pt_get();
      if (fit_fun_(local_best) <
          fit_fun_(best_pos_))
      {
        best_pos_ = local_best;
      }
    }
  }


  template <typename FF>
  void Pso<FF>::update()
  {
    /* Set best position for swarm and each particle */
    evaluate();
    for (auto p : list_particle_)
    {
      p->update(best_pos_);
    }

    return;
  }

  template <typename FF>
  std::vector<std::shared_ptr<Particle>> Pso<FF>::list_particle_get()
  {
    return list_particle_;
  }

}
