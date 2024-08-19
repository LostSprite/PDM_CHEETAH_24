#include "EEPROM.h"

const uint16_t ADDRESS_EEPROM =  0b10100000;

uint32_t lstTimeEEPROM = 0;

I2C_HandleTypeDef *hi2c;

void initEEPROM(I2C_HandleTypeDef *_hi2c){
	hi2c =  _hi2c;

	lstTimeEEPROM = HAL_GetTick();
}


uint8_t readEEPROM(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint8_t size, uint16_t address){
	HAL_StatusTypeDef status;

	while(HAL_GetTick() - lstTimeEEPROM < 5){};

	uint8_t adr[2];
	adr[0] = address >> 8;
	adr[1] = address &0xFF;

	status = HAL_I2C_Master_Transmit(hi2c, ADDRESS_EEPROM, adr, 2,1000);
	if(status == HAL_OK){
		status = HAL_I2C_Master_Receive(hi2c,  ADDRESS_EEPROM, pData, size,1000);
	}

	lstTimeEEPROM = HAL_GetTick();
	return status == HAL_OK ? 1 : 0;
}

uint8_t writeEEPROM(I2C_HandleTypeDef *hi2c, uint8_t *pData, uint8_t size, uint16_t address){

	HAL_StatusTypeDef status;

	while(HAL_GetTick() - lstTimeEEPROM < 5){};

	uint8_t data[size+2];
	data[0] = address >> 8;
	data[1] = address &0xFF;

	for(uint8_t i = 0; i < size; i++){
		data[i+2] = pData[i];
	}

	status = HAL_I2C_Master_Transmit(hi2c,ADDRESS_EEPROM, data, size+2,1000);

	lstTimeEEPROM = HAL_GetTick();

	return status == HAL_OK ? 1 : 0;

}
