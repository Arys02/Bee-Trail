#include "pso-settings.hh"

namespace beetrail
{
  int PsoSettings::max_frames_per_second = 10;

  PsoSettings::PsoSettings(enum topology p_topology, int p_frames,
      bool pprinter_on, bool time_count_on, int nb_particle)
    : topology_(p_topology), frames_per_second_(p_frames),
      pretty_printer_on_(pprinter_on), time_count_on_(time_count_on),
      nb_particles_(nb_particle)
  {
  }

}
