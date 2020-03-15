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
 
	/* ����3��ʹ�üĴ�������IO */ 
	while(1)
	{

		LED1_TOGGLE;	 			//led1״̬��ת����	
    Delay(0x0FFFFF); 
		LED1_TOGGLE;				//led1״̬��ת����

		LED2_TOGGLE;				//led2״̬��ת����
		Delay(0x0FFFFF);	   
		LED2_TOGGLE;		  	//led2״̬��ת����

		LED3_TOGGLE;				//led3״̬��ת����
		Delay(0x0FFFFF);
		LED3_TOGGLE;				//led3״̬��ת����

		LED4_TOGGLE;				//led3״̬��ת����
		Delay(0x0FFFFF);
		LED4_TOGGLE;				//led3״̬��ת����
	}
}

void Delay(__IO uint32_t nCount)	 //�򵥵���ʱ����
{
	for(; nCount != 0; nCount--);
}
/*********************************************END OF FILE**********************/
