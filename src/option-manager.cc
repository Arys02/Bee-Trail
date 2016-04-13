#include "option-manager.hh"

namespace beetrail
{
  OptionManager::OptionManager(OptionParser &option_parser)
  {
    option_parser_ = std::make_shared<OptionParser>(option_parser);
  }

  int OptionManager::action()
  {
    /* Help invoked? */
    if (option_parser_->help_called())
      option_parser_->print_help(std::cerr);

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
        option_parser_->time_called());

    /* Video path */
    VideoManager vm = option_parser_->video_input() == "" ?
      VideoManager() : VideoManager(option_parser_->video_input());

    /* Image to recognize path */
    ImageDescriptor img = ImageDescriptor(option_parser_->object_input());

    /* Main entry point */
    TheProgram the_program(vm, img, pso_settings);
    the_program.launch_pso();
    /* Or Output results = the_program.get_results(); */

    //Toast
  for(int i = 0 ;; i++)
  {
    cv::Mat frame;
    vm.capture_get() >> frame;
    vm.draw_square(5, 0, 0, frame);
    cv::imshow("Bee-trail", frame);

    if (cv::waitKey(30) >= 0)
      break;
  }

    return error_code::good;
  }

}
