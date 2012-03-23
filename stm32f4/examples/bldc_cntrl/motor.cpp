/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2012  <copyright holder> <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stm32f4xx_rcc.h>
#include <stm32f4xx_gpio.h>

#include "motor.h"

Motor::Motor() {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);

  gpio.GPIO_Mode = GPIO_Mode_OUT;
  gpio.GPIO_OType = GPIO_OType_PP;
  gpio.GPIO_Speed = GPIO_Speed_25MHz;
  gpio.GPIO_Pin = GPIO_Pin_0|
		  GPIO_Pin_1|
		  GPIO_Pin_2|
		  GPIO_Pin_3|
		  GPIO_Pin_4|
		  GPIO_Pin_5;
  
  GPIO_Init(GPIOC, &gpio);
}

void Motor::setState(bool state[6]) {
  //reseting bits
  GPIO_ResetBits(GPIOC, GPIO_Pin_0);
  GPIO_ResetBits(GPIOC, GPIO_Pin_1);
  GPIO_ResetBits(GPIOC, GPIO_Pin_2);
  GPIO_ResetBits(GPIOC, GPIO_Pin_3);
  GPIO_ResetBits(GPIOC, GPIO_Pin_4);
  GPIO_ResetBits(GPIOC, GPIO_Pin_5);
  
  if(state[0]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_0);}
  else if(state[1]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_1);}
  else if(state[2]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_2);}
  else if(state[3]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_3);}
  else if(state[4]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_4);}
  else if(state[5]==1) {GPIO_SetBits(GPIOC, GPIO_Pin_5);}
}
