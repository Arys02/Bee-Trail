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
  //    if (vm.count("help") && argc == 2) /* -h */
  //      help_exit();
  //    else if (argc == 5 && !vm["output"].defaulted()) /* two arguments */
  //    {
  //      if (vm.count("input")) /* -i -o */
  //      {
  //        check_input_file();
  //        return solve(vm["input"].as<std::string>().c_str(),
  //                         vm["output"].as<std::string>().c_str());
  //   }
  // else if (!vm["size"].defaulted()) /* -s -o*/
  // return genere(vm["size"].as<int>(),
  //             vm["output"].as<std::string>().c_str());
  //    }
  //  else if (argc == 3 && !vm.count("help")) /* -i or -o alone */
  //{
  //if (vm.count("input"))
  //      {
  //      check_input_file();
  //    return solve(vm["input"].as<std::string>().c_str(), nullptr);
  //}
  //      else if (!vm["output"].defaulted())
  //      return genere(3, vm["output"].as<std::string>().c_str()); // -o
  //  else if (!vm["size"].defaulted())
  //  return genere(vm["size"].as<int>(), nullptr);
  //    }
  //  else if (argc == 1) /* s = 3, -i nothing -o out */
  //  return genere(3, nullptr);

  //    throw std::bad_function_call();
  //  }
  //  catch (std::exception& e)
  //  {
  //  std::cerr << desc;
  //return error_code::bad_usage;
  //  }
  //}

  //int OptionParser::check_input_file()
  //{
/* Open file and put in in a stream */
/*  const char *input_file = vm["input"].as<std::string>().c_str();
    std::ifstream file_in;
    file_in.open(input_file);

    if (file_in.is_open() && file_in.good())
    {
    if (is_vex_file(file_in))
    return error_code::ok;

    exit(error_code::incorrect_file);
    }
    exit(error_code::file_not_found);
    }*/


/* Display help in standart output and exits with input error code */
void OptionParser::action_help(int error_code = error_code::good)
{
  std::cout << desc;
  exit(error_code);
}

}
