#include <iostream>
#include "option-parser.hh"

  int main(int argc, char **argv)
  {
    beetrail::OptionParser parser(argc, argv);
    parser.parse_options();

    return 0;
  }
