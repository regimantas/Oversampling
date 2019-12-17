/*
  Oversampling - Arduino Oversampling And Decimation Library.
  Created by Regimantas Baublys, 2019.
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
  SampleCount = constrain(SampleCount, 1, 14);
  int OversampleCount = pow(SampleCount, 4); // int OversampleCount = SampleCount ** 4;
  int DecimationCount = pow(SampleCount, 2); // int DecimationCount = SampleCount ** 2;
  if (SampleCount==3){
    OversampleCount = 64;
    DecimationCount = 8;
  }
  
  // Can Lead To Overflow
  unsigned long TotalADC = 0;
  for (int i=0; i<_Averaging; i++){
    for (int i=0; i<OversampleCount; i++){
      TotalADC = TotalADC + analogRead(pin);
    }
  }
  TotalADC = TotalADC / DecimationCount / _Averaging;

  avarage = avarage / _Averaging;
  //_Averaging
  return avarage;
}