/**
  ******************************************************************************
  * @file    USART/USART_TwoBoards/DataExchangeInterrupt/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "main.h"

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup USART_DataExchangeInterrupt
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern uint8_t TxBuffer[];
extern uint8_t RxBuffer[];
extern uint8_t CmdBuffer[];
extern uint8_t AckBuffer[];
extern __IO uint8_t RxIndex;
extern __IO uint8_t TxIndex;

extern __IO uint8_t UsartTransactionType;
extern __IO uint8_t UsartMode;

__IO uint8_t Counter = 0x00;
extern __IO uint32_t TimeOut;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
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
  * @brief  This function handles PendSV_Handler exception.
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
  /* Decrement the timeout value */
  if (TimeOut != 0x0)
  {
    TimeOut--;
  }
  
  if (Counter < 10)
  {
    Counter++;
  }
  else
  {
    Counter = 0x00;
    STM_EVAL_LEDToggle(LED1);
  }
}

/******************************************************************************/
/*            STM32F4xx Peripherals Interrupt Handlers                        */
/******************************************************************************/
/**
* @brief  This function handles USRAT interrupt request.
* @param  None
* @retval None
*/
void USARTx_IRQHandler(void)
{
  /* USART in mode Tramitter -------------------------------------------------*/
  if (USART_GetITStatus(USARTx, USART_IT_TXE) == SET)
  { /* When Joystick Pressed send the command then send the data */
    if (UsartMode == USART_MODE_TRANSMITTER)
    { /* Send the command */
      if (UsartTransactionType == USART_TRANSACTIONTYPE_CMD)
      {
        USART_SendData(USARTx, CmdBuffer[TxIndex++]);
        if (TxIndex == 0x02)
        {
          /* Disable the USARTx transmit data register empty interrupt */
          USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
        }
      }
      /* Send the data */
      else
      {
        USART_SendData(USARTx, TxBuffer[TxIndex++]);
        if (TxIndex == GetVar_NbrOfData())
        {
          /* Disable the USARTx transmit data register empty interrupt */
          USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
        }
      }
    }
    /*If Data Received send the ACK*/
    else
    {
      USART_SendData(USARTx, AckBuffer[TxIndex++]);
      if (TxIndex == 0x02)
      {
          /* Disable the USARTx transmit data register empty interrupt */
          USART_ITConfig(USARTx, USART_IT_TXE, DISABLE);
      }
    }
  }
  
  /* USART in mode Receiver --------------------------------------------------*/
  if (USART_GetITStatus(USARTx, USART_IT_RXNE) == SET)
  {
    if (UsartMode == USART_MODE_TRANSMITTER)
    {
      AckBuffer[RxIndex++] = USART_ReceiveData(USARTx);
    }
    else
    {
      /* Receive the command */
      if (UsartTransactionType == USART_TRANSACTIONTYPE_CMD)
      {
        CmdBuffer[RxIndex++] = USART_ReceiveData(USARTx);
      }
      /* Receive the USART data */
      else
      {
        RxBuffer[RxIndex++] = USART_ReceiveData(USARTx);
      }
    }
  }     
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
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

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
