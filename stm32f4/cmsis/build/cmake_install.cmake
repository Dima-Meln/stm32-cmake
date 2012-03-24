# Install script for directory: /home/dima/projects/git/stm32-cmake/stm32f4/cmsis

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/dima/projects/git/stm32-cmake/stm32f4/cmsis/build/libstm32f4_cmsis.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/stm32f4xx.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/system_stm32f4xx.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/arm_common_tables.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/arm_math.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cm0.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cm3.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cm4.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cm4_simd.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cmInstr.h;/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis/core_cmFunc.h")
FILE(INSTALL DESTINATION "/home/dima/apps/CodeBench/arm-none-eabi/include/stm32f4_cmsis" TYPE FILE FILES
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Device/ST/STM32F4xx/Include/stm32f4xx.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Device/ST/STM32F4xx/Include/system_stm32f4xx.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/arm_common_tables.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/arm_math.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cm0.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cm3.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cm4.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cm4_simd.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cmInstr.h"
    "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Include/core_cmFunc.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/dima/apps/CodeBench/arm-none-eabi/lib/stm32_flash.ld")
FILE(INSTALL DESTINATION "/home/dima/apps/CodeBench/arm-none-eabi/lib" TYPE FILE FILES "/home/dima/projects/git/stm32-cmake/stm32f4/cmsis/./stm32_flash.ld")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/home/dima/apps/CodeBench/arm-none-eabi/src/startup_stm32f4xx.s")
FILE(INSTALL DESTINATION "/home/dima/apps/CodeBench/arm-none-eabi/src" TYPE FILE FILES "/home/dima/projects/git/stm32-cmake/stm32f4/libs/CMSIS//Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f4xx.s")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/share/cmake-2.8/Modules/FindSTM32F4_CMSIS.cmake")
FILE(INSTALL DESTINATION "/usr/share/cmake-2.8/Modules" TYPE FILE FILES "/home/dima/projects/git/stm32-cmake/stm32f4/cmsis/FindSTM32F4_CMSIS.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
ELSE(CMAKE_INSTALL_COMPONENT)
  SET(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
ENDIF(CMAKE_INSTALL_COMPONENT)

FILE(WRITE "/home/dima/projects/git/stm32-cmake/stm32f4/cmsis/build/${CMAKE_INSTALL_MANIFEST}" "")
FOREACH(file ${CMAKE_INSTALL_MANIFEST_FILES})
  FILE(APPEND "/home/dima/projects/git/stm32-cmake/stm32f4/cmsis/build/${CMAKE_INSTALL_MANIFEST}" "${file}\n")
ENDFOREACH(file)
