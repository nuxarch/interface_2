#ifndef __MOTOR_DC__
#define __MOTOR_DC__

#define PIN_EN  12
#define PIN_IN1 10
#define PIN_IN2 11


void motorDC_init(){
  pinMode(PIN_EN, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
}
void putarCCW(){
 // set high pada PIN_EN
  digitalWrite(PIN_EN, HIGH);

  // CCW
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
}
void putarCW(){
 // set high pada PIN_EN
  digitalWrite(PIN_EN, HIGH);

  // CCW
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
}

void motor_off(){
  digitalWrite(PIN_EN, LOW);
}

#endif