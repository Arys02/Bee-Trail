#pragma once

#include "option-parser.hh"
#include <memory>

namespace beetrail
{
  class OptionManager
  {
    public:
      OptionManager(OptionParser &option_parser);

    private:
      std::shared_ptr<OptionParser> option_parser_;
  };
}
