#include <Arduino.h>
#include "LiquidCrystal_I2C.h"
#include "PinChangeInterrupt.h"
#include "led.h"
#include "switch.h"
#include "potensio.h"

#define PIN_RESPONSIF 50
LiquidCrystal_I2C layar(0x27, 20, 4);

#define ARAH_KIRI 1
#define ARAH_KANAN 2
int arah = ARAH_KIRI;

void detect_sensor()
{
  LED2_ON;
  arah = ARAH_KANAN;
}
char mychar = '>';
void lcd_shift(){
  if (arah == ARAH_KIRI)
    {
      for (int i = 0; i <= 3; i++)
      {
        for (int j = 0; j <= 19; j++)
        {
          layar.setCursor(j, i);
          layar.print(mychar);
          delay(100);
          layar.setCursor(j, i);
          layar.print(' ');
        }
      }
    }
    if (arah == ARAH_KANAN)
    {
      for (int i = 0; i <= 3; i++)
      {
        for (int j = 19; j > 0; j--)
        {
          layar.setCursor(j, i);
          layar.print('<');
          delay(100);
          layar.setCursor(j, i);
          layar.print(' ');
        }
      }
    }
}
void setup()
{
  Serial.begin(115200);
  konfig_led();
  konfig_switch();
  pinMode(PIN_RESPONSIF, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(PIN_RESPONSIF), detect_sensor, RISING);
  layar.init();
  layar.backlight();
  layar.setCursor(0,0);
            // 01234567890123456
  layar.print("ADC Sensor:");
  layar.setCursor(0,1);
            // 01234567890123456
  layar.print("Pos Sensor:");
  
}

void loop()
{
  readPotensio();
  delay(100);
}