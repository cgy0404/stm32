#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//打开GPIOA时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	
	
	//初始化端口
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	while(1)
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);//响
 
		Delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//不响
		Delay_ms(100);
		GPIO_ResetBits(GPIOB, GPIO_Pin_12);//响
		Delay_ms(100);
		GPIO_SetBits(GPIOB, GPIO_Pin_12);//不响
		Delay_ms(700);

	}
}
