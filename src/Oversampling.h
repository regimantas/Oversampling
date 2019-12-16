/*
  Morse.h - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#ifndef Oversampling_h
#define Oversampling_h

#include "Arduino.h"

class Oversampling
{
  public:
    Oversampling(int adcbytes, int samplebytes, int Averaging);
    int read(int pin);
  private:
    int _samplebytes;
    int _adcbytes;
    int _Averaging;
};

#endif

