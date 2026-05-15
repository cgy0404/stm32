#include "stm32f10x.h"                  // Device header



void Buzzer_Init(void)
{
	//开启时钟
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOB,ENABLE); //开启GPIOA的时钟
	
	//GPIO初始化
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz ;
	GPIO_Init (GPIOB ,&GPIO_InitStructure );   //将PA1和PA2引脚初始化为推挽输出
	
	//设置GPIO初始化后的默认电平
	GPIO_SetBits(GPIOB,GPIO_Pin_12); //设置PA1和PA2引脚为高电平
}



void Buzzer_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);//设置PA1引脚为低电平
}


void Buzzer_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);//设置PA1引脚为高电平
}

void Buzzer_Turn(void)
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) ==0 ) //获取输出寄存器状态，如果当前引脚输出低电平
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);//则设置PA1引脚为高电平
	}
	else                               //否则，即当前引脚输出高电平
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);//则设置PA1引脚为低电平
	}
}
