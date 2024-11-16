#include "stm32f4xx.h"
#include "dht11.h"

// Function to initialize DHT11 (PA11 as input/output)
void DHT11_Init(void)
{
    // Set PA11 as output for DHT11 communication
    GPIOA->MODER &= ~(0x3 << (2 * DHT11_PIN));  // Clear mode bits
    GPIOA->MODER |= (0x1 << (2 * DHT11_PIN));   // Set PA11 to output mode
    GPIOA->OTYPER |= (0x1 << DHT11_PIN);        // Set open-drain for PA11
}

// Function to read temperature and humidity from DHT11
uint8_t DHT11_ReadData(uint8_t *temperature, uint8_t *humidity)
{
    uint8_t data[5] = {0};  // Array to store the 5 bytes received
    
    // 1- Start signal (MCU sends low signal for 18ms)
    GPIOA->ODR &= ~(1 << DHT11_PIN);  // Pull PA11 low
    delay_ms(18);
    GPIOA->ODR |= (1 << DHT11_PIN);   // Pull PA11 high
    delay_us(20);
    
    // 2- Switch PA11 to input mode to receive response
    GPIOA->MODER &= ~(0x3 << (2 * DHT11_PIN));  // Set PA11 to input mode

    // Wait for the DHT11 to pull the line low
    uint32_t time_out = 0;
    while (GPIOA->IDR & (1 << DHT11_PIN))
    {
        if (time_out++ > 1000) return 1;  // Timeout error
    }
    
    // Wait for the DHT11 response signal
    while (!(GPIOA->IDR & (1 << DHT11_PIN)));  // Wait for pin to go high
    while (GPIOA->IDR & (1 << DHT11_PIN));     // Wait for pin to go low
    
    // Read 40 bits (5 bytes) from the sensor
    for (uint8_t i = 0; i < 40; i++)
    {
        // Wait for the line to go high
        while (!(GPIOA->IDR & (1 << DHT11_PIN)));
        
        // Measure how long the line stays high
        uint32_t length = 0;
        while (GPIOA->IDR & (1 << DHT11_PIN))
        {
            delay_us(1);
            length++;
        }
        
        // If the high signal was long (>50us), it is a '1'
        if (length > 50)
        {
            data[i / 8] |= (1 << (7 - (i % 8)));
        }
    }
    
    // 3- Check checksum
    if (data[0] + data[1] + data[2] + data[3] != data[4])
    {
        return 2;  // Checksum error
    }
    
    // 4- Extract temperature and humidity
    *humidity = data[0];
    *temperature = data[2];
    
    return 0;  // Success
}

// Millisecond delay function
void delay_ms(uint32_t ms)
{
    for (uint32_t i = 0; i < ms * 1000; i++) 
    {
        __asm("NOP");  // Simple no-operation loop
    }
}

// Microsecond delay function
void delay_us(uint32_t us)
{
    for (uint32_t i = 0; i < us * 10; i++) 
    {
        __asm("NOP");  // Simple no-operation loop
    }
}
