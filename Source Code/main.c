#include "drivers/i2c.h"
#include "displays/oled.h"
#include "drivers/rtc.h"
#include "sensors/sensors.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h> // For srand()

int main(void) {
    srand(45); // Seed for generating random sensor data

    SystemClock_Config();
    I2C1_Init();
    OLED_Init();
    RTC_Init();

    char timeStr[10];
    char buffer[10];
    int counter = 0;

    while (1) {
        RTC_GetTime(timeStr);
        OLED_Clear();
        OLED_SetCursor(20, 0);
        OLED_WriteString("CURRENT TIME:");
        OLED_WriteString(timeStr);

        OLED_SetCursor(20, 2);
        if (counter == 0) {
            OLED_WriteString("TEMPERATURE: ");
            snprintf(buffer, sizeof(buffer), "%.2f.C", generateTemperature());
            OLED_WriteString(buffer);
        } else if (counter == 1) {
            OLED_WriteString("HUMIDITY: ");
            snprintf(buffer, sizeof(buffer), "%.2f", generateHumidity());
            OLED_WriteString(buffer);
        } else if (counter == 2) {
            OLED_WriteString("NOISE LEVEL: ");
            snprintf(buffer, sizeof(buffer), "%.2f DB", generateNoise());
            OLED_WriteString(buffer);
        }

        OLED_SetCursor(20, 5);
        OLED_DisplayEmoji(20, 5, smileyFaceEmoji);

        counter = (counter + 1) % 3;
        delay(1000);
    }
}
