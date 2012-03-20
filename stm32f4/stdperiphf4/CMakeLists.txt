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


set(STM32F4_StdPeriphLib_misc_src ${STM32F4_StdPeriphLib_DIR}/src/misc.c)
set(STM32F4_StdPeriphLib_adc_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_adc.c)
set(STM32F4_StdPeriphLib_can_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_can.c)
set(STM32F4_StdPeriphLib_crc_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_crc.c)
set(STM32F4_StdPeriphLib_cryp_src 
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_aes.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_des.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_cryp_tdes.c
)
set(STM32F4_StdPeriphLib_dac_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dac.c)
set(STM32F4_StdPeriphLib_dbgmcu_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dbgmcu.c)
set(STM32F4_StdPeriphLib_dcmi_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dcmi.c)
set(STM32F4_StdPeriphLib_dma_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_dma.c)
set(STM32F4_StdPeriphLib_exti_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_exti.c)
set(STM32F4_StdPeriphLib_flash_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_flash.c)
set(STM32F4_StdPeriphLib_fsmc_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_fsmc.c)
set(STM32F4_StdPeriphLib_gpio_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_gpio.c)
set(STM32F4_StdPeriphLib_hash_src 
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash_md5.c
    ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_hash_sha1.c
)
set(STM32F4_StdPeriphLib_i2c_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_i2c.c)
set(STM32F4_StdPeriphLib_iwdg_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_iwdg.c)
set(STM32F4_StdPeriphLib_pwr_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_pwr.c)
set(STM32F4_StdPeriphLib_rcc_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rcc.c)
set(STM32F4_StdPeriphLib_rng_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rng.c)
set(STM32F4_StdPeriphLib_rtc_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_rtc.c)
set(STM32F4_StdPeriphLib_sdio_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_sdio.c)
set(STM32F4_StdPeriphLib_spi_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_spi.c)
set(STM32F4_StdPeriphLib_syscfg_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_syscfg.c)
set(STM32F4_StdPeriphLib_tim_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_tim.c)
set(STM32F4_StdPeriphLib_usart_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_usart.c)
set(STM32F4_StdPeriphLib_wwdg_src ${STM32F4_StdPeriphLib_DIR}/src/stm32f4xx_wwdg.c)


IF(USE_ASSERT)
    ADD_DEFINITIONS("-D\"assert_param(expr)\"=\"((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))\"")
ELSE()
    ADD_DEFINITIONS("-D\"assert_param(expr)\"=\"((void)0)\"")
ENDIF()

add_library(stm32f4_stdperiph_misc ${STM32F4_StdPeriphLib_misc_src})
add_library(stm32f4_stdperiph_adc ${STM32F4_StdPeriphLib_adc_src})
add_library(stm32f4_stdperiph_can ${STM32F4_StdPeriphLib_can_src})
add_library(stm32f4_stdperiph_crc ${STM32F4_StdPeriphLib_crc_src})
add_library(stm32f4_stdperiph_cryp ${STM32F4_StdPeriphLib_cryp_src})
add_library(stm32f4_stdperiph_dac ${STM32F4_StdPeriphLib_dac_src})
add_library(stm32f4_stdperiph_dbgmcu ${STM32F4_StdPeriphLib_dbgmcu_src})
add_library(stm32f4_stdperiph_dcmi ${STM32F4_StdPeriphLib_dcmi_src})
add_library(stm32f4_stdperiph_dma ${STM32F4_StdPeriphLib_dma_src})
add_library(stm32f4_stdperiph_exti ${STM32F4_StdPeriphLib_exti_src})
add_library(stm32f4_stdperiph_flash ${STM32F4_StdPeriphLib_flash_src})
add_library(stm32f4_stdperiph_fsmc ${STM32F4_StdPeriphLib_fsmc_src})
add_library(stm32f4_stdperiph_gpio ${STM32F4_StdPeriphLib_gpio_src})
add_library(stm32f4_stdperiph_hash ${STM32F4_StdPeriphLib_hash_src})
add_library(stm32f4_stdperiph_i2c ${STM32F4_StdPeriphLib_i2c_src})
add_library(stm32f4_stdperiph_iwdg ${STM32F4_StdPeriphLib_iwdg_src})
add_library(stm32f4_stdperiph_pwr ${STM32F4_StdPeriphLib_pwr_src})
add_library(stm32f4_stdperiph_rcc ${STM32F4_StdPeriphLib_rcc_src})
add_library(stm32f4_stdperiph_rng ${STM32F4_StdPeriphLib_rng_src})
add_library(stm32f4_stdperiph_rtc ${STM32F4_StdPeriphLib_rtc_src})
add_library(stm32f4_stdperiph_sdio ${STM32F4_StdPeriphLib_sdio_src})
add_library(stm32f4_stdperiph_spi ${STM32F4_StdPeriphLib_spi_src})
add_library(stm32f4_stdperiph_syscfg ${STM32F4_StdPeriphLib_syscfg_src})
add_library(stm32f4_stdperiph_tim ${STM32F4_StdPeriphLib_tim_src})
add_library(stm32f4_stdperiph_usart ${STM32F4_StdPeriphLib_usart_src})
add_library(stm32f4_stdperiph_wwdg ${STM32F4_StdPeriphLib_wwdg_src})

install(TARGETS stm32f4_stdperiph_misc
		stm32f4_stdperiph_adc
		stm32f4_stdperiph_can
		stm32f4_stdperiph_crc
		stm32f4_stdperiph_cryp
		stm32f4_stdperiph_dac
		stm32f4_stdperiph_dbgmcu
		stm32f4_stdperiph_dcmi
		stm32f4_stdperiph_dma
		stm32f4_stdperiph_exti
		stm32f4_stdperiph_flash
		stm32f4_stdperiph_fsmc
		stm32f4_stdperiph_gpio
		stm32f4_stdperiph_hash
		stm32f4_stdperiph_i2c
		stm32f4_stdperiph_iwdg
		stm32f4_stdperiph_pwr
		stm32f4_stdperiph_rcc
		stm32f4_stdperiph_rng
		stm32f4_stdperiph_rtc
		stm32f4_stdperiph_sdio
		stm32f4_stdperiph_spi
		stm32f4_stdperiph_syscfg
		stm32f4_stdperiph_tim
		stm32f4_stdperiph_usart
		stm32f4_stdperiph_wwdg
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES 
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

install(FILES 
    ${STM32F4_StdPeriphLib_DIR}/inc/misc.h
    RENAME
    stm32f4xx_misc.h
    DESTINATION
    ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_stdperiph
)

install(FILES
    ./FindSTM32F4_StdPeriphLib.cmake
    DESTINATION
    /usr/share/cmake-2.8/Modules/
)