#include "option-manager.hh"

namespace beetrail
{
  OptionManager::OptionManager(OptionParser &option_parser)
  {
    option_parser_ = std::make_shared<OptionParser>(option_parser);
  }
}
