#include "pso-settings.hh"

namespace beetrail
{
  int PsoSettings::max_frames_per_second = 10;

  PsoSettings::PsoSettings(enum topology p_topology, int p_frames,
      int pprinter_on, int time_count_on)
  {
    topology_ = p_topology;
    frames_per_second_ = p_frames;
    pretty_printer_on_ = pprinter_on ? 1 : 0;
    time_count_on_ = time_count_on ? 1 : 0; /*Useless, but to have cuter values in debugger */
  }

}
