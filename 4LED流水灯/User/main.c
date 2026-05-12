#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//打开GPIOA时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	
	
	//初始化端口
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	
	while(1)
	{
		GPIO_Write(GPIOA,~0X0001);//0000 0000 0000 0001 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0002);//0000 0000 0000 0010 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0004);//0000 0000 0000 0100 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0008);//0000 0000 0000 1000 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0010);//0000 0000 0001 0000 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0020);//0000 0000 0010 0000 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0040);//0000 0000 0100 0000 PA0~PA15的端口
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0080);//0000 0000 1000 0000 PA0~PA15的端口
		Delay_ms(100);

	}
}
