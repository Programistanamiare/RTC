#pragma once

/**
   * Typ wskaźnikowy przyjmujący funkcję, która nie pobiera argumentu i zwraca typ "unsigned long".
   * Przygotowany z myślą o pobieraniu wskaźnika do funkcji "millis" bądź "micros".
  */
  typedef unsigned long (*TimerFunctionPtr)();

/**
   * Typ wskaźnikowy przujmujący funkcję, która pobiera typ "unsigned long" i zwraca typ "void".
   * Przygotowany z myślą o przechowywaniu wskaźnika do funkcji "delay" lub "delayMicroseconds".
  */
  typedef void (*DelayFunctionPtr)(unsigned long);