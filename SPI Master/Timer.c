#include "CLOCK.h"
#include "USART.h"
#include "GPIO.h"
#include "SYS_INIT.h"
#include "Timer.h"
#include "global.h"
#include <stdio.h>
#include <string.h>
#include "InterruptHandler.h"
#include <stdlib.h>
uint32_t counter = 0;

char t1[4][200] = {
	"traffic light 1 ",
	"traffic light 2 ",
	"road north south ",
	"road east west "};

char t2a[4][200] = {
	"ON ON OFF",
	"OFF OFF ON"};

char t2b[4][200] = {
	"heavy traffic",
	"light traffic"};

void TIM6_DAC_IRQHandler(void)
{
	
//check if update flag is set	
	if (TIM6->SR & TIM_SR_UIF)
	{
		TIM6->SR &= ~TIM_SR_UIF;

		counter++;

		if ((counter % traffic_monitor) == 0)
		{
			strcpy(final_output, "\n----------------------------------");

			char str[10];
			sprintf(str, "\n%d ", counter);
			strcpy(traffic3, traffic2);
			strcpy(traffic2, traffic1);
			strcpy(traffic1, "");

			for (int j = 0; j < 4; j++)
			{
				strcat(traffic1, str);
				strcat(traffic1, t1[j]);

				int a = (GPIOA->IDR & (1U << 7));
				
				if (j == 0)
				{
					if (!a)
					{
						strcat(traffic1, t2a[0]);
						strcat(traffic1, str);
						strcat(traffic1, t1[j+1]);
						strcat(traffic1, t2a[1]);
					}
					else
					{
						strcat(traffic1, t2a[1]);
						strcat(traffic1, str);
						strcat(traffic1, t1[j+1]);
						strcat(traffic1, t2a[0]);
					}
					j++;
				}
				else if (j == 2)
				{
					int c = (GPIOA->IDR & (1U << 8));

					if (c)
						strcat(traffic1, t2b[0]);
					else
						strcat(traffic1, t2b[1]);
				}
				else
				{
					int d = (GPIOB->IDR & (1U << 3));

					if (d)
						strcat(traffic1, t2b[0]);
					else
						strcat(traffic1, t2b[1]);
				}
			}

			strcat(final_output, traffic3);
			strcat(final_output, traffic2);
			strcat(final_output, traffic1);

			UART_SendString(USART2, final_output);
		}
	}
}
// Function to initialize Timer 6
void TIM6_Config(void)
{
    RCC->APB1ENR |= TIM6_CLOCK;

    TIM6->PSC = 8999; // 10khz frequency ....
    TIM6->ARR = 9999;

    TIM6->DIER |= TIM_DIER_UIE;
    NVIC_EnableIRQ(TIM6_DAC_IRQn);

    TIM6->CR1 |= TIM_CR1_CEN;
}
