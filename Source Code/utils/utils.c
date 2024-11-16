#include "utils.h"

void delay(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 16000; i++) {
        __NOP(); // Perform no operation (loop-based delay)
    }
}

void SystemClock_Config(void) {
    RCC->CR |= RCC_CR_HSEON; // Enable HSE (High-Speed External clock)
    while (!(RCC->CR & RCC_CR_HSERDY)); // Wait until HSE is ready

    RCC->PLLCFGR = (RCC_PLLCFGR_PLLSRC_HSE | (4 << RCC_PLLCFGR_PLLM_Pos) |
                    (168 << RCC_PLLCFGR_PLLN_Pos) | (0 << RCC_PLLCFGR_PLLP_Pos) |
                    (7 << RCC_PLLCFGR_PLLQ_Pos));
    RCC->CR |= RCC_CR_PLLON; // Enable PLL
    while (!(RCC->CR & RCC_CR_PLLRDY)); // Wait until PLL is ready

    FLASH->ACR |= FLASH_ACR_LATENCY_5WS; // Configure Flash latency
    RCC->CFGR |= RCC_CFGR_SW_PLL;        // Set PLL as system clock
    while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)); // Wait for PLL to be used
}
