#define __AVR_ATmega328P__
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include"../../../UTILS/BIT_MATH.h"
#include <avr/interrupt.h>
#define PART4
#ifdef PART1

int main(void)
{
    SET_BIT(DDRD,PD0);
    CLEAR_BIT(PORTD,PD0);
while(1){
    SET_BIT(PORTD,PD0);
    _delay_ms(1000);
    CLEAR_BIT(PORTD,PD0);
    _delay_ms(1000);
}
}
#endif

#ifdef PART2

int main(void)
{
        CLEAR_BIT(DDRB,PB0);
        CLEAR_BIT(DDRB,PB1);
        SET_BIT(DDRC,PC0);
        SET_BIT(DDRC,PC1);
        CLEAR_BIT(PORTC,PC0);
        CLEAR_BIT(PORTC,PC1);
        while(1){
            if(READ_BIT(PINB,PB0))
            SET_BIT(PORTC,PC0);
            else
            CLEAR_BIT(PORTC,PC0);
            if(READ_BIT(PINB,PB1))
            SET_BIT(PORTC,PC1);
            else
            CLEAR_BIT(PORTC,PC1);
        }
}
#endif

#ifdef PART3

int main(void)
{

//1. Configure pin 0 of PORTB to be input pin. 
CLEAR_BIT(DDRB,PB0);

//2. Activate the internal pull up resistor of PB0. 
SET_BIT(PORTB,PB0);
//3. Configure pin 0 of PORTC to be output pin. 
SET_BIT(DDRC,PC0);

//4. Make LED is off at the beginning. 
CLEAR_BIT(PORTC,PC0);
//5. Check if the push button is pressed or not. If yes, wait 30ms then 
//check if the button is still pressed due to switch de-bouncing, If yes, 
//so, the Button is confirm to be pushed so toggle the LED. 
char prev=0;
while(1){
    char curr=PINB&1;
    if(prev==1 && curr==0){
        TOGGLE_BIT(PORTC,PC0);
    }
    prev=curr;
    _delay_ms(30);
}
}
#endif

#ifdef PART4
unsigned char arr[10]={
    0b00111111,
    0b00000110,
    0b01011011,
    0b01001111,
    0b01100110,
    0b01101101,
    0b01111101,
    0b00000111,
    0b01111111,
   0b01100111};
int main(void)
{
    CLEAR_BIT(DDRB,PB0);
    DDRD=0xFF;
    int count=0;
    PORTD=arr[count];
    while(1){
        if(READ_BIT(PINB,PB0)){
            count++;
            PORTD=arr[count];
        }
        if(count==9)
        count=0;
        _delay_ms(400);
    }
}
#endif