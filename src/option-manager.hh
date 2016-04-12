#pragma once

#include "option-parser.hh"
#include <memory>

namespace beetrail
{
  class OptionManager
  {
    public:
      OptionManager(OptionParser &option_parser);
      int action();
      int launch_application();

    private:
      std::shared_ptr<OptionParser> option_parser_;
  };
}
