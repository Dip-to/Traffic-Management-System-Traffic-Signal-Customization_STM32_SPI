#include "stm32f446xx.h"
#include "stm32f4xx.h"
#include "global.h"
#include "CLOCK.h"
#include "USART.h"
#include "GPIO.h"
#include "SYS_INIT.h"

void I2C2_EV_IRQHandler(void);

void USART2_IRQHandler(void);
void SPI3_IRQHandler(void);

uint8_t parse_string(char* , int* );