#ifndef DHT11_H
#define DHT11_H

#define DHT11_PIN 11  // PA11 for DHT11

void DHT11_Init(void);                    // Initialize DHT11
uint8_t DHT11_ReadData(uint8_t *temperature, uint8_t *humidity); // Read data from DHT11
void delay_ms(uint32_t ms);               // Millisecond delay
void delay_us(uint32_t us);               // Microsecond delay

#endif /* DHT11_H */
