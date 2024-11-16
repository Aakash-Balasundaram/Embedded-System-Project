#ifndef OLED_H
#define OLED_H

#include "stm32f4xx.h"

void OLED_Init(void);
void OLED_Command(uint8_t command);
void OLED_Clear(void);
void OLED_SetCursor(uint8_t x, uint8_t y);
void OLED_WriteChar(char ch);
void OLED_WriteString(char *str);
void OLED_DisplayEmoji(uint8_t x, uint8_t y, const uint8_t *emoji);

#endif // OLED_H
