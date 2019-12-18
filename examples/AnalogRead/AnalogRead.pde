#include <Oversampling.h>

Oversampling adc(10, 12, 2); //Adc Bytes 10 or 12, Oversampeling Bytes 11-18, 2 Is avaraging count.

void setup()
{
  Serial.begin(15200);
}

void loop()
{
  Serial.print(adc.read(0)); // 0 is adc pin
  delay(1000);
}

