#ifndef ADC_H
#define ADC_H

#include "stm32f103xb.h"

// Prototipos das funções
void ADC_Init(ADC_TypeDef* _hadc);
uint16_t ADC_Read(ADC_TypeDef* _hadc, uint8_t channel);

#endif // ADC_H
