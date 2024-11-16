#include "sensors.h"
#include <stdlib.h> // For rand()

float generateTemperature(void) {
    return (rand() % 401) / 10.0 - 20.0; // Simulated temp: -20.0°C to 20.0°C
}

float generateHumidity(void) {
    return (rand() % 101); // Simulated humidity: 0% to 100%
}

float generateNoise(void) {
    return (rand() % 801) / 10.0 + 20.0; // Simulated noise: 20.0 dB to 100.0 dB
}

void Sensors_Init(void)
{
    DHT11_Init();        // Initialize DHT11 sensor
    NoiseSensor_Init();  // Initialize Noise Sensor
}