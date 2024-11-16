#include "rtc.h"

void RTC_Init(void) {
    // Basic RTC initialization assuming the clock source is set up.
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;
    RCC->BDCR |= RCC_BDCR_RTCEN; // Enable RTC clock
    RTC->WPR = 0xCA;            // Disable write protection
    RTC->WPR = 0x53;

    RTC->ISR |= RTC_ISR_INIT;   // Enter initialization mode
    while (!(RTC->ISR & RTC_ISR_INITF));

    RTC->PRER = (127 << 16) | 255; // Configure prescaler
    RTC->TR = 0x000000;            // Set time to 00:00:00
    RTC->ISR &= ~RTC_ISR_INIT;     // Exit initialization mode

    RTC->WPR = 0xFF; // Enable write protection
}

void RTC_GetTime(char *timeStr) {
    uint32_t time = RTC->TR;

    uint8_t hours = ((time >> 16) & 0x3F);
    uint8_t minutes = ((time >> 8) & 0x7F);
    uint8_t seconds = (time & 0x7F);

    snprintf(timeStr, 10, "%02d:%02d:%02d", hours, minutes, seconds);
}
