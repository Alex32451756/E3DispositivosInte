// "OledTwi.h" rewritten using Wire.h, so its portable to ESP8266 , STM32 etc.
#include <Wire.h>

#define Adr 0x78  //(0x3C*2) 8 Bit Adress


void SetupOledI2C() {
  Wire.begin();
}

void  Start () {
  Wire.beginTransmission(Adr>>1); // uses 7 Bit Adr
}

void  Stop () {
  Wire.endTransmission();
}

  
void  Write (byte ab) {  // only data8
  Wire.write(ab);
}
