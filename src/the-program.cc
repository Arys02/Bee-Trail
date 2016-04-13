#include "the-program.hh"

namespace beetrail
{
  TheProgram::TheProgram(VideoManager &p_vm, ImageDescriptor &p_id,
      PsoSettings &p_pso_settings)
  {
    vm = std::make_shared<VideoManager>(p_vm);
    id = std::make_shared<ImageDescriptor>(p_id);
    pso_settings = std::make_shared<PsoSettings>(p_pso_settings);
  }

  void TheProgram::launch_pso()
  {
    return;
  }
}
