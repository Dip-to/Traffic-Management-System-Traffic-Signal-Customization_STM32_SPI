#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f4xx.h"
#include "global.h"
#include "CLOCK.h"
#include "USART.h"
#include "GPIO.h"
#include "SYS_INIT.h"

void SPI2_Config (void);
void SPI2_Transmit (uint8_t *data, int size);
void SPI2_Receive (uint8_t *data, int size);
void SPI2_Enable (void);
void SPI2_Disable (void);
void CS_Enable (void);
void CS_Disable (void);

void SPI3_Config (void);
void SPI3_Transmit (uint8_t *data, int size);
void SPI3_Receive (uint8_t *data, int size);
void SPI3_Enable (void);
void SPI3_Disable (void);

