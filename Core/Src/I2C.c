#include "i2c.h"

I2C_HandleTypeDef hi2c1;

void I2C_Init(void) {
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

    if (HAL_I2C_Init(&hi2c1) != HAL_OK) {
        // Inicialização falhou
        Error_Handler();
    }
}

HAL_StatusTypeDef I2C_Write(uint16_t devAddress, uint16_t memAddress, uint8_t* data, uint16_t size) {
    uint8_t memAddressArr[2] = {memAddress >> 8, memAddress & 0xFF};
    return HAL_I2C_Mem_Write(&hi2c1, devAddress << 1, memAddress, I2C_MEMADD_SIZE_16BIT, data, size, HAL_MAX_DELAY);
}

HAL_StatusTypeDef I2C_Read(uint16_t devAddress, uint16_t memAddress, uint8_t* data, uint16_t size) {
    return HAL_I2C_Mem_Read(&hi2c1, devAddress << 1, memAddress, I2C_MEMADD_SIZE_16BIT, data, size, HAL_MAX_DELAY);
}
