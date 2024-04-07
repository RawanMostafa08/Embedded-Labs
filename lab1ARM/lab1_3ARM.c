int i=0;
int prev1 = 0;
int prev2 = 0;
unsigned int counter=0;
void main() {
   GPIO_Digital_Input(&GPIOB_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1  );
   GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_0 | _GPIO_PINMASK_1 | _GPIO_PINMASK_2 | _GPIO_PINMASK_3);
   counter=0;
   GPIOD_ODR = 0x0000;

   while(1){
   unsigned int res1,res2;
   res1=Button(&GPIOB_IDR, 0, 100, 1);
   res2=Button(&GPIOB_IDR, 1, 100, 1);

   if(res1!=0  && counter<15 && prev1 == 0 )
   {
      counter++;
   }
   prev1 = res1;
   if(res2!=0  && counter>0 && prev2 == 0){
      counter--;
   }
   prev2 = res2;
   GPIOD_ODR=counter;
   Delay_ms(100);



// int count = 0;

//   while (1) {
//           print_num(count);
//     char curr0 = READ_BIT(PINC, PC0);
//     char curr1 = READ_BIT(PINC, PC1);
//     if (prev0 == 1 && curr0 == 0) {
//       if (count < 9)
//           count++;
//     }

//     prev0 = curr0;
//     if (prev1 == 1 && curr1 == 0) {
//       if (count >0)
//         count--;
//       }
//     prev1 = curr1;
//     _delay_ms(100);
//   }
   }
}