#include "pso-settings.hh"

namespace beetrail
{
  int PsoSettings::max_frames_per_second = 10;

  PsoSettings::PsoSettings(enum topology p_topology, int p_frames,
      int pprinter_on, int time_count_on)
  {
    topology = p_topology;
    frames_per_second = p_frames;
    pretty_printer_on = pprinter_on ? 1 : 0;
    time_count_on = time_count_on ? 1 : 0; /*Useless, but to have cuter values in debugger */
  }
}
