#include "timer.hh"
#include <iostream>

/* Launch timer on construction */
Timer::Timer(double& s, std::ostream& p_stream, std::string msg)
  : seconds(s), stream(p_stream), message(msg), t0(steady_clock::now())
{
}

double Timer::get_time_elapsed()
{
  steady_clock::time_point t1 = steady_clock::now();
  double time_elapsed = (double)
    (std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() /
     1e9);

  return time_elapsed;
}

/* Calculate time taken since contruction */
Timer::~Timer()
{
  /*steady_clock::time_point t1 = steady_clock::now();
  seconds = (double)
    (std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() /
     1e9); */
  seconds = get_time_elapsed();

  /* Print message on stream */
  if (stream.good() && !stream.eof())
    stream << message << seconds << std::endl;
}
