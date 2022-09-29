#ifndef __LED_H__
#define __LED_H__

#define PINLED1 13
#define PINLED2 12
#define PINLED3 11
#define PINLED4 10
#define PINLED5 50
#define PINLED6 51
#define PINLED7 52
#define PINLED8 53

#define LED1_ON digitalWrite(PINLED1, HIGH);
#define LED2_ON digitalWrite(PINLED2, HIGH);
#define LED3_ON digitalWrite(PINLED3, HIGH);
#define LED4_ON digitalWrite(PINLED4, HIGH);
#define LED5_ON digitalWrite(PINLED5, HIGH);
#define LED6_ON digitalWrite(PINLED6, HIGH);
#define LED7_ON digitalWrite(PINLED7, HIGH);
#define LED8_ON digitalWrite(PINLED8, HIGH);

#define LED1_OFF digitalWrite(PINLED1, LOW);
#define LED2_OFF digitalWrite(PINLED2, LOW);
#define LED3_OFF digitalWrite(PINLED3, LOW);
#define LED4_OFF digitalWrite(PINLED4, LOW);
#define LED5_OFF digitalWrite(PINLED5, LOW);
#define LED6_OFF digitalWrite(PINLED6, LOW);
#define LED7_OFF digitalWrite(PINLED7, LOW);
#define LED8_OFF digitalWrite(PINLED8, LOW);

uint8_t i = 0;
#define KANAN 0
#define KIRI 1
void konfig_led()
{
    // atur PORTB 0->7 sbg output
    pinMode(PINLED1, OUTPUT);
    pinMode(PINLED2, OUTPUT);
    pinMode(PINLED3, OUTPUT);
    pinMode(PINLED4, OUTPUT);
    pinMode(PINLED5, OUTPUT);
    pinMode(PINLED6, OUTPUT);
    pinMode(PINLED7, OUTPUT);
    pinMode(PINLED8, OUTPUT);

    // atur PORTB 0->7 sbg output
    //   DDRB = 0b11111111;
}
void kelap_kelip()
{
    LED1_ON;
    LED2_OFF;
    LED3_ON;
    LED4_OFF;
    LED5_ON;
    LED6_OFF;
    LED7_ON;
    LED8_OFF;
}

void onAll()
{
    LED1_ON;
    LED2_ON;
    LED3_ON;
    LED4_ON;
    LED5_ON;
    LED6_ON;
    LED7_ON;
    LED8_ON;
}
void offAll()
{
    LED1_OFF;
    LED2_OFF;
    LED3_OFF;
    LED4_OFF;
    LED5_OFF;
    LED6_OFF;
    LED7_OFF;
    LED8_OFF;
}

void led_count_up(int jeda)
{
    for (int i = 0; i < 255; i++)
    {
        PORTB = i;
        delay(jeda);
    }
}
void led_count_down(int jeda)
{
    for (int i = 255; i > 0; --i)
    {
        PORTB = i;
        delay(jeda);
    }
}

void led_shift_left()
{
    uint8_t a = 0b00000001;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);

    a = a << 1;
    PORTB = a;
    delay(1000);
}
void led_shift_right()
{
    uint8_t a = 0b10000000;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);

    a = a >> 1;
    PORTB = a;
    delay(1000);
}

void led_shift(int arah, int jeda)
{
    uint8_t data;
    if (arah == KANAN)
    {
        data = 0b10000000;
        for (int i = 0; i < 7; i++)
        {
            PORTB = data >> i;
            delay(jeda);
        }
    }else if(arah == KIRI){
        data = 0b00000001;
        for (int i = 0; i < 7; i++)
        {
            PORTB = data << i;
            delay(jeda);
        }
    }
}
#endif