# Arduino RTC v1.0.0

The library is used to simple control the part (or whole loop) of program written in the **Arduino framework** using **delays** functions.

## Instalation

To get this library you can clone it from repo:
```
  git clone "http://github.com/Programistanamiare/RTC.git"
```
with included examples or take only header and interface files from <a href="http://github.com/Programistanamiare/RTC/tree/master/src">**here**</a>.

## Example

```
  #include "RTC.hpp"

  // pass the body of 'delay' or 'delayMicroseconds' as an argument. The 'delay' function is set by default.
  RTC rtc(delay)

  void setup()
  {
    Serial.begin(9600);
  }

  void loop()
  {
    rtc.wait(1000) // a member function that stops the program running for exactly one second.
    Serial.println("Called every exactly one second.") 
    if (rtc.getCounter() == 5) { // a member function that get number of calls 'rtc.wait' function.
      Serial.println("Called every exacly five seconds.");
      rtc.resetCounter(); // reset internal counter.
    }
  }

```

## Documentation

Constructor get reference to delay function like **delay** or **delayMicroseconds**.
@param **delay_fun_ptr** pointer type accepting a function that takes type "unsigned long" and returns type "void". Prepared to store a pointer to the "delay" or "delayMicroseconds" function.
```
  RTC::RTC(DelayFunctionPtr delay_fun_ptr) 
``` 

A member function that stops the program for the time specified as an argument, subtracted from the time since the last call to this function.
@param **time** implied time since the last call.
@param **incrase_counter** if <i>true</i> incrase internal counter of calls this function. <i>True</i> is set by default.
@return the difference between the set time and the actual time since the previous call to this function.
```
  int64_t RTC::wait(const uint64_t& time, const bool& incrase_counter) 
``` 

A member function that returns the time since the last call to the wait() member function.
```
  uint64_t RTC::getTime() const
```

A member function that return internal counter of 'wait()' member function calls.
```
  const uint32_t& RTC::getCounter() const
```

A member function that reset internal counter.
```
  void RTC::resetCounter()
```

  