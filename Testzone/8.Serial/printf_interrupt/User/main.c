/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
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
#include "bsp_usart1.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
	/* USART1 configuration mode is 115200 8-N-1, interrupt reception */
	USART1_Config();
	
	NVIC_Configuration();

	printf("\r\n This is a serial port interrupt receiving echo experiment \r\n");
	printf("\r\n Please enter the character in HyperTerminal or Serial Debug Assistant \r\n");

	for(;;)
	{
		
	}
}
/*********************************************END OF FILE**********************/
