/*
  Oversampling - Arduino Oversampling And Decimation Library.
  Created by Regimantas Baublys, 2019.
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

