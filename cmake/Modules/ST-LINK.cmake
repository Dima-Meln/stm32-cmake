include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CMSIS ARGSS) 

function(stlink_flash ARGSS)
    CONFIGURE_FILE(${CMSIS_LINKER_SCRIPT} ${CMAKE_CURRENT_BINARY_DIR}/stm32_flash.ld)
endfunction(STM32_SET_PARAMS)