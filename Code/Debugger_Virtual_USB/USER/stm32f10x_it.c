/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "hw_config.h"

extern volatile uint32_t myTick;

extern u8 g_DatRev[256];
extern u8 g_DatRev_num;
extern u8 USART2_FLAG;
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    if (myTick <= 0xffff0000)
        myTick++;
    else
        myTick = 0;
    //myTick = (myTick < 0xf) ?	myTick++ : 0;
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

void USART1_IRQHandler(void)
{
    u8 Cache_num;
    GPIO_ResetBits(GPIOC, GPIO_Pin_2);
    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)//
    {
        Cache_num = USART_ReceiveData(USART1);  //
        USART_SendData(USART2, Cache_num);
        USART_SendData(USART1, Cache_num);

        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
    USART_ClearFlag(USART1, USART_FLAG_TC);
}

/*void USART2_IRQHandler(void)
{
    u8 Cache_num;
		uint8_t buf1[2]; 
    GPIO_ResetBits(GPIOC, GPIO_Pin_1);
    if (USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        Cache_num = USART_ReceiveData(USART2);
				buf1[0] = Cache_num;
			  USB_TxWrite(buf1, 1);
        USART_SendData(USART1, Cache_num);
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);
    }
    USART_ClearFlag(USART2, USART_FLAG_TC);
}*/

void USART2_IRQHandler(void) {
    uint8_t Clear = Clear;
  	
	  if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET) {
				GPIO_ResetBits(GPIOC, GPIO_Pin_2);
				g_DatRev[g_DatRev_num++] = USART2->DR;
		}
		if(USART_GetITStatus(USART2, USART_IT_IDLE) != RESET)
			GPIO_ResetBits(GPIOC, GPIO_Pin_1);
			Clear = USART2->SR;
		  Clear = USART2->DR;
		  USART2_FLAG = 1;
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
