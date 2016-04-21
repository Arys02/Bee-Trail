#pragma once

#include "option-parser.hh"
#include "video-manager.hh"
#include "swarm/pso-settings.hh"
#include "ffunctions/image-descriptor.hh"
#include "the-program.hh"
#include <memory>

namespace beetrail
{
  class OptionManager
  {
    public:
      OptionManager(OptionParser &option_parser);
      int action();
      int launch_application();

      void action_help();

      PsoSettings action_pso(int frames);

    private:
      std::shared_ptr<OptionParser> option_parser_;

  };
}
