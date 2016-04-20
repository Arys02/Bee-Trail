#include "pso.hh"

namespace beetrail
{

  Pso::Pso(std::shared_ptr<PsoSettings> pso_opt,
          std::shared_ptr<ImageDescriptor> img_desc)
    : pso_opt_(pso_opt), img_desc_(img_desc)
  {
    pso_opt_ = pso_opt;
    img_desc_ = img_desc;
    list_particle_ = std::vector<std::shared_ptr<Particle>>();

    int nb_particles = PsoSettings::get_nb_particles();


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
    for (auto p : list_particle_)
    {
      /* Evaluate local best particle */
      Vector2 old_local_best = p->best_pt_get();
      Vector2 current_pos = p->pos_get();

      p->best_pt_set(DistanceMiddle::compare_positions(
            old_local_best, current_pos) ?
          old_local_best :
          current_pos);

      /* Evaluate global best particle */
      best_pos_ =
        DistanceMiddle::compare_positions(best_pos_, p->best_pt_get()) ?
        best_pos_:
        p->best_pt_get();

    }
  }

  void Pso::update(cv::Mat frame)
  {
    int i = 0;
    evaluate();
    for (auto p : list_particle_)
    {
      i++;
      p->update(best_pos_);
    }

    //TODO Call evaluation function on swarm

    return;
  }


  std::vector<std::shared_ptr<Particle>> Pso::list_particle_get()
  {
    return list_particle_;
  }

  std::shared_ptr<PsoSettings>
  Pso::pso_opt_get()
  {
    return pso_opt_;
  }

  std::shared_ptr<ImageDescriptor>
  Pso::img_desc_get()
  {
    return img_desc_;
  }
}
