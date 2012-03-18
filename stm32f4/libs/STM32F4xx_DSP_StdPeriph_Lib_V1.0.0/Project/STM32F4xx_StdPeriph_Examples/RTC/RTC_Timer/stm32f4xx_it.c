/**
  ******************************************************************************
  * @file    RTC/RTC_Timer/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V0.0.2
  * @date    25-July-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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
  
/** @addtogroup RTC_Timer
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t RTCAlarmCount = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
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
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/
/**
  * @brief  This function handles External line 10 to 15 interrupts request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  if((EXTI_GetITStatus(KEY_BUTTON_EXTI_LINE) != RESET))
  {
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);

    /* Enable the RTC Clock */
    RCC_RTCCLKCmd(ENABLE);

    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();

    /* Enable the alarmA */
    RTC_AlarmCmd(RTC_Alarm_A, ENABLE);

    /* Clear the LEFT EXTI  pending bit */
    EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);  
  }
  else if((EXTI_GetITStatus(TAMPER_BUTTON_EXTI_LINE) != RESET))
  {

    /* Disable the RTC Clock */
    RCC_RTCCLKCmd(DISABLE);
  
    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();
        
    /* Clear the TAMPER EXTI  pending bit */
    EXTI_ClearITPendingBit(TAMPER_BUTTON_EXTI_LINE);  
  }
}

/**
  * @brief  This function handles External line 0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  if((EXTI_GetITStatus(WAKEUP_BUTTON_EXTI_LINE) != RESET))
  {
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);
    
    /* Clear the LCD line 2 */
    LCD_ClearLine(Line2);
   
    /* Disable the RTC Clock */
    RCC_RTCCLKCmd(DISABLE);
   
    /* Reset Counter*/
    RTCAlarmCount = 0;
    
    /* Disable the alarm */
    RTC_AlarmCmd(RTC_Alarm_A, DISABLE);
    
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);
  
    /* Display a Full rectangle on the LCD */
    LCD_DrawFullRect(80, 290,240, 25 );
    
    /* Set LCD text color */
    LCD_SetTextColor(Red);

    /* Display rectangle on the LCD */
    LCD_DrawRect(80, 290, 25, 240 );

    /* Clear the WAKEUP EXTI  pending bit */
    EXTI_ClearITPendingBit(WAKEUP_BUTTON_EXTI_LINE);  
  }

}
/**
  * @brief  This function handles RTC Alarm interrupt (A and B) request.
  * @param  None
  * @retval None
  */
void RTC_Alarm_IRQHandler(void)
{
  uint32_t tmp =0;
  /* Check on the AlarmA falg and on the number of interrupts per Second (60*8) */
  if(RTC_GetITStatus(RTC_IT_ALRA) != RESET) 
  { 
    /* Clear RTC AlarmA Flags */
    RTC_ClearITPendingBit(RTC_IT_ALRA);
    if(RTCAlarmCount != 480)
    {
      /* Increament the counter of Alarma interrupts*/
      RTCAlarmCount++;

      /* Set the LCD Back Color */
      LCD_SetTextColor(Green);

      /* Draw rectangle on the LCD */
      LCD_DrawLine(80,290 - (RTCAlarmCount/2),25,Vertical);

      /* Set the LCD text color */
      LCD_SetTextColor(Red);

      /* Display rectangle on the LCD*/
      LCD_DrawRect(80, 290, 25, 240 );

      /* Define the rate of Progress bar */
      tmp = (RTCAlarmCount * 100)/ 480; 

      /* Set the LCD Font */
      LCD_SetFont(&Font16x24);
    
      /* Display Char on the LCD : XXX% */
      LCD_DisplayChar(LINE(2),200, (tmp / 100) +0x30);
      LCD_DisplayChar(LINE(2),180, ((tmp  % 100 ) / 10) +0x30);
      LCD_DisplayChar(LINE(2),160, (tmp % 10) +0x30);
      LCD_DisplayChar(LINE(2),140, 0x25);
    }
    else
    {
      /* Disable the RTC Clock */
      RCC_RTCCLKCmd(DISABLE);
    }
  }
  /* Clear the EXTIL line 17 */
  EXTI_ClearITPendingBit(EXTI_Line17);
  
}

/**
  * @}
  */

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
