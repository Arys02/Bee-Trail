#pragma once

#include <boost/program_options.hpp>
#include <iostream>

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
      OptionParser(int p_argc, char **p_argv); /* Constructor */
      int parse_options(); /* Parse options and put results in the class fields */
      void print_help(std::ostream& output_stream); /* Display help in stream */

      /* Parser values getters */
      bool help_called();
      bool print_called();
      bool time_called();
      std::string topology();
      std::string video_input();
      std::string object_input();
      int frames_per_second();

    private:
      /* Fields */
      bpo::options_description desc_; /* Contains options description */
      bpo::variables_map vm_; /* Map containing arguments values after parsing */
      int argc_; /* Number of arguments */
      char **argv_; /* Arguments */

  };
}
