#include "option-manager.hh"

namespace beetrail
{
  OptionManager::OptionManager(OptionParser &option_parser)
  {
    option_parser_ = std::make_shared<OptionParser>(option_parser);
  }

  int OptionManager::action()
  {
    if (option_parser_->help_called())
    {
      option_parser_->print_help(std::cerr);
    }

    if (option_parser_->topology() == "star")
      ;
      // Options topology = TOPOLOGY_STAR;
    else if (option_parser_->topology() == "ring")
      ;
      // Options topology = TOPOLOGY_RING;
    else
      return error_code::error;

    int frames = option_parser_->frames_per_second();
    if (frames >= 0 && frames <= 10) //TODO 10 to be MAX_FRAMES
      ;
      // Options nb_frames =  frames;
    else
      return error_code::error;

    //TODO
    // Options pretty_printer =  option_parser_->print_called()
    // Options time_count = option_parser_->time_called()

    //TODO Initialize VideoManager with input video and put it in Options.
    //VideoManager(option_parser_->video_input());

    //TODO Initialize ImageDescriptor with input image and put it in Options.
    //ImageDescriptor set object(option_parser_->object_input());

    return error_code::good;
  }

}
