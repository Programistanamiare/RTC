#pragma once

#include <Arduino.h>
#include "time_utility.hpp"

class RTC
{
  /**
   * Obiekt służy do ewentualnego sztucznego wydłużania czasu trwania poszczególnych fragmentów programu.
   * Dodatkowo dostępny jest licznik wywołań funkcji odpowiedzialnej za zatrzymywanie czasu.
  */
public:
  /**
   * Konstruktor klasy RTC. 
   * @param delay_function wskaźnik do funkcji, która będzie wykorzystywana do zatrzymywania programu. Domyślnie "delay".
  */
  RTC(DelayFunctionPtr delay_function = delay);

  /**
   * Funkcja składowa zatrzymująca program na czas podany jako argument, od którego odjęty jest czas od ostatniego wywołania tej funkcji.
   * Jeśli czas podany jako argument będzie mniejszy niż upłynął od ostatniego wywołania funkcja nie zrobi nic.
   * Dodatkowo każde użycie tej funkcji zwiększa wew. licznik jej wywołań, który można odczytać przy pomocy funkcji składowej "getCounter()".
   * @param time domniemany czas od poprzedniego wywołania.
   * @return różnica pomiędzy czasem zadanym, a faktycznym czasem od poprzedniego wywołania tej funkcji. 
  */
  long wait(const uint64_t& time);

  /**
   * Funkcja składowa zwracająca czas od poprzedniego wywołania funkcji składowej wait().
  */
  uint64_t getTime() const;

  /**
   * Funkcja składowa zwracająca wew. licznik wywołań funkcji składowej "wait()".
  */
  const uint32_t& getCounter() const;

  /**
   * Funkcja składowa resetująca wartość wew. licznika wywołań funkcji "wait()".
  */
  void resetCounter();

private:
  uint64_t timer;
  TimerFunctionPtr time_f_ptr;
  DelayFunctionPtr delay_f_ptr;
  uint32_t counter;
};