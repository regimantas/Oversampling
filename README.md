# Arduino Oversampling And Decimation Library

Arduino oversampling, decimation and averaging library.
Using oversampling and decimation will only lower the ADCs quantization error, it does not
compensate for the ADCs integral non-linearity. 

```c
Oversampling adc(Adc, Oversampling, Averaging);

unsigned long adc_value = adc.read(Pin); // Oversampling and decimation
```

Where:

- `Adc` is the resolution of the ADC of the microcontroller; can be 10 or 12,
- `Oversampling` is the number of bits obtained through the oversampling process; can be 11 to 24,
- `Averaging` is the number of consecutive oversampled readings performed inside `adc.read()` before returning the averaged value.
- `Pin` is the ADC pin number (e.g., `analogRead(Pin)`).

Example Sketch:

```c
#include <Oversampling.h>

Oversampling adc(10, 16, 2);
/* 10 = resolution of the ADC of the microcontroller (e.g., for the ATTINY88, the ADC resolution is 10 bits)
 * 16 = n of bits obtained through the oversampling process (16-10 = 4 additional bits)
 *  2 = number of consecutive oversampled readings performed inside adc.read() before returning the averaged value.
 */

void setup()
{
  Serial.begin(19200);
}

void loop()
{
  Serial.print( (int) adc.read(0) ); // 0 is adc pin
  delay(1000);
}
```

The maximum value returned by `adc.read()` is `((2^Adc)-1) * (2^(Oversampling-Adc))`, where `Adc` is the number of bits of the ADC and `Oversampling` is the number of bits obtained through the oversampling process. (The minimum value is 0.)

Example of maximum value for the ATTINY88 10-bit ADC with 16-bit oversampling: `((2^10)-1) * (2^(16-10)) = 1023 * 64 = 65472`.

References:

- http://ww1.microchip.com/downloads/en/AppNotes/doc8003.pdf
- http://ww1.microchip.com/downloads/en/AppNotes/AN2572-ADC-Oversampling-with-tinyAVR-0-and1series-and-megaAVR-0series-00002572B.pdf
- https://www.ti.com/lit/an/slyt423a/slyt423a.pdf
- https://www.ti.com.cn/cn/lit/an/snoa232/snoa232.pdf
