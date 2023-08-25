#include "RTC.hpp"

// pass the body of 'delay' or 'delayMicroseconds' as an argument. The 'delay' function is set by default.
RTC rtc(delayMicroseconds)

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // first part of program 
  Serial.println("First part of program loop.")
  rtc.wait(90, false); // wait 90 microseconds - execution time of the first part of the program (without incrementing the counter).
  // second part of program
  Serial.println("Second part of program loop.")
  rtc.wait(10, false); // wait 10 microseconds - execution time of the second part of the program (without incrementing the counter).
  // third part of program
  Serial.println("Third part of program loop.")
  rtc.wait(50, false); // wait 50 microseconds - exectuin time of the third part of the program (without incrementing the counter).
  if (rtc.getCounter() % 3 == 0) // every third loop of program...
  {
    // do something
    Serial.println("Every third loop of program.")
  }
  rtc.wait(50) // wait 50 microseconds - exectuin time of the third part of the program (with incrementing the counter).
}