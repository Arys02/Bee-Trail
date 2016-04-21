#pragma once

namespace beetrail
{
  enum topology
  {
    star = 0,
    ring = 1
  };


//TODO Add getters
  class PsoSettings
  {
    private:
      enum topology topology;
      int frames_per_second;
      int pretty_printer_on;
      int time_count_on;
      static double constexpr acceleration1 = 2;
      static double constexpr acceleration2 = 2;
      static double constexpr weight = 1.1;
      static int constexpr nb_particles = 5000;

    public:
      static int max_frames_per_second;
      PsoSettings(enum topology p_topology, int p_frames, int pprinter_on,
          int time_count_on);

      static double get_acceleration1();
      static double get_acceleration2();
      static double get_weight();
      static int get_nb_particles();
  };
}
