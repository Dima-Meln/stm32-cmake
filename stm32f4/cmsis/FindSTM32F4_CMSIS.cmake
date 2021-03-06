SET(TOOLCHAIN_PREFIX /home/dima/apps/CodeBench)

SET(STM32F4_CMSIS_INCLUDE_DIR ${TOOLCHAIN_PREFIX}/arm-none-eabi/include/stm32f4_cmsis/)
SET(STM32F4_CMSIS_LIBRARIES stm32f4_cmsis)
SET(STM32F4_CMSIS_STARTUP_SOURCE ${TOOLCHAIN_PREFIX}/arm-none-eabi/src/startup_stm32f4xx.s)
SET(STM32F4_CMSIS_LINKER_SCRIPT ${TOOLCHAIN_PREFIX}/arm-none-eabi/lib/stm32_flash.ld)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CMSIS DEFAULT_MSG 
				  STM32F4_CMSIS_LIBRARIES 
				  STM32F4_CMSIS_INCLUDE_DIR 
				  STM32F4_CMSIS_STARTUP_SOURCE 
				  STM32F4_CMSIS_LINKER_SCRIPT
) 

#FUNCTION(STM32_SET_PARAMS FLASH_SIZE RAM_SIZE STACK_ADDRESS MIN_STACK_SIZE MIN_HEAP_SIZE EXT_RAM_SIZE FLASH_ORIGIN RAM_ORIGIN EXT_RAM_ORIGIN)
#    CONFIGURE_FILE(${CMSIS_LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/stm32_flash.ld)
#ENDFUNCTION(STM32_SET_PARAMS)

#FUNCTION(STM32_SET_PARAMS FLASH_SIZE RAM_SIZE STACK_ADDRESS)
#    SET(STACK_ADDRESS ${STACK_ADDRESS})
#    SET(FLASH_SIZE ${FLASH_SIZE})
#    SET(RAM_SIZE ${RAM_SIZE})
#    SET(MIN_STACK_SIZE "0x200")
#    SET(MIN_HEAP_SIZE "0")
#    SET(EXT_RAM_SIZE "0K")
#    SET(FLASH_ORIGIN "0x08000000")
#    SET(RAM_ORIGIN "0x20000000")
#    SET(EXT_RAM_ORIGIN "0x60000000")
#    CONFIGURE_FILE(${CMSIS_LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/stm32_flash.ld)
#ENDFUNCTION(STM32_SET_PARAMS)