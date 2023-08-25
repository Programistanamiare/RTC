#pragma once

/**
    * A pointer type that accepts a function that takes no argument and returns an "unsigned long" type.
    * Prepared for fetching a pointer to the "millis" or "micros" function.
   */
  typedef unsigned long (*TimerFunctionPtr)();

/**
    * Pointer type accepting a function that takes type "unsigned long" and returns type "void".
    * Prepared to store a pointer to the "delay" or "delayMicroseconds" function.
   */
  typedef void (*DelayFunctionPtr)(unsigned long);