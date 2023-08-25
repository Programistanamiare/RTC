#pragma once

#include <Arduino.h>
#include "time_utility.hpp"

/**
  * The object is used for possible artificial extension of the duration of individual program fragments.
  * In addition, there is a counter of calls to the function responsible for stopping time.
*/
class RTC
{
public:
  /**
    * RTC class constructor.
    * @param delay_function pointer to the function that will be used to stop the program. Default is "delay".
   */
  RTC(DelayFunctionPtr delay_function = delay);

  /**
    * A member function that stops the program for the time given as an argument, from which the time since the last call of this function is subtracted.
    * If the time given as an argument is less than the elapsed time since the last call, the function will do nothing.
    * In addition, each use of this function increases the int. counter of its calls, which can be read using the "getCounter()" member function.
    * @param time implied time since the last call.
    * @return difference between the set time and the actual time since the previous call to this function.
   */
  int64_t wait(const uint64_t& time, const bool& incrase_timer = true);

  /**
    * A member function that returns the time since the last call to the wait() member function.
   */
  uint64_t getTime() const;

  /**
    * Member function returning ext. count of calls to the "wait()" member function.
   */
  const uint32_t& getCounter() const;

  /**
    * Component function resetting the internal value. count of "wait()" calls.
   */
  void resetCounter();

private:
  uint64_t timer;
  TimerFunctionPtr time_f_ptr;
  DelayFunctionPtr delay_f_ptr;
  uint32_t counter;
};