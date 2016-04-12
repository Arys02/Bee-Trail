#include <iostream>
#include "option-parser.hh"
#include "option-manager.hh"
//#include "video/VideoManager.hh"


int main(int argc, char **argv)
{
  beetrail::OptionParser parser(argc, argv);
  parser.parse_options();
  beetrail::OptionManager manager(parser);
  //manager.take_action();

/*  beetrail::VideoManager vm("");

  for(;;)
  {
    cv::Mat frame = vm.get_frame();
    cv::imshow(vm.name_window_get(), frame);
  }
*/
  return 0;
}
