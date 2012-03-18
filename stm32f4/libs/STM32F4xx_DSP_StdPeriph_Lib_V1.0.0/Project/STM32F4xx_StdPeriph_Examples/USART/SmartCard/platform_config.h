/**
  ******************************************************************************
  * @file    USART/Smartcard/platform_config.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   Evaluation board specific configuration file.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H

/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the line corresponding to the STMicroelectronics evaluation board
   used to run the example */
#if !defined (USE_STM324xG_EVAL)
 //#define USE_STM324xG_EVAL
#endif

/* Define the STM32F4xx hardware depending on the used evaluation board */
#ifdef USE_STM324xG_EVAL
  #define SC_USART                           USART6
  #define SC_USART_CLK                       RCC_APB2Periph_USART6
  #define SC_USART_APBPERIPHCLOCK            RCC_APB2PeriphClockCmd
  #define SC_USART_IRQn                      USART6_IRQn
  #define SC_USART_IRQHandler                USART6_IRQHandler

  #define SC_USART_TX_PIN                    GPIO_Pin_6                
  #define SC_USART_TX_GPIO_PORT              GPIOC                       
  #define SC_USART_TX_GPIO_CLK               RCC_AHB1Periph_GPIOC
  #define SC_USART_TX_SOURCE                 GPIO_PinSource6
  #define SC_USART_TX_AF                     GPIO_AF_USART6

  #define SC_USART_CK_PIN                    GPIO_Pin_7                
  #define SC_USART_CK_GPIO_PORT              GPIOG                    
  #define SC_USART_CK_GPIO_CLK               RCC_AHB1Periph_GPIOG
  #define SC_USART_CK_SOURCE                 GPIO_PinSource7
  #define SC_USART_CK_AF                     GPIO_AF_USART6


  /* Smartcard Inteface GPIO pins */
  #define SC_3_5V_PIN                        GPIO_Pin_15
  #define SC_3_5V_GPIO_PORT                  GPIOH
  #define SC_3_5V_GPIO_CLK                   RCC_AHB1Periph_GPIOH
  
  #define SC_RESET_PIN                       GPIO_Pin_7
  #define SC_RESET_GPIO_PORT                 GPIOF
  #define SC_RESET_GPIO_CLK                  RCC_AHB1Periph_GPIOF

  #define SC_CMDVCC_PIN                      GPIO_Pin_12
  #define SC_CMDVCC_GPIO_PORT                GPIOG
  #define SC_CMDVCC_GPIO_CLK                 RCC_AHB1Periph_GPIOG

  #define SC_OFF_PIN                         GPIO_Pin_6
  #define SC_OFF_GPIO_PORT                   GPIOF
  #define SC_OFF_GPIO_CLK                    RCC_AHB1Periph_GPIOF
  #define SC_OFF_EXTI_LINE                   EXTI_Line6
  #define SC_OFF_EXTI_PORT_SOURCE            EXTI_PortSourceGPIOF
  #define SC_OFF_EXTI_PIN_SOURCE             EXTI_PinSource6
  #define SC_OFF_EXTI_IRQn                   EXTI9_5_IRQn 
  #define SC_OFF_EXTI_IRQHandler             EXTI9_5_IRQHandler
  
#endif /* USE_STM324xG_EVAL */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
