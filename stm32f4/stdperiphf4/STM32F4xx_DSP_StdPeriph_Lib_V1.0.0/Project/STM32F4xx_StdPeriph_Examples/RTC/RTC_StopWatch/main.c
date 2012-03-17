/**
  ******************************************************************************
  * @file    RTC/RTC_StopWatch/main.c 
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
  
/** @addtogroup RTC_StopWatch
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MESSAGE1   " **** STOPWATCH ****" 
#define MESSAGE2   "Push Wakeup to Start" 

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;
__IO uint32_t Secondfraction = 0;
__IO uint8_t Startevent = 0;
RTC_InitTypeDef RTC_InitStructure;
RTC_TimeTypeDef RTC_TimeStruct; 
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

  /* RTC configuration  */
  RTC_Config();
  
  /* Set the LCD Text Color */
  LCD_SetTextColor(Red);
  
  /* Set the LCD Back Color */
  LCD_SetBackColor(White);
  
  /* Draw rectangle on the LCD */
  LCD_DrawRect(43, 300, 30, 260);

  /* Configure the external interrupt "WAKEUP" and "KEY" buttons */
  STM_EVAL_PBInit(BUTTON_WAKEUP,BUTTON_MODE_EXTI);
  STM_EVAL_PBInit(BUTTON_KEY,BUTTON_MODE_EXTI);
  
  /* Configure the RTC tamper register */
  RTC_TamperConfig();
  
  /* Set the LCD Text Color */
  LCD_SetTextColor(Blue);
  
  /* Displays MESSAGE2 on line 5 */
  LCD_DisplayStringLine(LINE(5), (uint8_t *)MESSAGE2);
  
  /* Infinite loop */
  while (1)
  {
    /* Set The LCD font size */
    LCD_SetFont(&Font16x24);
     
    /* Set the LCD Back Color */
    LCD_SetBackColor(White);

    /* Check on the event 'start'*/
    if(Startevent != 0x0)
    {
       /* Get the RTC sub second fraction */
       Secondfraction = 1000 - ((uint32_t)((uint32_t)RTC_GetSubSecond() * 1000) / (uint32_t)0x3FF);
    }
    else
    {
      /* Idle */
      Secondfraction =0x0;
    }
    
    /* Get the Curent time */
    RTC_GetTime(RTC_Format_BCD, &RTC_TimeStruct);
    
    /* Display the curent time and the sub second on the LCD */
    RTC_Time_display(Line2, Black , RTC_Get_Time(Secondfraction , &RTC_TimeStruct));
  }
}


/**
  * @brief  Displays the current Time on the LCD.
  * @param  Line:  the Line where to display the Current time .
  *           This parameter can be one of the following values:
  *             @arg Linex: where x can be 0..9
  * @param  Color_x: specifies the Background Color.
  * @param  table: the Current time and sub second.
  * @retval None
  */
void RTC_Time_display(uint8_t Line,__IO uint16_t Color_x, Table_TypeDef table )
{   
  uint8_t i = 0;

  /* Initialize table */
  LCD_SetTextColor(Color_x);
  
  for (i=0;i<12;i++)
  {
    /* Display char on the LCD */
    LCD_DisplayChar(Line, (290 - (20 *i)), table.tab[i]);
  }  
}

/**
  * @brief  Configures the RTC peripheral by selecting the clock source.
  * @param  None
  * @retval None
  */
void RTC_Config(void)
{
  RTC_TimeTypeDef  RTC_TimeStructure;
  
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
  RTC_InitStructure.RTC_AsynchPrediv = 0x1F;
  RTC_InitStructure.RTC_SynchPrediv  = 0x3FF;
  RTC_InitStructure.RTC_HourFormat   = RTC_HourFormat_24;
  RTC_Init(&RTC_InitStructure);
  
  /* Set the time to 00h 00mn 00s AM */
  RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
  RTC_TimeStructure.RTC_Hours   = 0x00;
  RTC_TimeStructure.RTC_Minutes = 0x00;
  RTC_TimeStructure.RTC_Seconds = 0x00;  
  RTC_SetTime(RTC_Format_BCD, &RTC_TimeStructure);
}

/**
  * @brief  Returns the current time and sub second.
  * @param  Secondfraction: the sub second fraction.
  * @param  RTC_TimeStructure : pointer to a RTC_TimeTypeDef structure that 
  *         contains the current time values. 
  * @retval table : return current time and sub second in a table form
  */
Table_TypeDef RTC_Get_Time(uint32_t Secondfraction , RTC_TimeTypeDef* RTC_TimeStructure )
{
  Table_TypeDef table2;

  /* Fill the table2 fields with the current Time*/
  table2.tab[0] = (((uint8_t)(RTC_TimeStructure->RTC_Hours & 0xF0) >> 0x04) + 0x30);
  table2.tab[1]  = (((uint8_t)(RTC_TimeStructure->RTC_Hours & 0x0F))+ 0x30);
  table2.tab[2]  = 0x3A;
  
  table2.tab[3]  = (((uint8_t)(RTC_TimeStructure->RTC_Minutes & 0xF0) >> 0x04) + 0x30);
  table2.tab[4]  =(((uint8_t)(RTC_TimeStructure->RTC_Minutes & 0x0F))+ (uint8_t)0x30);
  table2.tab[5]  = 0x3A;

  table2.tab[6]   = (((uint8_t)(RTC_TimeStructure->RTC_Seconds & 0xF0) >> 0x04)+ 0x30);
  table2.tab[7]   = (((uint8_t)(RTC_TimeStructure->RTC_Seconds & 0x0F)) + 0x30);
  table2.tab[8]   = 0x2E;
  
  table2.tab[9]   = (uint8_t)((Secondfraction / 100) + 0x30);
  table2.tab[10]  = (uint8_t)(((Secondfraction % 100 ) / 10) +0x30);
  table2.tab[11]  =  (uint8_t)((Secondfraction % 10) +0x30);
  
  /* return table2 */
  return table2;
}

/**
  * @brief  RTC Tamper Configuration.
  * @param  None
  * @retval None
  */
void RTC_TamperConfig(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
    
  /* EXTI configuration */
  EXTI_ClearITPendingBit(EXTI_Line21);
  EXTI_InitStructure.EXTI_Line = EXTI_Line21;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable RTC_TAMP_STAMP_IRQn */
  NVIC_InitStructure.NVIC_IRQChannel = TAMP_STAMP_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  
  /* determines the number of active pulse for the specific level */
  RTC_TamperFilterConfig(RTC_TamperFilter_2Sample);
  
  /* Determines the frequency at which each of the tamper inputs are sampled */
  RTC_TamperSamplingFreqConfig(RTC_TamperSamplingFreq_RTCCLK_Div16384);

  /* Select the tamper 1 with High level */
  RTC_TamperTriggerConfig(RTC_Tamper_1, RTC_TamperTrigger_LowLevel );

  /* Enabale the tamper 1 */
  RTC_TamperCmd(RTC_Tamper_1 , ENABLE);
  
  /* Enable Tamper interrupt */
  RTC_ITConfig(RTC_IT_TAMP, ENABLE);
  
  /* Clear tamper 1 falg */
  RTC_ClearFlag(RTC_FLAG_TAMP1F);
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
