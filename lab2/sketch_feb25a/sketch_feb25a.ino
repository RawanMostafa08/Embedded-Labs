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
  SET_BIT(EIMSK, 0);
  SET_BIT(EICRA, 0);
  SET_BIT(EICRA, 1);
  //1. Configure pin 2 of PORTD to be input pin.
  CLEAR_BIT(DDRD, PD2);
  SET_BIT(SREG, 7);
}

ISR(INT0_vect) {
  //5. Check if the push button is pressed or not. If yes, wait 30ms then
  //check if the button is still pressed due to switch de-bouncing, If yes,
  //so, the Button is confirm to be pushed so toggle the LED.
  bool prev = 0;
  while (1) {
    bool curr=(PIND &(1<<PD2) );
    if (prev == 1 && curr == 0) {
      TOGGLE_BIT(PORTC, PC0);
    }
    prev = curr;
    _delay_ms(30);
  }
}

int main(){
  init();
    //3. Configure pin 0 of PORTC to be output pin.
  SET_BIT(DDRC, PC0);
    //4. Make LED is off at the beginning.
  CLEAR_BIT(PORTC, PC0);
  while(true);
}
