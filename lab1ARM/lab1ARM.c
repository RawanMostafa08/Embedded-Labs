void main() {
   GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL );
   while(1){
   GPIOD_ODR = 0xFFFF ;
   Delay_ms(500);
   GPIOD_ODR = 0x0000 ;
   Delay_ms(500);
   }
}