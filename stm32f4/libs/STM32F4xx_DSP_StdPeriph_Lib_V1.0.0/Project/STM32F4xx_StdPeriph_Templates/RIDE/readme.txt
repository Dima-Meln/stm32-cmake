/**
  @page ride RIDE Project Template for STM32F4xx devices
  
  @verbatim
  ******************** (C) COPYRIGHT 2011 STMicroelectronics *******************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   This sub-directory contains all the user-modifiable files needed to
  *          create a new project linked with the STM32F4xx Standard Peripherals
  *          Library and working with RIDE7 software toolchain (RIDE7 IDE:7.30,
  *          RKitARM for RIDE7:1.31)
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
  @endverbatim
 
 @par Directory contents
 
 - project .rprj/.rapp: A pre-configured project file with the provided library 
                        structure that produces an executable image with RIDE7.

 - stm32f4xx_flash_extsram.ld: This file is the RAISONANCE linker script used to 
                               place program code (readonly) in internal FLASH and 
                               data (readwrite, Stack and Heap)in external SRAM. 
                               You can customize this file to your need.
                                                          
 @par How to use it ?
 
 - Open the Project.rprj project.                          
 - Rebuild all files: Project->build project
 - Load project image: Debug->start(ctrl+D)
 - Run program: Debug->Run(ctrl+F9)  

 @note The needed define symbols for this config are already declared in the
       preprocessor section: USE_STM324xG_EVAL, STM32F4XX, USE_STDPERIPH_DRIVER 


 * <h3><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h3>
 */
