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

int counter;
void timer1_init(){
SET_BIT(TCCR1A,0);
SET_BIT(TCCR1B,3);
TCCR1B |=(1 << CS01)|(1 << CS00);
SET_BIT(TCCR1A,7);
// initialize counter
TCNT1 = 0;
// initialize compare value
OCR1A = 0;
counter=0;
}

int main() {
  //3. Configure pin 0 of PORTC to be output pin.
  SET_BIT(DDRB, PB1);
  //4. Make LED is off at the beginning.
  CLEAR_BIT(PORTB, PB1);
  timer1_init();
  while (counter<63000) {
    _delay_ms(100);
    counter+=1000;
    OCR1A=counter;
  }
  while(counter>1){
    _delay_ms(100);
    counter-=1000;
    OCR1A=counter;
  }
}
