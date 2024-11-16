#include "oled.h"
#include "i2c.h"
#include "fonts.h"

void OLED_Init(void) {
    OLED_Command(0xAE); // Display OFF
    OLED_Command(0xD5); // Set display clock divide
    OLED_Command(0x80);
    OLED_Command(0xA8); // Set multiplex
    OLED_Command(0x3F);
    OLED_Command(0xD3); // Display offset
    OLED_Command(0x00);
    OLED_Command(0x40 | 0x0); // Start line
    OLED_Command(0x8D); // Charge pump
    OLED_Command(0x14);
    OLED_Command(0x20); // Memory addressing
    OLED_Command(0x00);
    OLED_Command(0xA1); // Segment re-map
    OLED_Command(0xC8); // COM scan direction
    OLED_Command(0xDA); // COM pins
    OLED_Command(0x12);
    OLED_Command(0x81); // Contrast
    OLED_Command(0xCF);
    OLED_Command(0xD9); // Pre-charge
    OLED_Command(0xF1);
    OLED_Command(0xDB); // VCOM detect
    OLED_Command(0x40);
    OLED_Command(0xA4); // Entire display ON
    OLED_Command(0xA6); // Normal display
    OLED_Command(0xAF); // Display ON
}

void OLED_Command(uint8_t command) {
    I2C1_Write(OLED_I2C_ADDRESS, 0x00, command);
}

void OLED_Clear(void) {
    for (uint8_t page = 0; page < 8; page++) {
        OLED_Command(0xB0 + page);
        OLED_Command(0x00);
        OLED_Command(0x10);
        for (uint8_t col = 0; col < 128; col++) {
            I2C1_Write(OLED_I2C_ADDRESS, 0x40, 0x00);
        }
    }
}

void OLED_WriteChar(char ch) {
    for (uint8_t i = 0; i < 4; i++) {
        I2C1_Write(OLED_I2C_ADDRESS, 0x40, font4x6[ch - 32][i]);
    }
}

void OLED_WriteString(char *str) {
    while (*str) {
        OLED_WriteChar(*str++);
    }
}

void OLED_DisplayEmoji(uint8_t x, uint8_t y, const uint8_t *emoji) {
    OLED_SetCursor(x, y);
    for (uint8_t i = 0; i < 8; i++) {
        I2C1_Write(OLED_I2C_ADDRESS, 0x40, emoji[i]);
    }
}
