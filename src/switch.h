#ifndef __SWITCH_H__
#define __SWITCH_H__


#define PIN_SWITCH1     22
#define PIN_SWITCH2     23
#define PIN_SWITCH3     24
#define PIN_SWITCH4     25
#define PIN_SWITCH5     26
#define PIN_SWITCH6     27
#define PIN_SWITCH7     28
#define PIN_SWITCH8     29

#define SWITCH1_AKTIF   digitalRead(PIN_SWITCH1) == LOW
#define SWITCH2_AKTIF   digitalRead(PIN_SWITCH2) == LOW
#define SWITCH3_AKTIF   digitalRead(PIN_SWITCH3) == LOW
#define SWITCH4_AKTIF   digitalRead(PIN_SWITCH4) == LOW
#define SWITCH5_AKTIF   digitalRead(PIN_SWITCH5) == LOW
#define SWITCH6_AKTIF   digitalRead(PIN_SWITCH6) == LOW
#define SWITCH7_AKTIF   digitalRead(PIN_SWITCH7) == LOW
#define SWITCH8_AKTIF   digitalRead(PIN_SWITCH8) == LOW

#define SWITCH1_NONAKTIF   digitalRead(PIN_SWITCH1) == HIGH
#define SWITCH2_NONAKTIF   digitalRead(PIN_SWITCH2) == HIGH
#define SWITCH3_NONAKTIF   digitalRead(PIN_SWITCH3) == HIGH
#define SWITCH4_NONAKTIF   digitalRead(PIN_SWITCH4) == HIGH
#define SWITCH5_NONAKTIF   digitalRead(PIN_SWITCH5) == HIGH
#define SWITCH6_NONAKTIF   digitalRead(PIN_SWITCH6) == HIGH
#define SWITCH7_NONAKTIF   digitalRead(PIN_SWITCH7) == HIGH
#define SWITCH8_NONAKTIF   digitalRead(PIN_SWITCH8) == HIGH

void konfig_switch(){
  pinMode(PIN_SWITCH1, INPUT_PULLUP);
  pinMode(PIN_SWITCH2, INPUT_PULLUP);
  pinMode(PIN_SWITCH3, INPUT_PULLUP);
  pinMode(PIN_SWITCH4, INPUT_PULLUP);
  pinMode(PIN_SWITCH5, INPUT_PULLUP);
  pinMode(PIN_SWITCH6, INPUT_PULLUP);
  pinMode(PIN_SWITCH7, INPUT_PULLUP);
  pinMode(PIN_SWITCH8, INPUT_PULLUP);
}

int bacaSemuaSwitch(){
  int tombol_yg_ditekan = 0;
  if (SWITCH1_AKTIF){tombol_yg_ditekan = 1;}
  if (SWITCH2_AKTIF){tombol_yg_ditekan = 2;}
  if (SWITCH3_AKTIF){tombol_yg_ditekan = 3;}
  if (SWITCH4_AKTIF){tombol_yg_ditekan = 4;}
  if (SWITCH5_AKTIF){tombol_yg_ditekan = 5;}
  if (SWITCH6_AKTIF){tombol_yg_ditekan = 6;}
  if (SWITCH7_AKTIF){tombol_yg_ditekan = 7;}
  if (SWITCH8_AKTIF){tombol_yg_ditekan = 8;}

//   if (SWITCH1_NONAKTIF){tombol_yg_ditekan = 9;}
//   if (SWITCH2_NONAKTIF){tombol_yg_ditekan = 10;}
//   if (SWITCH3_NONAKTIF){tombol_yg_ditekan = 11;}
//   if (SWITCH4_NONAKTIF){tombol_yg_ditekan = 12;}
//   if (SWITCH5_NONAKTIF){tombol_yg_ditekan = 13;}
//   if (SWITCH6_NONAKTIF){tombol_yg_ditekan = 14;}
//   if (SWITCH7_NONAKTIF){tombol_yg_ditekan = 15;}
//   if (SWITCH8_NONAKTIF){tombol_yg_ditekan = 16;}
  return tombol_yg_ditekan;
}
#endif