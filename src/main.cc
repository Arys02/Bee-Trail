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

  /*
  beetrail::VideoManager vm("~/Videos/small.mp4");
  cv::Mat edge;

  for(;;)
  {
    //std::cout << "lol \n";
    cv::Mat frame;
    vm.capture_get() >> frame;
    //cv::cvtColor(frame, edge, cv::COLOR_BGR2GRAY);
    cv::imshow("mdr", frame);
  }
  */
}
