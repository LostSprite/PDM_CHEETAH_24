#include "led.h"

void LED_Init(LED_TypeDef* led, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    // Inicializa a estrutura LED
    led->GPIOx = GPIOx;
    led->GPIO_Pin = GPIO_Pin;

    // Configura o pino GPIO como saída push-pull sem pull-up/pull-down
    GPIO_Init(GPIOx, GPIO_Pin, GPIO_OUTPUT_PP, GPIO_NO_PULL);
}

void LED_On(LED_TypeDef* led) {
    // Define o pino GPIO para acender o LED
    GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_SET);
}

void LED_Off(LED_TypeDef* led) {
    // Reseta o pino GPIO para apagar o LED
    GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_RESET);
}

void LED_Toggle(LED_TypeDef* led) {
    // Alterna o estado do pino GPIO
    if (GPIO_ReadPin(led->GPIOx, led->GPIO_Pin) == GPIO_PIN_SET) {
        GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_RESET);
    } else {
        GPIO_WritePin(led->GPIOx, led->GPIO_Pin, GPIO_PIN_SET);
    }
}
