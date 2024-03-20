#define __AVR_ATmega328P__
#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include <util/delay.h>
#define SET_BIT(REG_NAME, BIT_NUMBER) REG_NAME |= (1 << BIT_NUMBER)
#define CLEAR_BIT(REG_NAME, BIT_NUMBER) REG_NAME &= (~(1 << BIT_NUMBER))
#define TOGGLE_BIT(REG_NAME, BIT_NUMBER) REG_NAME ^= (1 << BIT_NUMBER)
#define READ_BIT(REG_NAME, BIT_NUM) (REG_NAME >> BIT_NUM) & 1
#define CLEAR_PORT(PORT_NAME) PORT_NAME &= 0x00
#define SET_PORT(PORT_NAME) PORT_NAME |= 0xff
#define READ_PORT(PORT_NAME) PORT_NAME & 0xff

void init() {
  CLEAR_BIT(SREG, 7);
  SET_BIT(EIMSK, 1);
  SET_BIT(EICRA, 2);
  SET_BIT(EICRA, 3);
  //1. Configure pin 2 of PORTD to be input pin.
  CLEAR_BIT(DDRD, PD3);
  //2. Activate the internal pull up resistor of PD3.
  SET_BIT(PORTD, PD3);
  SET_BIT(SREG, 7);
}

ISR(INT1_vect) {
  for (int i = 0; i < 5; i++) {
    SET_BIT(PORTC, PC0);
    SET_BIT(PORTC, PC1);
    SET_BIT(PORTC, PC2);
    _delay_ms(500);
    CLEAR_BIT(PORTC, PC0);
    CLEAR_BIT(PORTC, PC1);
    CLEAR_BIT(PORTC, PC2);
    _delay_ms(500);
  }
}

int main() {
  init();
  //3. Configure pin 0 of PORTC to be output pin.
  SET_BIT(DDRC, PC0);
  SET_BIT(DDRC, PC1);
  SET_BIT(DDRC, PC2);
  //4. Make LED is off at the beginning.
  CLEAR_BIT(PORTC, PC0);
  CLEAR_BIT(PORTC, PC1);
  CLEAR_BIT(PORTC, PC2);

  while (true) {

    SET_BIT(PORTC, PC0);
    _delay_ms(500);
    CLEAR_BIT(PORTC, PC0);
    SET_BIT(PORTC, PC1);
    _delay_ms(500);
    CLEAR_BIT(PORTC, PC1);
    SET_BIT(PORTC, PC2);
    _delay_ms(500);
    CLEAR_BIT(PORTC, PC2);
  }
}
