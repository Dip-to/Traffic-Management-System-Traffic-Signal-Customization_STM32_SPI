/*
 * Copyright (c) 2022
 * Computer Science and Engineering, University of Dhaka
 * Credit: CSE Batch 25 (starter) and Prof. Mosaddek Tushar
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE UNIVERSITY AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE UNIVERSITY OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "GPIO.h"
#include "CLOCK.h"

void gpio_usart_init(void) // Enable Alternate Function mode
{
	
	RCC->AHB1ENR |= (1<<0) | (1<<2) | (1<<1);
	
	// pc2  spi miso blue
	// pc3  spi mosi green
	//pc7 for sck red
	GPIOC->MODER |= (2 << 4); // ekhane bhul thakte pare
	GPIOC->MODER |= (2 << 6);
	GPIOC->MODER |= (2 << 14);

	GPIOC->OSPEEDR |= (3 << 4); // ekhane bhul thakte pare
	GPIOC->OSPEEDR |= (3 << 6);
	GPIOC->OSPEEDR |= (3 << 14);

	GPIOC->AFR[0] |= (5 << 8);
	GPIOC->AFR[0] |= (5 << 12);
	GPIOC->AFR[0] |= (5 << 28);

	// pb4 miso blue
	//pb5 mosi green
	//pc10 sck red
	// pa4 nss orange
	GPIOB->MODER |= (2 << 8);
	GPIOB->MODER |= (2 << 10);
	GPIOC->MODER |= (2 << 20);
	GPIOC->MODER |= (2 << 20);
	GPIOA->MODER |= (2 << 8);
	

	GPIOB->OSPEEDR |= (3 << 8);
	GPIOB->OSPEEDR |= (3 << 10);
	GPIOC->OSPEEDR |= (3 << 20);
	GPIOA->OSPEEDR |= (3 << 8);

	GPIOB->AFR[0] |= (6 << 16);
	GPIOB->AFR[0] |= (6 << 20);
	GPIOC->AFR[1] |= (6 << 8);
	GPIOA->AFR[0] |= (6 << 16);
	
	

	GPIOA->MODER |= (1<<10);
	GPIOA->OSPEEDR |= (3 << 10);
	GPIOA->BSRR |= (unsigned)(1 << 5);
	
}

// Select Mode as OUTPUT MODE in the GPIOx_MODER
// GPIOA
