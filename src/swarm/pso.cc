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




    for (int i = 0 ; i < nb_particles ; i++)
    {
      int randomX = random() % 800;
      int randomY = random() % 1200;

      list_particle_.push_back(std::make_shared<Particle>(Particle(
              Vector2(randomX, randomY), Vector2(2, 2), Vector2(1, 1))));
    }

    //TODO Will be changed when calling evaluation function on this random swarm
    /* Tmp solution to best_particle find */
    int r = random() % nb_particles;
    best_particle_ = list_particle_[r];
  }

  void Pso::update(cv::Mat frame)
  {
    int i = 0;
    for (std::shared_ptr<Particle> p : list_particle_)
    {
      i++;
      std::cout << "Particle " << i << ":" << std::endl;
      p->update(best_particle_);
      std::cout << std::endl;
    }

    //TODO Call evaluation function on swarm

    return;
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
