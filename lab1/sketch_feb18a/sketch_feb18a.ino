#define __AVR_ATmega328P__
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#define SET_BIT(REG_NAME, BIT_NUMBER) REG_NAME |= (1 << BIT_NUMBER)
#define CLEAR_BIT(REG_NAME, BIT_NUMBER) REG_NAME &= (~(1 << BIT_NUMBER))
#define TOGGLE_BIT(REG_NAME, BIT_NUMBER) REG_NAME ^= (1 << BIT_NUMBER)
#define READ_BIT(REG_NAME, BIT_NUM) (REG_NAME >> BIT_NUM) & 1
#define CLEAR_PORT(PORT_NAME) PORT_NAME &= 0x00
#define SET_PORT(PORT_NAME) PORT_NAME |= 0xff
#define READ_PORT(PORT_NAME) PORT_NAME & 0xff

void print_num(int count) {
  switch (count) {
    case 0:
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      SET_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      CLEAR_BIT(PORTB, PB0);
      break;

    case 1:
      //0b00000110
      CLEAR_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      CLEAR_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      CLEAR_BIT(PORTD, PD7);
      CLEAR_BIT(PORTB, PB0);
      break;

    case 2:
      //0b01011011
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      CLEAR_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      SET_BIT(PORTD, PD6);
      CLEAR_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 3:
      //0b01001111
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      CLEAR_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 4:
      //0b01100110
      CLEAR_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      CLEAR_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 5:
      //0b01101101
      SET_BIT(PORTD, PD2);
      CLEAR_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 6:
      //0b01111101
      SET_BIT(PORTD, PD2);
      CLEAR_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      SET_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 7:
      //0b00000111
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      CLEAR_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      CLEAR_BIT(PORTD, PD7);
      CLEAR_BIT(PORTB, PB0);
      break;

    case 8:
      //0b01111111
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      SET_BIT(PORTD, PD5);
      SET_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;

    case 9:
      //0b01100111
      SET_BIT(PORTD, PD2);
      SET_BIT(PORTD, PD3);
      SET_BIT(PORTD, PD4);
      CLEAR_BIT(PORTD, PD5);
      CLEAR_BIT(PORTD, PD6);
      SET_BIT(PORTD, PD7);
      SET_BIT(PORTB, PB0);
      break;
  }
}

int main(void) {
  CLEAR_BIT(DDRC, PC0);
  CLEAR_BIT(DDRC,PC0);
  SET_BIT(DDRD, PD2);
  SET_BIT(DDRD, PD3);
  SET_BIT(DDRD, PD4);
  SET_BIT(DDRD, PD5);
  SET_BIT(DDRD, PD6);
  SET_BIT(DDRD, PD7);
  SET_BIT(DDRB, PB0);


  int count = 0;
  int prev1 = 0;
  int prev0 = 0;
  while (1) {
          print_num(count);
    char curr0 = READ_BIT(PINC, PC0);
    char curr1 = READ_BIT(PINC, PC1);
    if (prev0 == 1 && curr0 == 0) {
      if (count < 9)
          count++;
    }

    prev0 = curr0;
    if (prev1 == 1 && curr1 == 0) {
      if (count >0)
        count--;
      }
    prev1 = curr1;
    _delay_ms(100);
  }
}