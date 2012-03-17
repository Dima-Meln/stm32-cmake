/**
  ******************************************************************************
  * @file    PWR/BOR/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
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
#include "stm32f4xx.h"
#include "stm324xg_eval.h"

/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup PWR_BOR
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Uncomment the corresponding line to select the BOR level */
#define BOR_LEVEL OB_BOR_OFF /*!< BOR Reset threshold levels for 1.62V - 2.10V VDD power supply  */
//#define BOR_LEVEL OB_BOR_LEVEL1  /*!< BOR Reset threshold levels for 2.10V - 2.40V VDD power supply */
//#define BOR_LEVEL OB_BOR_LEVEL2  /*!< BOR Reset threshold levels for 2.40V - 2.70V VDD power supply */
//#define BOR_LEVEL OB_BOR_LEVEL3  /*!< BOR Reset threshold levels for 2.70V - 3.60V VDD power supply */

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
__IO uint32_t Counter = 0;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
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
       
  /* Initialize LED1 on STM324xG-EVAL board */
  STM_EVAL_LEDInit(LED1);

  /* Initialize Key Button mounted on STM324xG-EVAL board */
  STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_GPIO);

  /* Test if Key push-button on STM324xG-EVAL Board is pressed */
  if (STM_EVAL_PBGetState(BUTTON_KEY) == 0x00)
  {
    /* Get BOR Option Bytes */
    if((FLASH_OB_GetBOR() & 0x0C) != BOR_LEVEL) 
    {
      /* Unlocks the option bytes block access */
      FLASH_OB_Unlock();

      /* Select the desired V(BOR) Level -------------------------------------*/
      FLASH_OB_BORConfig(BOR_LEVEL); 

      /* Launch the option byte loading */
      FLASH_OB_Launch();

      /* Locks the option bytes block access */
      FLASH_OB_Lock();
    }
  } 
   
  while (1)
  {
    /* Toggle The LED1 */
    STM_EVAL_LEDToggle(LED1);

    /* Inserted Delay */
    for(Counter = 0; Counter < 0x5FFFF; Counter++);
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
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
