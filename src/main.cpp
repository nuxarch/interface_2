#include <Arduino.h>

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include "switch.h"
#include "PinChangeInterrupt.h"
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN 13
#define DATA_PIN 11
#define CS_PIN 10

// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
#define PIN_RESPONSIF 50
int counter = 0;
char buff[5];

void detect_sensor()
{
  delay(100);
  counter++;
}

void setup()
{
  Serial.begin(115200);
  konfig_switch();
  pinMode(PIN_RESPONSIF, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(PIN_RESPONSIF), detect_sensor, FALLING);
  P.begin();
}

void loop()
{
  itoa(counter, buff, 10);

  if (P.displayAnimate())
    P.displayText(buff, PA_CENTER, 50, 1000, PA_SCROLL_UP, PA_SCROLL_UP);
  P.setZoneEffect(0, true, PA_FLIP_LR);
  P.setZoneEffect(0, true, PA_FLIP_UD);

}