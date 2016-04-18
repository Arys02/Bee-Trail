#include "helpers/point.hh"

namespace beetrail
{
  Point::Point(double p_x, double p_y)
  {
    x = p_x;
    y = p_y;
  }

  Point::setPosition(Point p)
  {
    x = p.x;
    y = p.y;
  }

  Point::setX(double p_x)
  {
    x = p_x;
  }
    
  Point::setY(double p_y)
  {
    y = p_y;
  };
}
