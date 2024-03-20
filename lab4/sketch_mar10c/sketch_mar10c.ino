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

int main() {
  SET_PORT(DDRB);
  CLEAR_BIT(DDRB,PB0);
  Serial.begin(9600);
   int t=0;
while(1){
  TCCR1A=0;
  TIFR1= (1<<ICF1);
  TCCR1B=0x41;
  while((TIFR1&(1<<ICF1))==0);
  // t=ICR1;
  TIFR1=(1<<ICF1);
  t=ICR1-t;
  Serial.println(t);
  // t=0;
}
}


















