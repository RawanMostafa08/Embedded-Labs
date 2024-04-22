    int i=0;
void main() {
    unsigned int period = 0;
    period = PWM_TIM4_Init(4000);
    GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_12| _GPIO_PINMASK_13| _GPIO_PINMASK_14| _GPIO_PINMASK_15);
    while(1){
    for(i=0;i<100;i++)
    {
    PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL1);
    Delay_ms(10);
    }
    for(i=0;i<100;i++)
    {
    PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL2);
    Delay_ms(10);
    }
    for(i=0;i<100;i++)
    {
    PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL3);
    Delay_ms(10);
    }
    for(i=0;i<100;i++)
    {
    PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL4);
    Delay_ms(10);
    }


    for(i=100;i>0;i--)
    {
    PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
    PWM_TIM4_Set_Duty(period*(i)/100.0, _PWM_NON_INVERTED, _PWM_CHANNEL1);
    Delay_ms(10);
    }
    for(i=100;i>0;i--)
    {
    PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL2);
    Delay_ms(10);
    }
    for(i=100;i>0;i--)
    {
    PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL3);
    Delay_ms(10);
    }
    for(i=100;i>0;i--)
    {
    PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
    PWM_TIM4_Set_Duty(period*((i)/100.0), _PWM_NON_INVERTED, _PWM_CHANNEL4);
    Delay_ms(10);
    }


    }
}