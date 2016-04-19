#include "the-program.hh"

namespace beetrail
{
  TheProgram::TheProgram(VideoManager &p_vm, ImageDescriptor &p_id,
      PsoSettings &p_pso_settings)
  {
    vm = std::make_shared<VideoManager>(p_vm);
    id = std::make_shared<ImageDescriptor>(p_id);
    pso_settings = std::make_shared<PsoSettings>(p_pso_settings);
    pso = nullptr;
  }

  void TheProgram::launch_pso()
  {
    pso = std::make_shared<Pso>(pso_settings, id); //pso.init()
    for (;;)
    {
      cv::Mat frame = vm->frame_get();

      //vm->capture_get() >> frame;
      pso->update(frame); // particules update
      vm->pretty_print(pso, frame);
      cv::imshow("Bee-trail", frame);

      if (cv::waitKey(30) >= 0)
        break;
    }

    return;
  }
}
