#include "option-manager.hh"

namespace beetrail
{
  OptionManager::OptionManager(OptionParser &option_parser)
  {
    option_parser_ = std::make_shared<OptionParser>(option_parser);
  }

  void OptionManager::action_help()
  {
    /* Help invoked? */
    if (option_parser_->help_called())
      option_parser_->print_help(std::cerr);
  }


  int OptionManager::action()
  {
    action_help();

    /* Pso settings */
    enum topology topology;
    if (option_parser_->topology() == "star")
      topology = star;
    else if (option_parser_->topology() == "ring")
      topology = ring;
    else
      return error_code::error;

    int frames = option_parser_->frames_per_second();
    if (frames < 0 || frames > PsoSettings::max_frames_per_second)
      return error_code::error;

    PsoSettings pso_settings(topology, frames, option_parser_->print_called(),
        option_parser_->time_called(), option_parser_->number_get());

    /* Video path */
    VideoManager vm = option_parser_->video_input() == "" ?
      VideoManager() : VideoManager(option_parser_->video_input());

    /* Image to recognize path */
    ImageDescriptor img = ImageDescriptor(option_parser_->object_input());

    /* Main entry point */
    TheProgram the_program(vm, img, pso_settings);
    the_program.launch_pso();
    /* Output results = the_program.get_results(); */

    return error_code::good;
  }

}
