#pragma once

namespace beetrail
{
  /* Describes a point */
  public class Point
  {
    private:
      double x;
      double y;

    public:
      Point(double pX, double pY);
      setPosition(Point p);
      setX(double x);
      setY(double y);
  };
}
