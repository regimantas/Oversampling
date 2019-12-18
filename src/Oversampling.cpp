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

int Oversampling::read(int pin)
{
  int SampleCount = _samplebytes - _adcbytes;
  SampleCount = constrain(SampleCount, 1, 8);
  int OversampleCount;// = pow(SampleCount, 4);
  int DecimationCount;// = pow(SampleCount, 2);
  if (SampleCount==1){
    OversampleCount = 4;
    DecimationCount = 2;
  }
  if (SampleCount==2){
    OversampleCount = 16;
    DecimationCount = 4;
  }
  if (SampleCount==3){
    OversampleCount = 64;
    DecimationCount = 8;
  }
  if (SampleCount==4){
    OversampleCount = 256;
    DecimationCount = 16;
  }
  if (SampleCount==5){
    OversampleCount = 1024;
    DecimationCount = 32;
  }
  if (SampleCount==6){
    OversampleCount = 4096;
    DecimationCount = 64;
  }
  if (SampleCount==7){
    OversampleCount = 16384;
    DecimationCount = 128;
  }
  if (SampleCount==8){
    OversampleCount = 65536;
    DecimationCount = 256;
  }
  
  // Can Lead To Overflow
  unsigned long TotalADC = 0;
  for (int i=0; i<_Averaging; i++){
    for (int i=0; i<OversampleCount; i++){
      TotalADC = TotalADC + analogRead(pin);
    }
  }
  TotalADC = TotalADC / DecimationCount / _Averaging;

  //_Averaging
  return TotalADC;
}