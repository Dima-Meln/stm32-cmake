/**
  @page I2S_DataExchangePolling I2S full duplex communication example using polling mode 
  
  @verbatim
  ******************** (C) COPYRIGHT 2011 STMicroelectronics *******************
  * @file    I2S/I2S_TwoBoards/DataExchangePolling/readme.txt 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    30-September-2011
  * @brief   Description of the I2S full duplex communication example.
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Example Description 

This example provides a small application to show how to configure the I2S for
full duplex communication, based on polling mode and through I2S firmware
library. 

- Hardware Description

To use this example, you need to load it on two STM32 boards (let's call them 
BoardA and BoardB) then connect these two boards through I2S lines and GND.
In the firmware example uncomment the dedicated line in the main.h file to use
the I2S peripheral as STM32 Master device or as STM32 Slave device.

@verbatim
*------------------------------------------------------------------------------*
|                BoardA                                 BoardB                 |
|         ____________________                   ____________________          |
|        |     __________     |                 |     __________     |         |
|        |    |          |____|_______WS________|____|          |    |         |
|        |    |I2S Master|____|_______CK________|____|I2S Slave |    |         |
|        |    |    TX    |____|_______SD________|____|    RX    |    |         |
|        |    |__________|    |                 |    |__________|    |         |
|        |    | I2S_ext  |    |                 |    | I2S_ext  |    |         |
|        |    | Slave RX |____|_____ext_SD______|____| Slave TX |    |         |
|        |    |__________|    |                 |    |__________|    |         |
|        |                    |                 |                    |         |
|        |  O LD1             |                 |  O LD1             |         |
|        |  O LD2             |                 |  O LD2             |         |
|        |  O LD3             |                 |  O LD3             |         |
|        |  O LD4             |                 |  O LD4             |         |
|        |                    |                 |                    |         |
|        |             GND O--|-----------------|--O GND             |         |
|        |____________________|                 |____________________|         |
|                                                                              |
|                                                                              |
*------------------------------------------------------------------------------*
@endverbatim

@note The connection between the pins should use a short wires and a common Ground.

- Software Description
In this Example, the I2S full duplex interface is based on the I2S2 peripheral with 
an extra instance called I2S_ext used only for full duplex communication and can
operate only in Slave Mode.

Both I2Ss are configured as below:
  - Audio Frequency: 8 KHz
  - Standard: Phillips
  - MCLK Output: disabled
  - CPOL: Low
  - Data Format: 16b

In master board, I2S2 and I2S2_ext are enabled so I2S2 can deliver CK and WS to I2S2_ext.
The I2S2 peripheral is configured as Master Transmitter and I2S2_ext is configured 
as Slave Receiver. Whereas in Slave Board, the I2S2 peripheral is configured as Slave
Receiver ans I2S2_ext is configured as Slave Transmitter. 

- The Slave must be launched before the Master.
- The Master start the communication by sending TxMasterBuffer buffer through SD pin
  in the same time he receive a buffer through ext_SD pin, which is stored in RxMasterBuffer. 
- The Slave Start the communication when the clock is already available on CK pin
  the Buffer received from master through SD pin,is stored in RxSlaveBuffer, in the 
  same time the TxSlaveBuffer buffer is transmitted through ext_SD pin. 

- In Master Board, after the Communication end, if the received buffer is correct 
  the LED2 and LED4  turns ON.
- In Slave Board, after the Communication end, if the received buffer is correct 
  the LED 3 turns ON.

In both boards, the SysTick is configured to generate interrupt each 10ms. A dedicated  
counter inside the SysTick ISR is used to toggle LED1 each 100ms indicating that the 
firmware is running.


@par Directory contents 

  - I2S/I2S_TwoBoards/DataExchangePolling/stm32f4xx_conf.h    Library Configuration file
  - I2S/I2S_TwoBoards/DataExchangePolling/stm32f4xx_it.c      Interrupt handlers
  - I2S/I2S_TwoBoards/DataExchangePolling/stm32f4xx_it.h      Interrupt handlers header file
  - I2S/I2S_TwoBoards/DataExchangePolling/main.c              Main program
  - I2S/I2S_TwoBoards/DataExchangePolling/main.h              Main program header file
  - I2S/I2S_TwoBoards/DataExchangePolling/system_stm32f4xx.c  STM32F4xx system source file
  
@note The "system_stm32f4xx.c" is generated by an automatic clock configuration 
      tool and can be easily customized to your own configuration. 
      To select different clock setup, use the "STM32F4xx_Clock_Configuration_V1.0.0.xls" 
      provided with the AN3988 package available on <a href="http://www.st.com/internet/mcu/family/141.jsp">  ST Microcontrollers </a>


@par Hardware and Software environment

  - This example runs on STM32F4xx Devices.
  
  - This example has been tested with STM324xG-EVAL RevB (with no additional
    hardware), and can be easily tailored to any other development board.

  - STM324xG-EVAL Set-up 
    - Use LED1, LED2, LED3 and LED4 connected respectively to PG.06, PG.08, PI.09
      and PC.07 pins
    - Use the Joystick Push Button
    - Connect BoardA I2S2_WS pin (PB12) to BoardB I2S2_WS pin (PB12)
    - Connect BoardA I2S2_CK pin (PB13) to BoardB I2S2_CK pin (PB13) 
    - Connect BoardA I2S2_SD pin (PC3) to BoardB I2S2_SD pin (PC3)
    - Connect BoardA I2S2ext_SD pin (PI2) to BoardB I2S2ext_SD pin (PI2)


@par How to use it ? 

In order to make the program work, you must do the following :
 - Copy all source files from this example folder to the template folder under
   Project\STM32F4xx_StdPeriph_Templates
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example
    
 * <h3><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h3>
 */
