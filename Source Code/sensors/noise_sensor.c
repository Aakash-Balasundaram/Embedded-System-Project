#include "stm32f4xx.h"
#include "noise_sensor.h"

// Function to initialize Noise Sensor (Assuming analog input on PA0)
void NoiseSensor_Init(void)
{
    // Enable clock for GPIOA
    RCC->AHB1ENR |= (1U << 0);
    
    // Configure PA0 as analog mode (for ADC)
    GPIOA->MODER |= (0x3 << (2 * 0));  // Set PA0 to analog mode
}

// Function to read noise level from the sensor using ADC
uint16_t NoiseSensor_Read(void)
{
    // Start ADC conversion (assuming ADC1 is used)
    ADC1->CR2 |= ADC_CR2_SWSTART;  // Start conversion
    while (!(ADC1->SR & ADC_SR_EOC));  // Wait for conversion to finish
    return ADC1->DR;  // Return the result
}
