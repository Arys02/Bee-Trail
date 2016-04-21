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

    public:
      static int max_frames_per_second;
      PsoSettings(enum topology p_topology, int p_frames, bool pprinter_on,
          bool time_count_on, int nb_particle);

      static double get_acceleration1();
      static double get_acceleration2();
      static double get_weight();
      int get_nb_particles();

    private:
      enum topology topology_;
      int frames_per_second_;
      bool pretty_printer_on_;
      bool time_count_on_;


      static double constexpr acceleration1_ = 2;
      static double constexpr acceleration2_ = 2;
      static double constexpr weight_ = 1.1;
      int nb_particles_;

  };
}

#include "pso-settings.hxx"
