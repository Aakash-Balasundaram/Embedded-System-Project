#ifndef RTC_H
#define RTC_H

#include "stm32f4xx.h"
#include <stdio.h>

void RTC_Init(void);
void RTC_GetTime(char *timeStr);

#endif // RTC_H
