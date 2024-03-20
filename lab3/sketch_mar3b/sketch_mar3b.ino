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


volatile uint8_t tot_overflow;

void timer2_init(){
  // initialize counter
  TCNT2 = 0;
TIMSK2 |= (1 << TOIE2);
// Non PWM mode FOC2A=1
TCCR2A |= (1 << FOC2A);
// Normal Mode WGM21=0 & WGM20=0
TCCR2A &= ~(1 << WGM21);
TCCR2A &= ~(1 << WGM20);
// Clock = F_CPU/1024 CS20=1 CS21=0 CS22=1
TCCR2B |= (1 << CS22) | (1 << CS20);
TCCR2B |= (1 << CS21);
}

ISR(TIMER2_OVF_vect) {
  tot_overflow++;
}

int main() {
  //3. Configure pin 0 of PORTC to be output pin.
  SET_BIT(DDRC, PC0);
  //4. Make LED is off at the beginning.
  CLEAR_BIT(PORTC, PC0);
  // SET_BIT(SREG, 7);
  timer2_init();
  sei();
  while (1) {
    if (tot_overflow >= 30)  // NOTE: '>=' is used
    {
      if (TCNT2 >= 131) {
        PORTC ^= (1 << 0);  // toggles the led
        TCNT2 = 0;          // reset counter
        tot_overflow = 0;   // reset overflow counter
      }
    }
  }
}
