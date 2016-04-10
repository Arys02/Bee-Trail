#pragma once

#include <boost/program_options.hpp>

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
    void action_help(int error_code); /* Displays help and exits */
    int parse_options(); /* Parse options and put results in the class fields */
};
