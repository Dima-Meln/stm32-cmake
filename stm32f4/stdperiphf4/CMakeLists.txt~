PROJECT(stm32f4stdperiph)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
ENABLE_LANGUAGE(ASM)

SET(TOOLCHAIN_PREFIX /home/dima/apps/CodeBench)

IF(NOT STM32F4_CMSIS_DIR)
    SET(STM32F4_CMSIS_DIR "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS/")
    MESSAGE(STATUS "No STM32F4_CMSIS_DIR specified, using default: " ${STM32F4_CMSIS_DIR})
ENDIF()

IF(NOT STM32F4_StdPeriphLib_DIR)
    SET(STM32F4_StdPeriphLib_DIR "/home/dima/projects/git/stm32-cmake/stm32f4/libs/STM32F4xx_StdPeriph_Driver")
    MESSAGE(STATUS "No STM32_StdPeriphLib_DIR specified, using default: " ${STM32F4_StdPeriphLib_DIR})
ENDIF()

INCLUDE_DIRECTORIES(
    ${STM32F4_CMSIS_DIR}Device/ST/STM32F4xx/Include/
    ${STM32F4_CMSIS_DIR}/Include/
    ${STM32F4_StdPeriphLib_DIR}/inc/
)

SET(LIB_SOURCES
    ${STM32F4_StdPeriphLib_DIR}/src/misc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_adc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_can.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_crc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_aes.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_des.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_tdes.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dac.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dbgmcu.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dcmi.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dma.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_exti.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_flash.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_fsmc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_gpio.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash_md5.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash_sha1.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_i2c.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_iwdg.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_pwr.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rcc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rng.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rtc.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_sdio.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_spi.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_syscfg.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_tim.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_usart.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_wwdg.c
)

IF(USE_ASSERT)
    ADD_DEFINITIONS("-D\"assert_param(expr)\"=\"((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))\"")
ELSE()
    ADD_DEFINITIONS("-D\"assert_param(expr)\"=\"((void)0)\"")
ENDIF()

ADD_LIBRARY(stm32f4_stdperiph ${LIB_SOURCES})
SET_TARGET_PROPERTIES(stm32f4_stdperiph PROPERTIES COMPILE_DEFINITIONS "STM32F4xx_stdperiph")

INSTALL(TARGETS stm32f4_stdperiph
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

INSTALL(FILES 
    ${STM32F4_StdPeriphLib_DIR}/inc/misc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_adc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_can.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_crc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_cryp.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_dac.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_dbgmcu.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_dcmi.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_dma.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_exti.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_flash.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_fsmc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_gpio.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_hash.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_i2c.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_iwdg.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_pwr.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_rcc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_rng.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_rtc.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_sdio.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_spi.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_syscfg.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_tim.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_usart.h
    ${STM32F4_StdPeriphLib_DIR}/inc/stm32f4xx_wwdg.h
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_stdperiph
)

INSTALL(FILES 
    ${STM32F4_StdPeriphLib_DIR}/inc/misc.h
    RENAME
    stm32f4xx_misc.h
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_stdperiph
)