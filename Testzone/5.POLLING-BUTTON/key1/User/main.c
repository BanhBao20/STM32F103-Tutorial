/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ���԰���
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
#include "bsp_key.h"

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
  /* config the led */
  LED_GPIO_Config();
  LED1_ON;

  /*config key*/
  Key_GPIO_Config();

  while (1)
  {
    if (Key_Scan(GPIOA, GPIO_Pin_0) == KEY_ON)
    {
      /*LED1��ת*/
      LED1_TOGGLE;
    }
    if (Key_Scan(GPIOA, GPIO_Pin_8) == KEY_ON)
    {
      /*LED1��ת*/
      LED4_TOGGLE;
    }
  }
}
/*********************************************END OF FILE**********************/
