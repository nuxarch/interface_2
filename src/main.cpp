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
  konfig_switch();
}

void loop()
{
  // baca pot
  int16_t pot = analogRead(PIN_POT1);
  uint8_t speed_val = map(pot, 0, 1023, 0,255);
  Serial.println("speed ="+String(map(speed_val,0,255,0,100)));
  // baca status switch 
  if (bacaSemuaSwitch() == 1){
    // maka putar cw
    setSpeed(speed_val);
  }else{
    motor_off();
  }  
}