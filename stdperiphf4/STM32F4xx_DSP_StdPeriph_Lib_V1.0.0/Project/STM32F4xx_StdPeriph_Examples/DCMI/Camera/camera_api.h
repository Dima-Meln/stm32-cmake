/**
  ******************************************************************************
  * @file    DCMI/Camera/camera_api.h 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   Header for camera_api.c module
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
#ifndef __CAMERA_API_H
#define __CAMERA_API_H

/* Includes ------------------------------------------------------------------*/
#include "lcd_log.h"
#include "main.h"

/* Exported constants --------------------------------------------------------*/
#define DCMI_DR_ADDRESS       0x50050028
#define FSMC_LCD_ADDRESS      0x68000002
#define NOKEY                 0
#define SEL                   1
#define UP                    2
#define DOWN                  3

/* Exported types ------------------------------------------------------------*/
/* Camera devices enumeration */
typedef enum   
{
  OV9655_CAMERA            =   0x00,	 /* Use OV9655 Camera */
  OV2640_CAMERA            =   0x01      /* Use OV2640 Camera */
}Camera_TypeDef;

/* Image Sizes enumeration */
typedef enum   
{
  BMP_QQVGA             =   0x00,	    /* BMP Image QQVGA 160x120 Size */
  BMP_QVGA              =   0x01,           /* BMP Image QVGA 320x240 Size */
  JPEG_160x120          =   0x02,	    /* JPEG Image 160x120 Size */
  JPEG_176x144          =   0x03,	    /* JPEG Image 176x144 Size */
  JPEG_320x240          =   0x04,	    /* JPEG Image 320x240 Size */
  JPEG_352x288          =   0x05	    /* JPEG Image 352x288 Size */
}ImageFormat_TypeDef;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
uint8_t Demo_Init(void);
void Display_Menu(uint8_t ForematIndex, uint8_t MaxForematIndex);
void Camera_Config(void);
void OV2640_SpecialEffects(uint8_t index);
void Delay(uint32_t nTime);
void TimingDelay_Decrement(void);
void Demo_LCD_Clear(void);

#endif /* __CAMERA_API_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
