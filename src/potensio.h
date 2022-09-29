#ifndef __POTENSIO_H__
#define __POTENSIO_H__

#define PIN_POT1    A0
#define PIN_POT2    A1
#define PIN_POT3    A2
#define PIN_POT4    A3
#define PIN_POT5    A4
#define PIN_POT6    A5

void readPotensio(){
    // konversi teg analog -> digital
  int16_t hasil_konversi = analogRead(PIN_POT1);
  double position = mapFraction(hasil_konversi, 0, 1023, 0, 5);
  Serial.println("hasil konversi ADC :["+String(hasil_konversi) +"] ==> pos["+String(position)+"v]");
//   layar.setCursor(11,0);
//   layar.print(hasil_konversi);
//   layar.setCursor(11,1);
//   layar.print(position);
}
#endif