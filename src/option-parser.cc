#include "option-parser.hh"

namespace beetrail
{
  /* Parser initialisation */
  OptionParser::OptionParser(int p_argc, char **p_argv)
    : desc(bpo::options_description("Options")),
    vm(),
    argc(p_argc),
    argv(p_argv)
  {
    desc.add_options()
      ("help,h", "Display the help")
      ("print,p", "Pretty printing of particules")
      ("time,t", "Evaluation of the performances in term of time")
      ("topology,T", bpo::value<std::string>()->default_value("star"),
       "Changes the type of topology for the PSO algorithm")
      ("video,v", bpo::value<std::string>()->default_value(""),
       "File path to video to analyse")
      ("object,o", bpo::value<std::string>()->default_value(""),
       "File path to object to be detected")
      ("frames,f", bpo::value<int>()->default_value(1),
       "Number of frames to analyse per second");
  }

  /* Parses options according to desc definition (constructor) */
  int OptionParser::parse_options()
  {
    try
    {
      bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
      bpo::notify(vm);
      /* Add actions to do to structure */
    }
    catch (std::exception& e)
    {
      action_help(error_code::error);
    }
    return 0;
  }

  int OptionParser::help_called()
  {
    return vm.count("help");
  }

  int OptionParser::print_called()
  {
    return vm.count("print");
  }

  int OptionParser::time_called()
  {
    return vm.count("time");
  }

  std::string OptionParser::topology()
  {
    return vm["topology"].as<std::string>();
  }

  std::string OptionParser::video_input()
  {
    return vm["video"].as<std::string>();
  }

  std::string OptionParser::object_input()
  {
    return vm["object"].as<std::string>();
  }

  int OptionParser::frames_per_second()
  {
    return vm["frames"].as<int>();
  }

  /* Display help in standart output and exits with input error code */
  void OptionParser::action_help(int error_code = error_code::good)
  {
    std::cout << desc;
    exit(error_code);
  }

}
