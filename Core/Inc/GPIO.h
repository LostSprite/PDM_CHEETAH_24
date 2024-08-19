#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx_hal.h"

// Tipos de configuração GPIO (modos e pull)
typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT_PP,
    GPIO_OUTPUT_OD,
    GPIO_AF_PP,
    GPIO_AF_OD,
    GPIO_ANALOG
} GPIO_Mode;

typedef enum {
    GPIO_NO_PULL,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN
} GPIO_Pull;

void GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_Mode Mode, GPIO_Pull Pull);
void GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
GPIO_PinState GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif // GPIO_H
