#include <iostream>
#include <boost/program_options.hpp>
#include <string>
#include "timer.hh"
#include <fstream>

#include "swarm/pso.hh"
#include "video/video-manager.hh"


/*int main(int argc, char **argv)
{
  beetrail::OptionParser parser(argc, argv);
  parser.parse_options();
  beetrail::OptionManager manager(parser);
  return manager.action();
}*/




void exit_help(boost::program_options::options_description desc)
{
  std::cerr << desc;
  exit(1);
}

void print_help(std::ostream& output_stream,
    boost::program_options::options_description desc)
{
  output_stream << desc;
}


int main(int argc, char **argv)
{
  /* Parse aguments */
  namespace bpo = boost::program_options;
  bpo::options_description desc(bpo::options_description("Options"));
  bpo::variables_map vm;

  /* Add options */
  desc.add_options()
    ("help,h", "Display the help")
    ("print,p", "Pretty printing of particules")
    ("time,t", "Evaluation of the performances in term of time")

    ("topology,T", bpo::value<std::string>()->default_value("star"),
     "Changes the type of topology for the PSO algorithm")

    ("video,v", bpo::value<std::string>()->default_value(""),
     "File path to video to analyse")

    ("object,o", bpo::value<std::string>()->default_value(""),
     "File path to object to be detected")

    ("frames,f", bpo::value<int>()->default_value(1),
     "Number of frames to analyse per second")

    ("number,n", bpo::value<int>()->default_value(50),
     "Number of Particle per swarm")

    ("benchmark,b", bpo::value<std::string>()->default_value(""),
      "File name to save benchmark results in");

  /* Parse options */
  try
  {
    bpo::store(bpo::parse_command_line(argc, argv, desc), vm);
    bpo::notify(vm);
  }
  catch (std::exception& e)
  {
    exit_help(desc);
  }

  /* Create PSO with input image */
  //ImageDescriptor img(vm["object"].as<string>());
  //
  beetrail::Pso pso(100);

  /* Set attributes depending on parsed input */
  /* Topology type */
  //std::string topology(vm["topology"].as<std::string());
  //topology ? pso.set_topology(topology) : pso.set_topology("star");;

  /* Frames to analyze per second */
  //int frames_per_second = vm["frames"].as<int>();
  //if (frames_per_second < 0)
   // exit_help();
  //pso.set_frames_per_second(frames_per_second);

  /* Input video */
  std::string path_to_video = vm["video"].as<std::string>();

  beetrail::VideoManager video_manager = path_to_video == "" ?
    beetrail::VideoManager() :
    beetrail::VideoManager(path_to_video);

  /* Benchmark file log. Open output stream */
  std::string path_to_benchmark_file = vm["benchmark"].as<std::string>();
  std::ofstream benchmark_file;
  if (path_to_benchmark_file != "")
    benchmark_file.open(path_to_benchmark_file);
  else
    std::ofstream benchmark_file(0);


  /* Main loop */
  int stop = 0;
  {
    double z = 0;
    Timer global_timer(z, benchmark_file, "Global time: ");
    while (!stop)
    {
      double x = 0;
      Timer local_timer(x, benchmark_file, "Time for an iteration: ");
      cv::Mat frame = video_manager.frame_get();
      pso.update(frame);
      video_manager.pretty_print(pso, frame);
      video_manager.display_frame(frame, stop);
    }
  }

  return 0;
}
