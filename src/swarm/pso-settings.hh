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

    public:
      static int max_frames_per_second;
      PsoSettings(enum topology p_topology, int p_frames, int pprinter_on,
          int time_count_on);
  };
}
