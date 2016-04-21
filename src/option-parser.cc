#include "option-parser.hh"

namespace beetrail
{
  /* Parser initialisation */
  OptionParser::OptionParser(int p_argc, char **p_argv)
    : desc_(bpo::options_description("Options")),
    vm_(),
    argc_(p_argc),
    argv_(p_argv)
  {
    desc_.add_options()
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
       "Number of frames to analyse per second")

      ("number,n", bpo::value<int>()->default_value(50),
       "Number of Particle per swarm");

  }

  /* Parses options according to desc definition (constructor) */
  int OptionParser::parse_options()
  {
    try
    {
      bpo::store(bpo::parse_command_line(argc_, argv_, desc_), vm_);
      bpo::notify(vm_);
      /* Add actions to do to structure */
    }
    catch (std::exception& e)
    {
      print_help(std::cerr);
      exit(error_code::error);
    }
    return 0;
  }

  bool OptionParser::number_called()
  {
    return vm_.count("number");
  }

  bool OptionParser::help_called()
  {
    return vm_.count("help");
  }

  bool OptionParser::print_called()
  {
    return vm_.count("print");
  }

  bool OptionParser::time_called()
  {
    return vm_.count("time");
  }

  std::string OptionParser::topology()
  {
    return vm_["topology"].as<std::string>();
  }

  std::string OptionParser::video_input()
  {
    return vm_["video"].as<std::string>();
  }

  std::string OptionParser::object_input()
  {
    return vm_["object"].as<std::string>();
  }

  int OptionParser::frames_per_second()
  {
    return vm_["frames"].as<int>();
  }

  int OptionParser::number_get()
  {
    return vm_["number"].as<int>();
  }

  /* Display help in input stream */
  void OptionParser::print_help(std::ostream& output_stream)
  {
    output_stream << desc_;
  }
}
