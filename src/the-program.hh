#pragma once

#include "video/video-manager.hh"
#include "ffunctions/image-descriptor.hh"
#include "swarm/pso-settings.hh"
#include "swarm/pso.hh"

#include <memory>

namespace beetrail
{
  class TheProgram
  {
    private:
      std::shared_ptr<VideoManager> vm;
      std::shared_ptr<ImageDescriptor> id;
      std::shared_ptr<PsoSettings> pso_settings;

      std::shared_ptr<Pso> pso;

    public:
      TheProgram(VideoManager &vm, ImageDescriptor &id,
          PsoSettings &pso_settings);
      /* TODO Launch_pso should return a PsoResult class in the future*/
      void launch_pso(); // Init pso and loops on update
  };
}
