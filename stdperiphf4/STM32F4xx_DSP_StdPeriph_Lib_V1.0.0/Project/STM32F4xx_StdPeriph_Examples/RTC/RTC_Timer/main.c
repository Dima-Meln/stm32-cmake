/**
  ******************************************************************************
  * @file    RTC/RTC_Timer/main.c 
  * @author  MCD Application Team
  * @version V0.0.2
  * @date    25-July-2011
  * @brief   Main program body
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
#include "main.h"

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */
  
/** @addtogroup RTC_Timer
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MESSAGE1   "*** Progress Bar ***" 
#define MESSAGE2   "WAKEUP     TAMPER     KEY " 
#define MESSAGE3   " Reset      Stop     Start" 

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
RTC_InitTypeDef RTC_InitStructure;
RTC_TimeTypeDef  RTC_TimeStruct;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f4xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f4xx.c file
     */  
  
  /* Initialize the LCD */
  STM324xG_LCD_Init(); 

  /* Clear the LCD */ 
  LCD_Clear(White);

  /* Set the LCD Back Color */
  LCD_SetBackColor(Blue);
  
  /* Set the LCD Text Color */
  LCD_SetTextColor(White);
   
  /* Displays MESSAGE1 on line 1 */
  LCD_DisplayStringLine(LINE(0), (uint8_t *)MESSAGE1);

  /* RTC configuration */
  RTC_Config();
  
  /* Set the LCD Text Color */
  LCD_SetTextColor(Red);
  
  /* Displays a rectangle on the LCD */
  LCD_DrawRect(80, 290, 25, 240 );
  
  /* Configure the external interrupt "KEY", "WAKEUP" and "TAMPER" buttons */
  STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_EXTI);
  STM_EVAL_PBInit(BUTTON_WAKEUP, BUTTON_MODE_EXTI);
  STM_EVAL_PBInit(BUTTON_TAMPER, BUTTON_MODE_EXTI);  
     
  /* Configure RTC AlarmA register to generate 8 interrupts per 1 Second */
  RTC_AlarmConfig();
  
  /* set LCD Font */
  LCD_SetFont(&Font12x12);

  /* Set the LCD Back Color */
  LCD_SetBackColor(White); 

  /* Set the LCD Text Color */
  LCD_SetTextColor(Black);

  /* Displays MESSAGE2 and MESSAGE3 on the LCD */
  LCD_DisplayStringLine(LINE(18), (uint8_t *)MESSAGE2);  
  LCD_DisplayStringLine(LINE(19), (uint8_t *)MESSAGE3);  

  /* Infinite loop */
  while (1)
  {
  }
}

/**
  * @brief  Configures the RTC peripheral and select the clock source.
  * @param  None
  * @retval None
  */
void RTC_Config(void)
{
  /* Enable the PWR clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

  /* Allow access to RTC */
  PWR_BackupAccessCmd(ENABLE);

  /* Reset RTC Domain */
  RCC_BackupResetCmd(ENABLE);
  RCC_BackupResetCmd(DISABLE);

  /* Enable the LSE OSC */
  RCC_LSEConfig(RCC_LSE_ON);

  /* Wait till LSE is ready */  
  while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
  {
  }

  /* Select the RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

  /* Configure the RTC data register and RTC prescaler */
  RTC_InitStructure.RTC_AsynchPrediv = 0x7F;
  RTC_InitStructure.RTC_SynchPrediv  = 0xFF;
  RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;
  RTC_Init(&RTC_InitStructure);
  
  /* Set the time to 00h 00mn 00s AM */
  RTC_TimeStruct.RTC_H12     = RTC_H12_AM;
  RTC_TimeStruct.RTC_Hours   = 0x00;
  RTC_TimeStruct.RTC_Minutes = 0x00;
  RTC_TimeStruct.RTC_Seconds = 0x00;  
  RTC_SetTime(RTC_Format_BCD, &RTC_TimeStruct);
  
}

/**
  * @brief  Configures the RTC Alarm.
  * @param  None
  * @retval None
  */
void RTC_AlarmConfig(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
  RTC_AlarmTypeDef RTC_AlarmStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* EXTI configuration */
  EXTI_ClearITPendingBit(EXTI_Line17);
  EXTI_InitStructure.EXTI_Line = EXTI_Line17;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
  
  /* Enable the RTC Alarm Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = RTC_Alarm_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
 
  /* Set the alarmA Masks */
  RTC_AlarmStructure.RTC_AlarmMask = RTC_AlarmMask_All;
  RTC_SetAlarm(RTC_Format_BCD, RTC_Alarm_A, &RTC_AlarmStructure);
  
  /* Set AlarmA subseconds and enable SubSec Alarm : generate 8 interripts per Second */
  RTC_AlarmSubSecondConfig(RTC_Alarm_A, 0xFF, RTC_AlarmSubSecondMask_SS14_5);

  /* Enable AlarmA interrupt */
  RTC_ITConfig(RTC_IT_ALRA, ENABLE);

}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
