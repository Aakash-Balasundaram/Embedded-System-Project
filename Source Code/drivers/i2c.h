#ifndef I2C_H
#define I2C_H

#include "stm32f4xx.h"

void I2C1_Init(void);
void I2C1_Write(uint8_t address, uint8_t mode, uint8_t data);

#endif // I2C_H
