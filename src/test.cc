#include <iostream>
#include <boost/program_options.hpp>
#include <string>

//#include "option-parser.hh"
//#include "option-manager.hh"

#include "swarm/pso.hh"
#include "video/video-manager.hh"


/*int main(int argc, char **argv)
{
  beetrail::OptionParser parser(argc, argv);
  parser.parse_options();
  beetrail::OptionManager manager(parser);
  return manager.action();
}*/






int main(int argc, char **argv)
{
  beetrail::DistanceMiddle dst_mid();
  beetrail::Pso<DistanceMiddle> pso(100, dst_mid);
 return 0;
}
