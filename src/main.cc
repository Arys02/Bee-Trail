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




//private void exit_help(boost::program_options::options_description desc)
//{
//  std::err << desc;
//  exit(1);
//}
//
//int main(int argc, char **argv)
//{
//  /* Parse aguments */
//  namespace bpo = boost::program_options;
//  bpo::options_description desc(bpo::options_description("Options"));
//  bpo::variables_map vm;
//
//  /* Add options */
//  desc.add_options()
//    ("help,h", "Display the help")
//    ("print,p", "Pretty printing of particules")
//    ("time,t", "Evaluation of the performances in term of time")
//
//    ("topology,T", bpo::value<std::string>()->default_value("star"),
//     "Changes the type of topology for the PSO algorithm")
//
//    ("video,v", bpo::value<std::string>()->default_value(""),
//     "File path to video to analyse")
//
//    ("object,o", bpo::value<std::string>()->default_value(""),
//     "File path to object to be detected")
//
//    ("frames,f", bpo::value<int>()->default_value(1),
//     "Number of frames to analyse per second")
//
//    ("number,n", bpo::value<int>()->default_value(50),
//     "Number of Particle per swarm");
//
//  /* Parse options */
//  try
//  {
//    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
//    bpo::notify(vm);
//  }
//  catch (std::exception& e)
//  {
//    exit_help();
//  }
//
//  /* Create PSO */
//  Pso pso;
//
//  /* Set attributes depending on parsed input */
//  /* Topology type */
//  std::string topology(vm["topology"].as<std::string());
//  topology ? pso.set_topology(topology) : pso.set_topology("star");;
//
//  /* Frames to analyze per second */
//  int frames_per_second = vm["frames"].as<int>();
//  if (frames_per_second < 0)
//    exit_help();
//  pso.set_frames_per_second(frames_per_second);
//
//  /* Input video */
//  std::string path_to_video = vm["video"].as<string>();
//  VideoManager video_manager = path_to_video == "" ?
//    VideoManager() :
//    VideoManager(path_to_video);
//
//
//
//  pso.launch_pso();
//}
