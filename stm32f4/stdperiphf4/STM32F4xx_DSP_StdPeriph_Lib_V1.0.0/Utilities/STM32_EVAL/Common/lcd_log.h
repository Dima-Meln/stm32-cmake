/**
  ******************************************************************************
  * @file    lcd_log.h
  * @author  MCD Application Team
  * @version V5.0.0
  * @date    30-September-2011
  * @brief   header for the lcd_log.c file
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
#ifndef  __LCD_LOG_H__
#define  __LCD_LOG_H__

/* Includes ------------------------------------------------------------------*/

#include "lcd_log_conf.h"

/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup Common
  * @{
  */

/** @addtogroup LCD_LOG
  * @{
  */
  
/** @defgroup LCD_LOG
  * @brief 
  * @{
  */ 


/** @defgroup LCD_LOG_Exported_Defines
  * @{
  */ 
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/** These value can be changed by user */

#ifdef LCD_SCROLL_ENABLED
 #define     LCD_CACHE_DEPTH     (YWINDOW_SIZE + CACHE_SIZE)
#else
 #define     LCD_CACHE_DEPTH     YWINDOW_SIZE
#endif
/**
  * @}
  */ 

/** @defgroup LCD_LOG_Exported_Types
  * @{
  */ 
typedef struct _LCD_LOG_line
{
  uint8_t  line[XWINDOW_MAX];
  uint16_t color;

}LCD_LOG_line;

/**
  * @}
  */ 

/** @defgroup LCD_LOG_Exported_Macros
  * @{
  */ 
#define  LCD_ErrLog(...)    LCD_LineColor = Red;\
                            printf("ERROR: ") ;\
                            printf(__VA_ARGS__);\
                            LCD_LineColor = LCD_LOG_DEFAULT_COLOR

#define  LCD_UsrLog(...)    LCD_LineColor = LCD_LOG_DEFAULT_COLOR;\
                            printf(__VA_ARGS__);\


#define  LCD_DbgLog(...)    LCD_LineColor = Cyan;\
                            printf(__VA_ARGS__);\
                            LCD_LineColor = LCD_LOG_DEFAULT_COLOR
/**
  * @}
  */ 

/** @defgroup LCD_LOG_Exported_Variables
  * @{
  */ 
extern uint16_t LCD_LineColor;
/**
  * @}
  */ 

/** @defgroup LCD_LOG_Exported_FunctionsPrototype
  * @{
  */ 
void LCD_LOG_Init(void);
void LCD_LOG_DeInit(void);
void LCD_LOG_SetHeader(uint8_t *Title);
void LCD_LOG_SetFooter(uint8_t *Status);
void LCD_LOG_ClearTextZone(void);
#ifdef LCD_SCROLL_ENABLED
 ErrorStatus LCD_LOG_ScrollBack(void);
 ErrorStatus LCD_LOG_ScrollForward(void);
#endif
/**
  * @}
  */ 


#endif /* __LCD_LOG_H__ */

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */  

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
