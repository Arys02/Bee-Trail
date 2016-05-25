#include "pso.hh"

namespace beetrail
{

  Pso::Pso(/*std::shared_ptr<PsoSettings> pso_opt,
          */std::shared_ptr<ImageDescriptor> img_desc)
    : /*pso_opt_(pso_opt), */img_desc_(img_desc)
  {
    pso_opt_ = pso_opt;
    img_desc_ = img_desc;
    list_particle_ = std::vector<std::shared_ptr<Particle>>();

    int nb_particles = pso_opt->get_nb_particles();


    srand(time(NULL));

    for (int i = 0 ; i < nb_particles ; i++)
    {
      int randomX = random() % 640;
      int randomY = random() % 480;

      list_particle_.push_back(std::make_shared<Particle>(Particle(
              Vector2(randomX, randomY), Vector2(2, 2))));
    }

    //TODO Will be changed when calling evaluation function on this random swarm
    /* Tmp solution to best_particle find */
    int r = random() % nb_particles;
    best_pos_ = list_particle_[r]->best_pt_get();
    /* Update best swarm position and best position for each particle */
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
      p->update(best_pos_);

    return;
  }


  std::vector<std::shared_ptr<Particle>> Pso::list_particle_get()
  {
    return list_particle_;
  }

  /*std::shared_ptr<PsoSettings>
  Pso::pso_opt_get()
  {
    return pso_opt_;
  }*/

  std::shared_ptr<ImageDescriptor>
  Pso::img_desc_get()
  {
    return img_desc_;
  }
}
