/**
  ******************************************************************************
  * @file    USART/USART_TwoBoards/DataExchangeInterrupt/main.h
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
#include "stm324xg_eval_ioe.h"

/* Exported typedef -----------------------------------------------------------*/
#define countof(a)   (sizeof(a) / sizeof(*(a)))
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;

/* Exported define ------------------------------------------------------------*/

/* USER_TIMEOUT value for waiting loops. This timeout is just guarantee that the
   application will not remain stuck if the USART communication is corrupted. 
   You may modify this timeout value depending on CPU frequency and application
   conditions (interrupts routines, number of data to transfer, baudrate, frequence
   CPU...). */ 
#define USER_TIMEOUT                    ((uint32_t)0x64) /* Waiting 1s */

/* USART Mode Selected */
#define USART_MODE_TRANSMITTER           0x00
#define USART_MODE_RECEIVER              0x01      

/* USART Transaction Type */
#define USART_TRANSACTIONTYPE_CMD        0x00
#define USART_TRANSACTIONTYPE_DATA       0x01


/* Definition for USARTx resources ********************************************/
#define USARTx                           USART3
#define USARTx_CLK                       RCC_APB1Periph_USART3
#define USARTx_CLK_INIT                  RCC_APB1PeriphClockCmd
#define USARTx_IRQn                      USART3_IRQn
#define USARTx_IRQHandler                USART3_IRQHandler

#define USARTx_TX_PIN                    GPIO_Pin_10                
#define USARTx_TX_GPIO_PORT              GPIOC                       
#define USARTx_TX_GPIO_CLK               RCC_AHB1Periph_GPIOC
#define USARTx_TX_SOURCE                 GPIO_PinSource10
#define USARTx_TX_AF                     GPIO_AF_USART3

#define USARTx_RX_PIN                    GPIO_Pin_11                
#define USARTx_RX_GPIO_PORT              GPIOC                    
#define USARTx_RX_GPIO_CLK               RCC_AHB1Periph_GPIOC
#define USARTx_RX_SOURCE                 GPIO_PinSource11
#define USARTx_RX_AF                     GPIO_AF_USART3


/* Misc definition ************************************************************/
/* Transmit buffer size */
#define TXBUFFERSIZE                     (countof(TxBuffer) - 1)
/* Receive buffer size */
#define RXBUFFERSIZE                     TXBUFFERSIZE

/* Commands list */
#define CMD_RIGHT                        0x55
#define CMD_LEFT                         0xAA
#define CMD_UP                           0x33
#define CMD_DOWN                         0xCC
#define CMD_SEL                          0xFF 

#define CMD_ACK                          0x66 

/* Number of data bytes for each command */
#define CMD_RIGHT_SIZE                   0x01
#define CMD_LEFT_SIZE                    0x05
#define CMD_UP_SIZE                      0x14
#define CMD_DOWN_SIZE                    0x1E
#define CMD_SEL_SIZE                     TXBUFFERSIZE

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t GetVar_NbrOfData(void);
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
