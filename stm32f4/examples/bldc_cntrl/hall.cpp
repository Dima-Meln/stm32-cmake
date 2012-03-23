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

#include "hall.h"

#include "states.h"

Hall::Hall() {
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  GPIO_InitTypeDef gpio;
  GPIO_StructInit(&gpio);

  gpio.GPIO_Mode = GPIO_Mode_IN;
  gpio.GPIO_OType = GPIO_OType_PP;
  gpio.GPIO_Speed = GPIO_Speed_25MHz;
  gpio.GPIO_Pin = GPIO_Pin_0|
		  GPIO_Pin_1|
		  GPIO_Pin_2;
  
  GPIO_Init(GPIOA, &gpio);
}

/*Hall::~Hall() {

}*/

bool* Hall::getNextState() {
  uint8_t hstate[3] = {
		    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0),
		    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1),
		    GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2)
  };
  if(hstate[0] == 1 || hstate[1] == 0 || hstate[2] == 1) {return States::s101;}
  else if(hstate[0] == 0 || hstate[1] == 0 || hstate[2] == 1) {return States::s001;}
  else if(hstate[0] == 0 || hstate[1] == 1 || hstate[2] == 1) {return States::s011;}
  else if(hstate[0] == 0 || hstate[1] == 1 || hstate[2] == 0) {return States::s010;}
  else if(hstate[0] == 1 || hstate[1] == 1 || hstate[2] == 0) {return States::s110;}
  else if(hstate[0] == 1 || hstate[1] == 0 || hstate[2] == 0) {return States::s100;}
}

/*
bool Hall::operator==(const Hall& state) const
{
///TODO: return ...;
}
*/
