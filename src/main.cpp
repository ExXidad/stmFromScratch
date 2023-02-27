#include "../inc/stm32f746xx.h"

int main(void)
{
	// GPIO clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

	// PI1 GP output mode
	GPIOI->MODER |= (0b01 << 2);

	// Set LED PI1
	GPIOI->BSRR |= (1 << 1);

	// Read Button PI11
	while ((GPIOI->IDR & (1 << 11)) != (1 << 11));

	// Reset LED PI1
	GPIOI->BSRR |= (1 << 17);

	// Enable GPIO Clock
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	// Alternate Function Mode USART1
	GPIOA->MODER |= (0b10 << 9 * 2); // PA9
	GPIOB->MODER |= (0b10 << 7 * 2); // PB7

	// <<4=PA9, 0b111=7=AF7
	GPIOA->AFR[1] |= (0b111 << (4 * (9 - 8)));

	// <<28=PB7, 0b111=7=AF7
	GPIOB->AFR[0] |= (0b111 << (4 * (7 - 0)));

	// Enable USART Clock
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	USART1->BRR = 1667;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_UE;

	// Main loop
	while (1)
	{
		// Send 7
		USART1->TDR = '7';
		// Wait until done
		while (!(USART1->ISR & USART_ISR_TXE));
	}
}
