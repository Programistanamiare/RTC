#include "RTC.hpp"

RTC::RTC(DelayFunctionPtr delay_function)
{
  this->time_f_ptr = delay_function == delay ? millis : micros;
  this->delay_f_ptr = delay_function;
  this->timer = 0;
  this->counter = 0U;
}

long RTC::wait(const uint64_t& time)
{
  uint64_t elapsed_time = this->getTime();
  if (time > elapsed_time) this->delay_f_ptr(time - elapsed_time);
  this->timer = this->time_f_ptr();
  this->counter++;
  return time - elapsed_time;
}

uint64_t RTC::getTime() const
{
  return this->time_f_ptr() - this->timer;
}

const uint32_t& RTC::getCounter() const
{
  return this->counter;
}

void RTC::resetCounter()
{
  this->counter = 0U;
}

