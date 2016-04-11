#pragma once

#include <boost/program_options.hpp>

namespace beetrail
{
  namespace bpo = boost::program_options;

  enum error_code
  {
    good = 0,
    error = 1
  };


  class OptionParser
  {
    public:
      /* Fields */
      bpo::options_description desc; /* Contains options description */
      bpo::variables_map vm; /* Map containing arguments values after parsing */
      int argc; /* Number of arguments */
      char **argv; /* Arguments */

      OptionParser(int p_argc, char **p_argv); /* Constructor */
      int parse_options(); /* Parse options and put results in the class fields */
      void action_help(int error_code); /* Displays help and exits */

      /* Parser values getters */
      int help_called();
      int print_called();
      int time_called();
      std::string topology();
      std::string video_input();
      std::string object_input();
      int frames_per_second();
  };
}
