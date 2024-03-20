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
SET_BIT(TCCR1A,1);
SET_BIT(TCCR1B,3);
SET_BIT(TCCR1B,4);
TCCR1B |=(1 << CS01)|(1 << CS00);
SET_BIT(TCCR1A,5);
// initialize counter
TCNT1 = 0;
// initialize compare value
OCR1A = 5000;
OCR1B=500;
counter=0;
}

int main() {
  //3. Configure pin 0 of PORTC to be output pin.
  SET_BIT(DDRB, PB2);
  //4. Make LED is off at the beginning.
  // CLEAR_BIT(PORTB, PB1);
  timer1_init();
  while(1){
  while (counter<580) {
    _delay_ms(30);
    counter+=10;
    OCR1B=counter;
  }
  while(counter>0){
    _delay_ms(30);
    counter-=10;
    OCR1B=counter;
  }
  }
}
