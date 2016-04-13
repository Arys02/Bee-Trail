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

  beetrail::VideoManager vm;
  cv::Mat edge;

  for(int i = 0;;i++)
  {
    //std::cout << "lol \n";
    cv::Mat frame;
    vm.capture_get() >> frame;
    //cv::cvtColor(frame, edge, cv::COLOR_BGR2GRAY);
    //if (i % 1 == 0) {
    vm.draw_square(5, 0, 0, frame);
    cv::imshow("Bee-trail", frame);
    //}

    if (cv::waitKey(30) >= 0)
      break;
  }
}
