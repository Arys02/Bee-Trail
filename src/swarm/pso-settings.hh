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
      enum topology topology_;
      int frames_per_second_;
      int pretty_printer_on_;
      int time_count_on_;

      static double constexpr acceleration1_ = 2;
      static double constexpr acceleration2_ = 2;
      static double constexpr weight_ = 1.1;
      static int constexpr nb_particles_ = 5000;

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

#include "pso-settings.hxx"
