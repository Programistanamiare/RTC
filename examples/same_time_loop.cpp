#include "RTC.hpp"

RTC rtc(delay)

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rtc.wait(1000)
  Serial.println("Called every exactly one second.")
  if (rtc.getCounter() == 5) {
    Serial.println("Called every exacly five seconds.");
    rtc.resetCounter();
  }
}