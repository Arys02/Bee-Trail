#pragma once
#include <math.h>
#include "swarm/particle.hh"

namespace beetrail
{
  class DistanceMiddle
  {
    public:
      /* The closest to 0, the closest to the middle */
      static double compare_positions(Vector2 p);

      double operator()(Vector2 p);
  };

}

