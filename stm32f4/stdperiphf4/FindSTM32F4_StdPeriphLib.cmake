set(TOOLCHAIN_PREFIX /home/dima/apps/CodeBench)

set(STM32F4_StdPeriphLib_INCLUDE_DIR ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_stdperiph/)

set(STM32F4_StdPeriphLib_misc_lib stm32f4_stdperiph_misc)
set(STM32F4_StdPeriphLib_adc_lib stm32f4_stdperiph_adc)
set(STM32F4_StdPeriphLib_can_lib stm32f4_stdperiph_can)
set(STM32F4_StdPeriphLib_crc_lib stm32f4_stdperiph_crc)
set(STM32F4_StdPeriphLib_cryp_lib stm32f4_stdperiph_cryp)
set(STM32F4_StdPeriphLib_dac_lib stm32f4_stdperiph_dac)
set(STM32F4_StdPeriphLib_dbgmcu_lib stm32f4_stdperiph_dbgmcu)
set(STM32F4_StdPeriphLib_dcmi_lib stm32f4_stdperiph_dcmi)
set(STM32F4_StdPeriphLib_dma_lib stm32f4_stdperiph_dma)
set(STM32F4_StdPeriphLib_exti_lib stm32f4_stdperiph_exti)
set(STM32F4_StdPeriphLib_flash_lib stm32f4_stdperiph_flash)
set(STM32F4_StdPeriphLib_fsmc_lib stm32f4_stdperiph_fsmc)
set(STM32F4_StdPeriphLib_gpio_lib stm32f4_stdperiph_gpio)
set(STM32F4_StdPeriphLib_hash_lib stm32f4_stdperiph_hash)
set(STM32F4_StdPeriphLib_i2c_lib stm32f4_stdperiph_i2c)
set(STM32F4_StdPeriphLib_iwdg_lib stm32f4_stdperiph_iwdg)
set(STM32F4_StdPeriphLib_pwr_lib stm32f4_stdperiph_pwr)
set(STM32F4_StdPeriphLib_rcc_lib stm32f4_stdperiph_rcc)
set(STM32F4_StdPeriphLib_rng_lib stm32f4_stdperiph_rng)
set(STM32F4_StdPeriphLib_rtc_lib stm32f4_stdperiph_rtc)
set(STM32F4_StdPeriphLib_sdio_lib stm32f4_stdperiph_sdio)
set(STM32F4_StdPeriphLib_spi_lib stm32f4_stdperiph_spi)
set(STM32F4_StdPeriphLib_syscfg_lib stm32f4_stdperiph_syscfg)
set(STM32F4_StdPeriphLib_tim_lib stm32f4_stdperiph_tim)
set(STM32F4_StdPeriphLib_usart_lib stm32f4_stdperiph_usart)
set(STM32F4_StdPeriphLib_wwdg_lib stm32f4_stdperiph_wwdg)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DUSE_STDPERIPH_DRIVER")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_STDPERIPH_DRIVER")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(STM32F4_StdPeriphLib 
				  DEFAULT_MSG 
				  STM32F4_StdPeriphLib_INCLUDE_DIR
				  STM32F4_StdPeriphLib_misc_lib
				  STM32F4_StdPeriphLib_adc_lib
				  STM32F4_StdPeriphLib_can_lib
				  STM32F4_StdPeriphLib_crc_lib
				  STM32F4_StdPeriphLib_cryp_lib
				  STM32F4_StdPeriphLib_dac_lib
				  STM32F4_StdPeriphLib_dbgmcu_lib
				  STM32F4_StdPeriphLib_dcmi_lib
				  STM32F4_StdPeriphLib_dma_lib
				  STM32F4_StdPeriphLib_exti_lib
				  STM32F4_StdPeriphLib_flash_lib
				  STM32F4_StdPeriphLib_fsmc_lib
				  STM32F4_StdPeriphLib_gpio_lib
				  STM32F4_StdPeriphLib_hash_lib
				  STM32F4_StdPeriphLib_i2c_lib
				  STM32F4_StdPeriphLib_iwdg_lib
				  STM32F4_StdPeriphLib_pwr_lib
				  STM32F4_StdPeriphLib_rcc_lib
				  STM32F4_StdPeriphLib_rng_lib
				  STM32F4_StdPeriphLib_rtc_lib
				  STM32F4_StdPeriphLib_sdio_lib
				  STM32F4_StdPeriphLib_spi_lib
				  STM32F4_StdPeriphLib_syscfg_lib
				  STM32F4_StdPeriphLib_tim_lib
				  STM32F4_StdPeriphLib_usart_lib
				  STM32F4_StdPeriphLib_wwdg_lib
) 
