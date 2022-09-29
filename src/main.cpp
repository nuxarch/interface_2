#include <Arduino.h>
#include "LiquidCrystal_I2C.h"
#include "PinChangeInterrupt.h"
#include "led.h"
#include "switch.h"
#include "potensio.h"
#include "motorDC.h"

void setup()
{
  Serial.begin(115200);
  motorDC_init();
  
}

void loop()
{
  putarCW();
  delay(1000);
  motor_off();
  delay(1000);
  putarCCW();
  delay(1000);


}