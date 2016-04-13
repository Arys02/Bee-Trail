#include <iostream>
#include "option-parser.hh"
#include "option-manager.hh"
#include "video/video-manager.hh"


int main(int argc, char **argv)
{
  beetrail::OptionParser parser(argc, argv);
  parser.parse_options();
  beetrail::OptionManager manager(parser);
  return manager.action();
}
