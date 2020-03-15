/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   systickϵͳ��ʱ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ISO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_led.h"

// ����Ա

/*
 * t : ��ʱʱ�� 
 * Ticks : ���ٸ�ʱ�����ڲ���һ���ж� 
 * f : ʱ��Ƶ�� 72000000
 * t = Ticks * 1/f = (72000000/100000) * (1/72000000) = 10us 
 */ 

/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	
	/* LED �˿ڳ�ʼ�� */
	LED_GPIO_Config();

	/* ����SysTick Ϊ10us�ж�һ�� */
	SysTick_Init();

	for(;;)
	{

		LED1( ON ); 
	    Delay_us(10000);    	// 10000 * 10us = 100ms
		//Delay_ms(100);
		LED1( OFF );
	  
		LED2( ON );
	    Delay_us(10000);		// 10000 * 10us = 100ms
		//Delay_ms(100);
		LED2( OFF );
	
		LED3( ON );
	    Delay_us(10000);		// 10000 * 10us = 100ms
		//Delay_ms(100);
		LED3( OFF );	

		LED4( ON );
	    Delay_us(10000);		// 10000 * 10us = 100ms
		//Delay_ms(100);
		LED4( OFF );	

	}     
}
/*********************************************END OF FILE**********************/
