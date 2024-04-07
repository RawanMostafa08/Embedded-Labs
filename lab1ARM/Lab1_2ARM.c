/*int i=0;
void main() {
   GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL );
   GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL );
   //Button(&GPIOD_IDR, 0, 1, 1));
   while(1){
   GPIOD_ODR = 0x0000 ;
   GPIOE_ODR = 0x0000 ;

   for(i =0;i<4;i++)
   {
    GPIOD_ODR |= (1<<i);
    GPIOD_ODR |= (1<<i+4);
    GPIOD_ODR |= (1<<i+8);
    GPIOD_ODR |= (1<<i+12);
    GPIOE_ODR |= (1<<i+8);
    GPIOE_ODR |= (1<<i+12);
    Delay_ms(100);
   }
   for(i =0;i<4;i++)
   {
    GPIOD_ODR &=~(1<<i);
    GPIOD_ODR &=~(1<<i+4);
    GPIOD_ODR &=~(1<<i+8);
    GPIOD_ODR &=~(1<<i+12);
    GPIOE_ODR &=~(1<<i+8);
    GPIOE_ODR &=~(1<<i+12);
    Delay_ms(100);
   }
   }
}*/