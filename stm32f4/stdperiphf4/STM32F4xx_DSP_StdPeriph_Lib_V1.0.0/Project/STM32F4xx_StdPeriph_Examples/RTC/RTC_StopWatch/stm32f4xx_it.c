/**
  ******************************************************************************
  * @file    RTC/RTC_StopWatch/stm32f4xx_it.c 
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
  
/** @addtogroup RTC_StopWatch
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define MESSAGE2   "Press Tamper Button 1 Sec    " 
#define MESSAGE3   "to restart and reset all     " 
#define MESSAGE5   "   the backup register       " 
#define MESSAGE4   "Push Wakeup to start"

/* Private variables ---------------------------------------------------------*/
__IO uint32_t Backupindex = 0;
__IO uint8_t RTCCount = 0, SSecondfraction = 0;
extern __IO uint8_t Startevent;
RTC_TimeTypeDef RTC_StampTimeStruct, RTC_TimeStructure;

/* Define the backup register */
uint32_t BKPDataReg[20] = { RTC_BKP_DR0, RTC_BKP_DR1, RTC_BKP_DR3, RTC_BKP_DR4, RTC_BKP_DR5,
                            RTC_BKP_DR6, RTC_BKP_DR7, RTC_BKP_DR8, RTC_BKP_DR9, RTC_BKP_DR10,
                            RTC_BKP_DR11, RTC_BKP_DR12, RTC_BKP_DR13, RTC_BKP_DR14, RTC_BKP_DR15,
                            RTC_BKP_DR16, RTC_BKP_DR17, RTC_BKP_DR18, RTC_BKP_DR19};

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
  * @brief  This function handles External line 0 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  if((EXTI_GetITStatus(WAKEUP_BUTTON_EXTI_LINE) != RESET) && (Startevent == 0x0))
  {
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);

    /* Clear the LCD line 5 */
    LCD_ClearLine(Line5);
  
    /* Enable the RTC Clock */
    RCC_RTCCLKCmd(ENABLE);

    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();

    /* start count */
    Startevent = 0x1;
  }
  /* Clear the Wakeup EXTI  pending bit */
  EXTI_ClearITPendingBit(WAKEUP_BUTTON_EXTI_LINE);  
}  

/**
  * @brief  This function handles External lines 15 to 10 interrupt request.
  * @param  None
  * @retval None
  */
void EXTI15_10_IRQHandler(void)
{
  if((EXTI_GetITStatus(KEY_BUTTON_EXTI_LINE) != RESET) && (Startevent !=0x0) && (Backupindex < 11))
  {
    uint16_t Colorx;
      
    if (Backupindex < 10)
    {
      /* Increment counter */
      RTCCount++;
      if((uint8_t)(RTCCount% 2) != 0x0)
      { 
        /* Set LCD backcolor*/
        LCD_SetBackColor(Blue2);
        Colorx = White;
      }
      else
      {
        /* Set LCD backcolor*/
        LCD_SetBackColor(Cyan);
        Colorx = Black;
      }
      
      /* Get the Current sub second and time */
      SSecondfraction = 1000 - ((uint32_t)((uint32_t)RTC_GetSubSecond() * 1000) / (uint32_t)0x3FF);
      RTC_GetTime(RTC_Format_BCD, &RTC_StampTimeStruct);
 
      LCD_SetFont(&Font12x12);
      
      /* Display result on the LCD */
      RTC_Time_display( LINE(7 + Backupindex), Colorx, RTC_Get_Time(SSecondfraction , &RTC_StampTimeStruct) ); 

      /* Save time register  to Backup register (the first 10 registers are reserved for time) */
      RTC_WriteBackupRegister(BKPDataReg[Backupindex],(uint32_t)RTC->TR);
       
      /* Save sub second time stamp register (the latest 10 registers are reserved for sub second) */
      RTC_WriteBackupRegister(BKPDataReg[Backupindex + 10], SSecondfraction);
    }
    else
    {
      /* the backup register is full with 10 trials */
      /* Set the LCD Back Color */
      LCD_SetBackColor(Green);
      LCD_SetFont(&Font12x12);
       
      /* Set the LCD Text Color */
      LCD_SetTextColor(Black); 
      LCD_DisplayStringLine(LINE(17), (uint8_t *)MESSAGE2);
      LCD_DisplayStringLine(LINE(18), (uint8_t *)MESSAGE3);
      LCD_DisplayStringLine(LINE(19), (uint8_t *)MESSAGE5);
     }  
     Backupindex++;
  }
  /* Clear the Key EXTI line */
  EXTI_ClearITPendingBit(KEY_BUTTON_EXTI_LINE);     
}

/**
  * @brief  This function handles Tamper&Stamp pin interrupt request.
  * @param  None
  * @retval None
  */
void TAMP_STAMP_IRQHandler(void)
{
  if (RTC_GetITStatus(RTC_IT_TAMP1) != RESET)
  {
    uint8_t i =0;
    
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);
    LCD_SetFont(&Font12x12);
    
    /* Clear LCD line 7 to 9 */
    for (i=0; i < 13; i++)
    {
      /* Clear all the LCD lignes from 7 to 19 */
      LCD_ClearLine(LINE(7+i));
    }

    /* Reset Counter */
    RTCCount = 0;

    /* reset Counter */
    Backupindex = 0 ;

    /* Enetr to idle */
    Startevent =0x0;
   
    /* Set the time to 00h 00mn 00s AM */
    RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
    RTC_TimeStructure.RTC_Hours   = 0x00;
    RTC_TimeStructure.RTC_Minutes = 0x00;
    RTC_TimeStructure.RTC_Seconds = 0x00;  
    RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);
 
    /* Disable the RTC Clock */
    RCC_RTCCLKCmd(DISABLE);
    LCD_SetFont(&Font16x24);

    /* Set the LCD Text Color */
    LCD_SetTextColor(Blue);

    /* Display message 4 to the LCD */
    LCD_DisplayStringLine(LINE(5), (uint8_t *)MESSAGE4);

    /* Clear EXTI line 21 */
    EXTI_ClearITPendingBit(EXTI_Line21);
    
    /* Clear Tamper pin interrupt pending bit */
    RTC_ClearITPendingBit(RTC_IT_TAMP1);
  }
}

/**
  * @}
  */ 

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
