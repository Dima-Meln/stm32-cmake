# Now only for STM32F407VG

PROJECT(stm32f4cmsis)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ENABLE_LANGUAGE(ASM)

SET(TOOLCHAIN_PREFIX /home/dima/apps/CodeBench)

IF(NOT STM32F4_CMSIS_DIR)
    SET(STM32F4_CMSIS_DIR "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS/")
    MESSAGE(STATUS "No STM32F4_CMSIS_DIR specified, using default: " ${STM32F4_CMSIS_DIR})
ENDIF()

INCLUDE_DIRECTORIES(
    ${STM32F4_CMSIS_DIR}Device/ST/STM32F4xx/Include/
    ${STM32F4_CMSIS_DIR}/Include/
    ${CMAKE_CURRENT_SOURCE_DIR}
)

SET(CMSIS_SOURCES
    ${STM32F4_CMSIS_DIR}/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c
)

SET(STM32F4_STARTUP ${STM32F4_CMSIS_DIR}/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f4xx.s)

ADD_LIBRARY(stm32f4_cmsis ${CMSIS_SOURCES})
SET_TARGET_PROPERTIES(stm32f4_cmsis PROPERTIES COMPILE_DEFINITIONS "STM32F4xx")

#&&&ADD_EXECUTABLE(startup_stm32f4xx.O)

INSTALL(TARGETS stm32f4_cmsis
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

INSTALL(FILES 
    ${STM32F4_CMSIS_DIR}/Device/ST/STM32F4xx/Include/stm32f4xx.h
    ${STM32F4_CMSIS_DIR}/Device/ST/STM32F4xx/Include/system_stm32f4xx.h
    ${STM32F4_CMSIS_DIR}/Include/arm_common_tables.h
    ${STM32F4_CMSIS_DIR}/Include/arm_math.h
    ${STM32F4_CMSIS_DIR}/Include/core_cm0.h
    ${STM32F4_CMSIS_DIR}/Include/core_cm3.h
    ${STM32F4_CMSIS_DIR}/Include/core_cm4.h
    ${STM32F4_CMSIS_DIR}/Include/core_cm4_simd.h
    ${STM32F4_CMSIS_DIR}/Include/core_cmInstr.h
    ${STM32F4_CMSIS_DIR}/Include/core_cmFunc.h
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_cmsis
)

INSTALL(FILES 
    ./stm32_flash.ld
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/lib/
)

INSTALL(FILES 
    ${STM32F4_STARTUP}
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/src/
)

INSTALL(FILES
	FindSTM32F4_CMSIS.cmake
	DESTINATION
	/usr/share/cmake-2.8/Modules/
)