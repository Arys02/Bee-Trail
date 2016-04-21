#pragma once

#include "pso-settings.hh"

namespace beetrail {

  inline
  double PsoSettings::get_weight()
  {
    return weight_;
  }

  inline
  double PsoSettings::get_acceleration1()
  {
    return acceleration1_;
  }

  inline
  double PsoSettings::get_acceleration2()
  {
    return acceleration2_;
  }

  inline
  int PsoSettings::get_nb_particles()
  {
    return nb_particles_;
  }


}
