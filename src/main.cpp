#include <Arduino.h>

#define PIN_IN1 10
#define PIN_IN2 11
#define PIN_IN3 12
#define PIN_IN4 13

#define PIN1_HIGH   digitalWrite(PIN_IN1, HIGH)
#define PIN1_LOW   digitalWrite(PIN_IN1, LOW)
#define PIN2_HIGH   digitalWrite(PIN_IN2, HIGH)
#define PIN2_LOW   digitalWrite(PIN_IN2, LOW)
#define PIN3_HIGH   digitalWrite(PIN_IN3, HIGH)
#define PIN3_LOW   digitalWrite(PIN_IN3, LOW)
#define PIN4_HIGH   digitalWrite(PIN_IN4, HIGH)
#define PIN4_LOW   digitalWrite(PIN_IN4, LOW)

void setup(){
  Serial.begin(115200);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);

}
void loop(){
  // PIN 1234 = 0001, 0010, 0100, 1000
  for (int i = 0; i < 50; i++)
  {
    PIN1_LOW; PIN2_LOW; PIN3_LOW; PIN4_HIGH;delay(10);
    PIN1_LOW; PIN2_LOW; PIN3_HIGH; PIN4_LOW;delay(10);
    PIN1_LOW; PIN2_HIGH; PIN3_LOW; PIN4_LOW;delay(10);
    PIN1_HIGH; PIN2_LOW; PIN3_LOW; PIN4_LOW;delay(10);
  }
  // PIN 1234 = 1000, 0100, 0010, 0001

  PIN1_LOW; PIN2_LOW; PIN3_LOW; PIN4_LOW;delay(1000);
  for (int i = 0; i < 50; i++)
  {
    PIN1_HIGH; PIN2_LOW; PIN3_LOW; PIN4_LOW;delay(10);
    PIN1_LOW; PIN2_HIGH; PIN3_LOW; PIN4_LOW;delay(10);
    PIN1_LOW; PIN2_LOW; PIN3_HIGH; PIN4_LOW;delay(10);
    PIN1_LOW; PIN2_LOW; PIN3_LOW; PIN4_HIGH;delay(10);
  }
  PIN1_LOW; PIN2_LOW; PIN3_LOW; PIN4_LOW;delay(1000);

}