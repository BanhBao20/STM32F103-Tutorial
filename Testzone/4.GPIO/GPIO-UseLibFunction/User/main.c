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
 
	/* ����2��ʹ�ù̼������IO */
	while (1)
	{
		LED1( ON );			  // ��
		Delay(0x0FFFFF);
		LED1( OFF );		  // ��

		LED2( ON );			  // ��
		Delay(0x0FFFFF);
		LED2( OFF );		  // ��

		LED3( ON );			  // ��
		Delay(0x0FFFFF);
		LED3( OFF );		  // ��	   

		LED4( ON );			  // ��
		Delay(0x0FFFFF);
		LED4( OFF );		  // ��	   
	}

}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
