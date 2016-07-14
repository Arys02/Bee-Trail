namespace beetrail
{

  template <typename FF>
  Pso<FF>::Pso(int nb_particles, FF& fit_fun)
    : nb_particles_(nb_particles), fit_fun_(fit_fun)

  {
      frames_per_second_ = 1;
      pretty_printer_on_ = true;
      time_count_on_ = false;
      accel1_ = 2;
      accel2_ = 10;
      weight_ = 0.5;
  }


  template <typename FF>
  void Pso<FF>::init(int frame_width, int frame_height)
  {
    srand(time(NULL));

    for (int i = 0 ; i < nb_particles_ ; i++)
    {
      int randomX = random() % frame_width;
      int randomY = random() % frame_height;

     // Particle p(Vector2(randomX, randomY), Vector2(2, 2) , this);
     //list_particle_.push_back(std::make_shared<Particle>(p));


      pos_.push_back(Vector2(randomX, randomY));
      best_local_.push_back(Vector2(randomX, randomY));
      speed_.push_back(Vector2(2, 2));

    }

    /* Tmp solution to best_particle find */
    int r = random() % nb_particles_;
    //best_pos_ = list_particle_[r]->best_pt_get();

    best_pos_ = best_local_.at(r);
  }


  template <typename FF>
  void Pso<FF>::evaluate()
  {
    /* Update best position for each particle and swarm */
    auto body = [=] (size_t i)
    {
      //auto p = list_particle_.at(i);
           /* Evaluate local best particle */
      //Vector2 local_best = p->best_pt_get();
      //Vector2 current_pos = p->pos_get();
      auto current_pos = pos_.at(i);
      auto local_best = best_local_.at(i);


      if (fit_fun_(current_pos) <
          fit_fun_(local_best))
      {
        //p->best_pt_set(current_pos);
        best_local_.at(i) = current_pos;
      }

      /* Update global best if current particule is better */
      //local_best = p->best_pt_get();
      local_best = best_local_.at(i);
      if (fit_fun_(local_best) <
          fit_fun_(best_pos_))
      {
        best_pos_ = local_best;
      }

    };

    tbb::parallel_for(size_t(0),(size_t) list_particle_.size(), body);
  }


  template <typename FF>
  void Pso<FF>::update()
  {
    /* Set best position for swarm and each particle */
    evaluate();

    auto body = [=] (size_t i)
    {
      //list_particle_.at(i)->update(best_pos_);
      /* Constants */
      double r = (double) (rand() % 1000) / (double) 1000;

      /* Compute new speed */
      speed_.at(i) = weight_ * speed_.at(i)
        + accel1_ * r * (best_local_.at(i) - pos_.at(i))
        + accel2_ * r * (best_pos_ - pos_.at(i));


      cap_speed(i, 10);
      pos_.at(i) = pos_.at(i) + speed_.at(i);
    };

    tbb::parallel_for(size_t(0),(size_t) nb_particles_, body);

    //for (int i = 0; i < nb_particles_; i++)
      //list_particle_.at(i)->update(best_pos_);

    return;
  }
/*
  template <typename FF>
  std::vector<std::shared_ptr<Particle>> Pso<FF>::list_particle_get()
  {
    return list_particle_;
  }
  */

  template <typename FF>
  std::vector<Vector2> Pso<FF>::list_particle_get()
  {
    return pos_;
  }


  template <typename FF>
 void Pso<FF>::cap_speed(int pos, double max)
  {
    double k;

    if (std::abs(speed_.at(pos).y) > max)
    {
      k = std::abs(max / speed_.at(pos).y);
      speed_.at(pos).y = speed_.at(pos).y > 0 ? max : - max;

      speed_.at(pos).x = k * speed_.at(pos).x;
    }

    if (std::abs(speed_.at(pos).x) > max)
    {
      k = abs(max / speed_.at(pos).x);
      speed_.at(pos).x = speed_.at(pos).x > 0 ? max : - max;

      speed_.at(pos).y = k * speed_.at(pos).y;
    }

  }


}
