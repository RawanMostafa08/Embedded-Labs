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

#define SCK PB5
#define MISQ PB4
#define MOSI PB3
#define SS PB2

void SPI_Init() {
 DDRB |= (1<<MOSI) | (1<<SCK) | (1<<SS);
 DDRB &= ~(1<<MISO);
 PORTB |= (1<<SS);
 SPCR |= (1<<SPE) | (1<<MSTR) | (1<<SPR0);
 SPSR &= ~(1<<SPI2X);
}

void SPI_Write(char data) {
  char flush_buffer;
  SPDR =data;
  while (!(SPSR & (1<<SPIF)));
  flush_buffer=SPDR;
}
char SPI_Read(){
  SPDR=0xFF;
  while(!(SPSR & (1<<SPIF)));
  return (SPDR);
}

int main() {
  Serial.begin(921600);
  SPI_Init();
  uint8_t count=0;
  uint8_t rec=0;
  char buffer[5];
  PORTB &= ~(1<<SS); ///set SS pin Low and wait for 1 second to allow slave to up
  _delay_ms(1000);
  while(1){
     SPI_Write(count);
    _delay_ms(1000);
    count++;
    rec=SPI_Read();
    int x=int(rec);
    // sprintf(buffer,"%d   ",rec);
    Serial.println(x);
    if(count==100)
    {
      count=0;
    }
    _delay_ms(500);
  }

}
