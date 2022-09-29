#include <Arduino.h>

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN 13
#define DATA_PIN 11
#define CS_PIN 10

// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup()
{
  Serial.begin(115200);
  P.begin();
}

void loop()
{
  if (P.displayAnimate())
    P.displayText(" => ", PA_CENTER, 200, 1000, PA_SCROLL_UP, PA_SCROLL_UP);
  P.setZoneEffect(0, true, PA_FLIP_LR);
  P.setZoneEffect(0, true, PA_FLIP_UD);
}