#pragma once

#include <chrono>
#include <iostream>

using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;


/*!
  * \class Timer
  * \brief Class timing time elapsed from object initialization to destruction
  *
  * Start a timer at initialization and calculate elapsed time at destruction.
  * Put result in double reference passed as parameter. Print parameter message
  * in stream when done.
  */
class Timer
{
  public:
    /*!
     * \brief Constructor
     *
     * Start a timer
     * \param s : reference to double. Will contain elapsed time after
     * destruction
     * \param stream : stream in which end message will be printed
     * \param msg : message to print along with the elapsed time
     *
     */
    Timer(double& s, std::ostream& stream, std::string msg);

    /*!
     * \brief Destructor
     *
     * End timer. Put time elapsed in s. Also print message with elapsed time.
     *
     */
    ~Timer();

    double get_time_elapsed();

  private:
    double&                   seconds;
    std::ostream&             stream;
    std::string               message;
    steady_clock::time_point  t0;
};
