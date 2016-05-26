#include <iostream>
#include <boost/program_options.hpp>
#include <string>

//#include "option-parser.hh"
//#include "option-manager.hh"

#include "swarm/pso.hh"
#include "video/video-manager.hh"
#include "ffunctions/distance-middle.hh"


/*int main(int argc, char **argv)
{
  beetrail::OptionParser parser(argc, argv);
  parser.parse_options();
  beetrail::OptionManager manager(parser);
  return manager.action();
}*/






int main(int argc, char **argv)
{
  beetrail::DistanceMiddle dst_mid;
  beetrail::Pso<beetrail::DistanceMiddle> pso(100, dst_mid);
  /* Main loop */
  //int stop = 0;
  /*
  while (!stop)
  {
    cv::Mat frame = video_manager.frame_get();
    pso.update(frame);
    //video_manager.pretty_print(pso, frame);
    video_manager.display_frame(frame, stop);
  }
  */

  return 0;
}
