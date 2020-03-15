/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����led
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */  
#include "stm32f10x.h"
#include "bsp_led.h"

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();	 

	/* ����1��ֱ�ӿ��ƼĴ��� */
	while(1)
	{
		// ODR GPIOB
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (��λֵ)
		// 1  1  1  1      1  1  1 1    1 1 1 1    1 1 1 0

		GPIOB->ODR = 0XFFFE; 		//�͵�ƽ��GPIOB0��LED0������
		Delay(0x0FFFFF);
		GPIOB->ODR = 0XFFFF;		//�ߵ�ƽ��GPIOB0��LED0������

		// ODR GPIOC
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (��λֵ)
		// 1  1  1  1      1  1  1 1    1 1 1 0    1 1 1 1	
		GPIOC->ODR = 0XFFEF; 		//�͵�ƽ��GPIOC4��LED1������
		Delay(0x0FFFFF);
    
		GPIOC->ODR = 0XFFFF;		//�ߵ�ƽ��GPIOC4��LED1������

		// ODR GPIOC
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (��λֵ)
		// 1  1  1  1      1  1  1 1    1 1 1 1    0 1 1 1		 	
		GPIOC->ODR = 0XFFF7; 		//�͵�ƽ��GPIOC5��LED2������
		Delay(0x0FFFFF);
		GPIOC->ODR = 0XFFFF;		//�ߵ�ƽ��GPIOC5��LED2������ 

		// ODR GPIOA
		// 15 14 13 12     11 10 9 8    7 6 5 4    3 2 1 0
		// 0  0  0  0      0  0  0 0    0 0 0 0    0 0 0 0 (��λֵ)
		// 1  1  1  1      1  1  1 1    1 1 1 1    1 1 0 1		 	
		GPIOA->ODR = 0XFFFD; 		//�͵�ƽ��GPIOA1��LED2������
		Delay(0x0FFFFF);
		GPIOA->ODR = 0XFFFF;		//�ߵ�ƽ��GPIOA1��LED2������ 
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
