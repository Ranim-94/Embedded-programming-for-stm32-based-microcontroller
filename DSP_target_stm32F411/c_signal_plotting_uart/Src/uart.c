


#include"uart.h"

#define GPIOAEN (1U<<0) // shift bit 1 to position 0


void uart2_tx_init(void){


	/*****Configure UART GPIO Pin******/

		/*Enable clock access to GPIOA*/
		// GPIO is connected to AHB1
		RCC->AHB1ENR |= GPIOAEN;

		/*Set PA2 mode to alternate function mode */

		GPIOA->MODER &=~(1U<<4);
		GPIOA->MODER |=(1U<<5);

		/*Set PA2 alternate function type to UART_TX(AF07)*/
		/*
		 * In the header file we use, AFR is an array of size 2
		 *
		 * [0] for AFR low (pin 0 --> pin 7) and [1] for AFR high (pin 8 --> pin 15)
		 * */
		GPIOA->AFR[0] |=(1U<<8);
		GPIOA->AFR[0] |=(1U<<9);
		GPIOA->AFR[0] |=(1U<<10);
		GPIOA->AFR[0] &=~(1U<<11); // shift 0 to bit 10

		/*****Configure UART  ******/
		/*Enable clock access to UART2*/
		RCC->APB1ENR |=UART2EN;

		/*Configure baudrate*/
		uart2_set_baudrate(APB1_CLK,UART_BAUDRATE);

		/*Configure the transfer direction*/
		USART2->CR1 = CR1_TE;

		/*Enable UART module*/
		USART2->CR1 |= CR1_UE;




} // end uart2_tx_init
