# Now only for STM32F407VG

PROJECT(stm32f4cmsis)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENABLE_LANGUAGE(ASM)

SET(TOOLCHAIN_PREFIX /home/dima/apps/CodeBench)

IF(NOT STM32_StdPeriphLib_DIR)
    SET(STM32_StdPeriphLib_DIR "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS/")
    MESSAGE(STATUS "No STM32_StdPeriphLib_DIR specified, using default: " ${STM32_StdPeriphLib_DIR})
ENDIF()

INCLUDE_DIRECTORIES(
    ${STM32_StdPeriphLib_DIR}/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/
    ${STM32_StdPeriphLib_DIR}/Libraries/CMSIS/CM3/CoreSupport/
    ${CMAKE_CURRENT_SOURCE_DIR}
)

SET(CMSIS_SOURCES
    ${STM32_StdPeriphLib_DIR}/Device/ST/STM32F4xx/Source/Templates/system_stm32f10x.c
    ${STM32_StdPeriphLib_DIR}/Include/core_cm4.h
)

SET(STM32F4_STARTUP ${STM32_StdPeriphLib_DIR}/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f4xx.s)

ADD_LIBRARY(cmsis_f4 ${CMSIS_SOURCES})
SET_TARGET_PROPERTIES(cmsis_f4 PROPERTIES COMPILE_DEFINITIONS "STM32F4xx")


INSTALL(TARGETS cmsis_f4
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

INSTALL(FILES 
    ${STM32_StdPeriphLib_DIR}/Device/ST/STM32F4xx/Include/stm32f4xx.h
    ${STM32_StdPeriphLib_DIR}/Device/ST/STM32F4xx/Include/system_stm32f4xx.h
    ${STM32_StdPeriphLib_DIR}/Include/core_cm4.h
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/include
)

INSTALL(FILES 
    ${STM32F4_STARTUP}
    ./stm32f4xx_flash_extsram.ld
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/lib/
)