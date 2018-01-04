#include "bsp.h"

/*******************************************************************************
�� �� ����void IWDG_Init(void)
�������������Ź���ʼ��						
��ڲ�����							
���ز�����
����ʱ��: 2011.6.24
********************************************************************************/
void IWDG_Init(void)
{
    IWDG_WriteAccessCmd( IWDG_WriteAccess_Enable );
    IWDG_SetPrescaler( IWDG_Prescaler_128);	//��С
    IWDG_SetReload(0x138 * 5);		//40KHz�ڲ�ʱ�� (1/40000 * 128 * 0x138 * 5= 5s )
    IWDG_WriteAccessCmd( IWDG_WriteAccess_Disable );
    IWDG_Enable();
    IWDG_ReloadCounter();
}

/*******************************************************************************
* Function Name : void IWDG_Clear(void)
* Description   : �忴�Ź�
* Input         : 
* Output        : 
* Other         : 
* Date          : 2014.04.13
*******************************************************************************/
void WDG_Clear(void)
{
    IWDG_ReloadCounter();
}

/*******************************************************************************
* Function Name :void SysTickInit(void)
* Description   :ϵͳ��ʱ��ʱ������
* Input         :
* Output        :
* Other         :ʱ��Ϊ1ms
* Date          :2011.11.03  12:59:13
*******************************************************************************/
void SysTickInit(void)
{
    RCC_ClocksTypeDef rccClk = {0};
    
    RCC_GetClocksFreq(&rccClk);
    
    SysTick_Config(rccClk.HCLK_Frequency / 1000);			//uCOSʱ��1ms
}

/*******************************************************************************
* Function Name :void InterruptOrder(void)
* Description   :�ж����������ȼ�
* Input         :
* Output        :
* Other         :
* Date          :2011.10.27  11:50:05
*******************************************************************************/
void NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4);//���ȼ�����  ȫΪ��ռʽ���ȼ�
}

/*******************************************************************************
* Function Name :void SystemConfig(void)
* Description   :ϵͳ��ʼ��
* Input         :
* Output        :
* Other         :
* Date          :2011.10.27  13:14:59
*******************************************************************************/
void BSP_Init(void)
{
    NVIC_Configuration();	//�ж����ȼ�����
    //GPIO_Configuration();	//
}