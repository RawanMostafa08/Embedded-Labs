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
uint8_t ADC_endconversion_Flag = 0;
bool x_y = 0;
void adc_init() {
  // AREF = AVcc
  ADMUX = (1 << REFS0);
  // ADC Enable and prescaler of 128
  // 16000000/128 = 125000
  // (1<<ADIE)=1 🡪 set ADC interrupt enable
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)
           | (1 << ADIE);
  // Set global interrupt
  sei();
}
ISR(ADC_vect) {
  ADC_endconversion_Flag = 1;
}
uint16_t adc_read(uint8_t ch) {
  // select the corresponding channel 0~5
  // ANDing with ’7′ will always keep the value
  // of ‘ch’ between 0 and 5
  ch &= 0b00000111;             // AND operation with 7
  ADMUX = (ADMUX & 0xF8) | ch;  // clears the bottom 3 bits before ORing
  // start single conversion
  // write ’1′ to ADSC
  ADCSRA |= (1 << ADSC);
  // wait for conversion to complete
  // ADSC becomes ’0′ again
  // till then, run loop continuously
  if (ADC_endconversion_Flag == 1) {
    ADC_endconversion_Flag = 0;
    return (ADC);
  } else
    return (-1);
}

int main() {
  Serial.begin(9600);
  uint16_t adc_result0;
  uint16_t adc_result1;
  // initialize adc
  adc_init();
  while (1) {
    if (x_y == 0) {
      adc_result0 = adc_read(0);  // read adc value at PC0
      if (adc_result0 != -1) {
        Serial.println("X-axis  :" + String(adc_result0));
        x_y = 1;
      }
    }
    if (x_y == 1) {
      adc_result1 = adc_read(1);  // read adc value at PC0
      if (adc_result1 != -1) {
        Serial.println("Y-axis  :" + String(adc_result1));
        x_y = 0;
      }
    }
    _delay_ms(500);
  }
}
