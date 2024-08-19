#include "adc.h"

// Função de inicialização do ADC
void ADC_Init(ADC_TypeDef* _hadc) {
    // Habilitar o clock para o ADC
    if (_hadc == ADC1) {
        RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
    } else if (_hadc == ADC2) {
        RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;
    }

    // Configurar o ADC
    _hadc->CR2 |= ADC_CR2_ADON; // Ligar o ADC

    // Esperar Tstab (estabilização do ADC)
    for (volatile int i = 0; i < 1000; i++);

    // Calibrar o ADC
    _hadc->CR2 |= ADC_CR2_CAL;
    while (_hadc->CR2 & ADC_CR2_CAL); // Esperar a calibração terminar

    // Configurar a divisão do clock para o ADC (Opcional: ajustar conforme necessário)
    RCC->CFGR &= ~RCC_CFGR_ADCPRE;
    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV6; // PCLK2 dividido por 6 para ADC clock

    // Configurar o modo de scan, alinhamento e interrupções (se necessário)
    _hadc->CR1 &= ~ADC_CR1_SCAN; // Modo single channel
    _hadc->CR2 &= ~ADC_CR2_ALIGN; // Alinhamento à direita
}

// Função para ler o valor do ADC
uint16_t ADC_Read(ADC_TypeDef* _hadc, uint8_t channel) {
    // Configurar o canal
	_hadc->SQR3 = channel;

    // Iniciar a conversão
	_hadc->CR2 |= ADC_CR2_ADON;

    // Esperar a conversão terminar
    while (!(_hadc->SR & ADC_SR_EOC));

    // Ler o valor convertido
    uint16_t result = _hadc->DR;

    return result;
}
