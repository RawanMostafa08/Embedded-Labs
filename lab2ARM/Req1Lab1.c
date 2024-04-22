/*int i=0;
void main() {
    unsigned int period = 0;
    period = PWM_TIM1_Init(3800);
    GPIO_Digital_Output(&GPIOE_BASE, _GPIO_PINMASK_ALL);
    PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
    while(1){
    for(i=0;i<period/2;i++)
    {
    PWM_TIM1_Set_Duty(period/(i*2), _PWM_NON_INVERTED, _PWM_CHANNEL4);
    Delay_ms(10);
    }
    for(i=period/2;i>0;i--)
    {
    PWM_TIM1_Set_Duty(period/(i*2), _PWM_NON_INVERTED, _PWM_CHANNEL4);
    // PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
    Delay_ms(10);
    }

    }
}*/