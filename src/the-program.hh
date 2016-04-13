#pragma once

#include "video/video-manager.hh"
#include "ffunctions/image-descriptor.hh"
#include "swarm/pso-settings.hh"

#include <memory>

namespace beetrail
{
  class TheProgram
  {
    private:
      std::shared_ptr<VideoManager> vm;
      std::shared_ptr<ImageDescriptor> id;
      std::shared_ptr<PsoSettings> pso_settings;

    public:
      TheProgram(VideoManager &vm, ImageDescriptor &id,
          PsoSettings &pso_settings);
      void launch_pso();
  };
}
