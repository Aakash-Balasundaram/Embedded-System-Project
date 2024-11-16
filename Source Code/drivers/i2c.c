#include "i2c.h"

void I2C1_Init(void) {
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

    GPIOB->MODER |= GPIO_MODER_MODER6_1 | GPIO_MODER_MODER7_1;
    GPIOB->OTYPER |= GPIO_OTYPER_OT6 | GPIO_OTYPER_OT7;
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6 | GPIO_OSPEEDER_OSPEEDR7;
    GPIOB->PUPDR |= GPIO_PUPDR_PUPDR6_0 | GPIO_PUPDR_PUPDR7_0;
    GPIOB->AFR[0] |= (4 << GPIO_AFRL_AFSEL6_Pos) | (4 << GPIO_AFRL_AFSEL7_Pos);

    I2C1->CR1 = I2C_CR1_SWRST;
    I2C1->CR1 = 0;
    I2C1->CR2 = 16;
    I2C1->CCR = 80;
    I2C1->TRISE = 17;
    I2C1->CR1 |= I2C_CR1_PE;
}

void I2C1_Write(uint8_t address, uint8_t mode, uint8_t data) {
    while (I2C1->SR2 & I2C_SR2_BUSY);

    I2C1->CR1 |= I2C_CR1_START;
    while (!(I2C1->SR1 & I2C_SR1_SB));

    I2C1->DR = address;
    while (!(I2C1->SR1 & I2C_SR1_ADDR));
    (void)I2C1->SR2;

    I2C1->DR = mode;
    while (!(I2C1->SR1 & I2C_SR1_BTF));

    I2C1->DR = data;
    while (!(I2C1->SR1 & I2C_SR1_BTF));

    I2C1->CR1 |= I2C_CR1_STOP;
}
