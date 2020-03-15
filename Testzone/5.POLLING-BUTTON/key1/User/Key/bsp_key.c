/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����Ӧ��bsp��ɨ��ģʽ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� iSO-MINI STM32 ������ 
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */

#include "bsp_key.h"
#include "bsp_led.h"

/// ����ȷ����ʱ
static void Key_Delay(__IO u32 nCount)
{
	for (; nCount != 0; nCount--)
		;
}

/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key1_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*������˿ڣ�PA����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_8;
	//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void Key2_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*������˿ڣ�PC����ʱ��*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void Key_GPIO_Config(void)
{
	Key1_GPIO_Config();
	Key2_GPIO_Config();
}

/**
  * @brief   ����Ƿ��а�������
  * @param   ����Ķ˿ںͶ˿�λ
  *		@arg GPIOx: x�����ǣ�A...G�� 
  *		@arg GPIO_PIN ������GPIO_PIN_x��x������1...16��
  * @retval  ������״̬
  *		@arg KEY_ON:��������
  *		@arg KEY_OFF:����û����
  */
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, u16 GPIO_Pin)
{
	/*����Ƿ��а������� */
	if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
	{
		/*��ʱ����*/
		Key_Delay(10000);
		if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
		{
			/*�ȴ������ͷ� */
			while (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON)
				;
			return KEY_ON;
		}
		else
			return KEY_OFF;
	}
	else
		return KEY_OFF;
}

/*-----------------------------------------------------------------*/
void Key_Test(void)
{
	/* config the led */
	LED_GPIO_Config();
	LED1_ON;
	LED2_ON;
	LED4_ON;

	/*config key*/
	Key1_GPIO_Config();
	Key2_GPIO_Config();

	while (1)
	{
		if (Key_Scan(GPIOA, GPIO_Pin_0) == KEY_ON) // KEY1
		{
			/*LED1��ת*/
			LED1_TOGGLE;
		}

		if (Key_Scan(GPIOC, GPIO_Pin_13) == KEY_ON) // KEY2
		{
			/*LED2��ת*/
			LED2_TOGGLE;
		}
		if (Key_Scan(GPIOA, GPIO_Pin_8) == KEY_ON) // KEY3
		{
			/*LED1��ת*/
			LED4_TOGGLE;
		}
	}
}
/*********************************************END OF FILE**********************/
