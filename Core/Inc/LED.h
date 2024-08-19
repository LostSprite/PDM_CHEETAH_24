#ifndef LED_H
#define LED_H

#include "gpio.h"

// Define uma estrutura para representar um LED
typedef struct {
    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_Pin;
} LED_TypeDef;

void LED_Init(LED_TypeDef* led, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void LED_On(LED_TypeDef* led);
void LED_Off(LED_TypeDef* led);
void LED_Toggle(LED_TypeDef* led);

#endif // LED_H
