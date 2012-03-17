/**
  ******************************************************************************
  * @file    I2S/I2S_TwoBoards/DataExchangePolling/main.h
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm324xg_eval.h"

/* Exported typedef -----------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Exported define ------------------------------------------------------------*/
/* Uncomment the line below if you will use the I2S peripheral as a Master */
#define I2S_MASTER 
/* Uncomment the line below if you will use the I2S peripheral as a Slave */
/* #define I2S_SLAVE */

/* I2Sx Communication boards Interface */
#define I2Sx                           SPI2
#define I2Sxext                        I2S2ext
#define I2Sx_CLK                       RCC_APB1Periph_SPI2
#define I2Sx_CLK_INIT                  RCC_APB1PeriphClockCmd

#define I2Sx_WS_PIN                    GPIO_Pin_12
#define I2Sx_WS_GPIO_PORT              GPIOB
#define I2Sx_WS_GPIO_CLK               RCC_AHB1Periph_GPIOB
#define I2Sx_WS_SOURCE                 GPIO_PinSource12
#define I2Sx_WS_AF                     GPIO_AF_SPI2

#define I2Sx_CK_PIN                    GPIO_Pin_13
#define I2Sx_CK_GPIO_PORT              GPIOB
#define I2Sx_CK_GPIO_CLK               RCC_AHB1Periph_GPIOB
#define I2Sx_CK_SOURCE                 GPIO_PinSource13
#define I2Sx_CK_AF                     GPIO_AF_SPI2

#define I2Sx_SD_PIN                    GPIO_Pin_3
#define I2Sx_SD_GPIO_PORT              GPIOC
#define I2Sx_SD_GPIO_CLK               RCC_AHB1Periph_GPIOC
#define I2Sx_SD_SOURCE                 GPIO_PinSource3
#define I2Sx_SD_AF                     GPIO_AF_SPI2

#define I2Sxext_SD_PIN                 GPIO_Pin_2
#define I2Sxext_SD_GPIO_PORT           GPIOI
#define I2Sxext_SD_GPIO_CLK            RCC_AHB1Periph_GPIOI
#define I2Sxext_SD_SOURCE              GPIO_PinSource2
#define I2Sxext_SD_AF                  GPIO_AF_SPI3

#define TX_MASTER_BUFFERSIZE           (countof(TxMasterBuffer) - 1)
#define RX_MASTER_BUFFERSIZE           TX_MASTER_BUFFERSIZE

#define TX_SLAVE_BUFFERSIZE           (countof(TxSlaveBuffer) - 1)
#define RX_SLAVE_BUFFERSIZE           TX_SLAVE_BUFFERSIZE

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
