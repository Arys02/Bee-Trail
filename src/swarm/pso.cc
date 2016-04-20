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
    /* Update best position for each particle */
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
      /*best_pos_ =
        DistanceMiddle::compare_positions(best_pos_, p->best_pt_get()) ?
        best_pos_:
        p->best_pt_get(); */

      if (DistanceMiddle::compare_positions(best_pos_, p->best_pt_get()))
      {
        std::cout << "Not changing global best" << std::endl;
      }
      else
      {
        std::cout << "Changing global velocity" << std::endl;
        //std::cout << "  Particle (" << p->best_pt_get().X
        best_pos_ = p->best_pt_get();
      }


      //std::cout << "Particule best : " << p->best_pt_get() << std::endl;
      //std::cout << "Global best    : " << best_pos_ << std::endl;
    }

  }

  void Pso::update(cv::Mat frame)
  {
    evaluate();
    std::cout << "Best point. X = " << best_pos_.x << ", Y = " << best_pos_.y;
    std::cout << std::endl;
    for (auto p : list_particle_)
      p->update(best_pos_);

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
