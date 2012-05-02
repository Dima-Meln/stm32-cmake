# Install script for directory: /home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/home/dima/apps/CodeBench/arm-none-eabi")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_misc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_adc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_can.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_crc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_cryp.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_dac.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_dbgmcu.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_dcmi.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_dma.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_exti.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_flash.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_fsmc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_gpio.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_hash.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_i2c.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_iwdg.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_pwr.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_rcc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_rng.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_rtc.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_sdio.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_spi.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_syscfg.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_tim.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_usart.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/libstm32f4_stdperiph_wwdg.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/misc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_adc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_can.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_crc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_cryp.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_dac.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_dbgmcu.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_dcmi.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_dma.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_exti.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_flash.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_fsmc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_gpio.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_hash.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_i2c.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_iwdg.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_pwr.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_rcc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_rng.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_rtc.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_sdio.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_spi.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_syscfg.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_tim.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_usart.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_wwdg.h")
FILE(INSTALL DESTINATION "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph" TYPE FILE FILES
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/misc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_adc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_can.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_crc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_cryp.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_dac.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_dbgmcu.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_dcmi.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_dma.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_exti.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_flash.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_fsmc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_gpio.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_hash.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_i2c.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_iwdg.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_pwr.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_rcc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_rng.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_rtc.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_sdio.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_spi.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_syscfg.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_tim.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_usart.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_wwdg.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph/stm32f4xx_misc.h")
FILE(INSTALL DESTINATION "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_stdperiph" TYPE FILE RENAME "stm32f4xx_misc.h" FILES "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver/inc/misc.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/cmake-2.8/Modules/FindSTM32F4_StdPeriphLib.cmake")
FILE(INSTALL DESTINATION "/usr/share/cmake-2.8/Modules" TYPE FILE FILES "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/./FindSTM32F4_StdPeriphLib.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/dima/projects/git/stm32-cmake/stm32f4/stdperiphf4/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
