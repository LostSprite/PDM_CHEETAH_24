#ifndef I2C_H
#define I2C_H

#include "stm32f1xx_hal.h"

void I2C_Init(void);
HAL_StatusTypeDef I2C_Write(uint16_t devAddress, uint16_t memAddress, uint8_t* data, uint16_t size);
HAL_StatusTypeDef I2C_Read(uint16_t devAddress, uint16_t memAddress, uint8_t* data, uint16_t size);

#endif // I2C_H
