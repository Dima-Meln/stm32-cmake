#include <stm32f4xx_tim.h>

#include "stm32f4xx_it.h"

#include "control.h"

Contjrol contrl;
void TIM6_DAC_IRQHandler(void ) {
  if (TIM_GetITStatus(TIM6, TIM_IT_Update) != RESET) {
    TIM_ClearITPendingBit(TIM6, TIM_IT_Update);
    contrl.setState(contrl.getNextState());
  }
}