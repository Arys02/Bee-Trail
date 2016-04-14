#include "pso.hh"

namespace beetrail
{

  Pso::Pso()
  {

  }
  Pso::Pso(std::shared_ptr<PsoSettings> pso_opt,
          std::shared_ptr<ImageDescriptor> img_desc)
    : pso_opt_(pso_opt), img_desc_(img_desc)
  {
    //TODO init set of paricles
  }

  void Pso::update(cv::Mat frame)
  {
    //TODO
    return; //update function
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
