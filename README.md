# Arduino Oversampling And Decimation Library

Arduino oversampling, decimation and averaging library.
Using oversampling and decimation will only lower the ADCs quantization error, it does not
compensate for the ADCs integral non-linearity. 

Exaple Sketch:

    #include <Oversampling.h>
    
    Oversampling adc(10, 12, 2); //Adc Bytes 10 or 12, Oversampeling Bytes 11-24, 2 Is avaraging count.
    
    void setup()
    {
      Serial.begin(15200);
    }
    
    void loop()
    {
      Serial.print(adc.read(0)); // 0 is adc pin
      delay(1000);
    }
