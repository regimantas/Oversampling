/*
  Oversampling - Arduino Oversampling And Decimation Library.
  Created by Regimantas Baublys, 2019.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Oversampling.h"

Oversampling::Oversampling(int adcbytes, int samplebytes, int Averaging)
{
  _samplebytes = constrain(samplebytes, 11, 18);
  _adcbytes = constrain(adcbytes, 10, 12);
  if (Averaging < 1){
    Averaging = 1;
  }
  _Averaging = Averaging;
}

unsigned long Oversampling::read(int pin)
{
  int DecimationCount = _samplebytes - _adcbytes;
  DecimationCount = constrain(DecimationCount, 1, 8);
  int OversampleCount = 1 << DecimationCount*2;// = pow(2, DecimationCount*2);
  
  // Can Lead To Overflow
  unsigned long TotalADC = 0;
  for (int i=0; i<_Averaging; i++){
    for (int i=0; i<OversampleCount; i++){
      TotalADC = TotalADC + analogRead(pin);
    }
  }
  TotalADC = (TotalADC >> DecimationCount) / _Averaging;

  //_Averaging
  return TotalADC;
}
