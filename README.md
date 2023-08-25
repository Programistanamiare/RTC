# Arduino RTC v1.0.0

The library is used to simple control the part (or whole loop) of program written in the **Arduino framework** using **delays** functions.

## Instalation

To get this library you can clone it from repo:

```
  git clone "http://github.com/Programistanamiare/RTC.git"
```

with included examples or take only header and interface files from <a href="http://github.com/Programistanamiare/RTC/tree/master/src">**here**</a>.

## Examples

<details>
<summary>Click <b>here</b> to see few examples how to use library.</summary>

### Same time loop

```cpp

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

### Same interval between parts of program

```cpp

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

```

</details>

## Documentation

Constructor get reference to delay function like **delay** or **delayMicroseconds**.<br>
@param **delay_fun_ptr** pointer type accepting a function that takes type "unsigned long" and returns type "void". Prepared to store a pointer to the "delay" or "delayMicroseconds" function.

```cpp
  RTC::RTC(DelayFunctionPtr delay_fun_ptr) 
```

A member function that stops the program for the time specified as an argument, subtracted from the time since the last call to this function.<br>
@param **time** implied time since the last call.<br>
@param **incrase_counter** if <i>true</i> incrase internal counter of calls this function. <i>True</i> is set by default.<br>
@return the difference between the set time and the actual time since the previous call to this function.

```cpp
  int64_t RTC::wait(const uint64_t& time, const bool& incrase_counter) 
```

A member function that returns the time since the last call to the wait() member function.

```cpp
  uint64_t RTC::getTime() const
```

A member function that return internal counter of 'wait()' member function calls.

```cpp
  const uint32_t& RTC::getCounter() const
```

A member function that reset internal counter.

```cpp
  void RTC::resetCounter()
```  
