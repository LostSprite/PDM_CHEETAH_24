#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "main.h"

void initEEPROM(I2C_HandleTypeDef *_hi2c);

uint8_t readEEPROM(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint8_t size, uint16_t address);
uint8_t writeEEPROM(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint8_t size, uint16_t address);

#endif /* INC_EEPROM_H_ */
