#pragma once
#include <math.h>
#include "swarm/particle.hh"

namespace beetrail
{
  class DistanceMiddle
  {
    public:
      static int compare_particles(std::shared_ptr<Particle> p1,
          std::shared_ptr<Particle> pt2);
      /* Returns true if p1 is better than p2 */
      static int compare_positions(Vector2 p1, Vector2 p2);
  };
}

