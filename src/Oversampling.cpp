/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Oversampling.h"

Oversampling::Oversampling(int adcbytes, int samplebytes, int Averaging)
{
  _samplebytes = constrain(samplebytes, 11, 24);
  _adcbytes = constrain(adcbytes, 10, 12);
  if (Averaging < 1){
    Averaging = 1;
  }
  _Averaging = Averaging;
}

int Oversampling::read(int pin)
{
  int SampleCount = _samplebytes - _adcbytes;
  SampleCount = constrain(SampleCount, 1, 14) ** 4;
  
  //unsigned long avarage = 0;
  unsigned long TotalADC = 0;
  for (int i=0; i<_Averaging; i++){
    for (int i=0; i<SampleCount; i++){
      TotalADC = TotalADC + analogRead(pin);
    }
  }
  TotalADC = TotalADC / 2 / _Averaging;

  avarage = avarage / _Averaging;
  //_Averaging
  return avarage;
}