#include "gpio.h"

void GPIO_Init(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_Mode Mode, GPIO_Pull Pull) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Habilitar o clock do GPIOx
    if (GPIOx == GPIOA) {
        __HAL_RCC_GPIOA_CLK_ENABLE();
    } else if (GPIOx == GPIOB) {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    } else if (GPIOx == GPIOC) {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    } else if (GPIOx == GPIOD) {
        __HAL_RCC_GPIOD_CLK_ENABLE();
    } else if (GPIOx == GPIOE) {
        __HAL_RCC_GPIOE_CLK_ENABLE();
    }

    // Configurar o pino
    GPIO_InitStruct.Pin = GPIO_Pin;

    switch (Mode) {
        case GPIO_INPUT:
            GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
            break;
        case GPIO_OUTPUT_PP:
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;
        case GPIO_OUTPUT_OD:
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;
        case GPIO_AF_PP:
            GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;
        case GPIO_AF_OD:
            GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
            break;
        case GPIO_ANALOG:
            GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
            break;
    }

    switch (Pull) {
        case GPIO_NO_PULL:
            GPIO_InitStruct.Pull = GPIO_NOPULL;
            break;
        case GPIO_PULL_UP:
            GPIO_InitStruct.Pull = GPIO_PULLUP;
            break;
        case GPIO_PULL_DOWN:
            GPIO_InitStruct.Pull = GPIO_PULLDOWN;
            break;
    }

    HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

GPIO_PinState GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}
