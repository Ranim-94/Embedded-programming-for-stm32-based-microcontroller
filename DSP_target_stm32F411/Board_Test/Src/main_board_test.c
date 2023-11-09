



#include"stm32f411xe.h"


#define GPIOAEN (1U<<0)
/*
 * Set bit 0 to 1
 *
 * Enable clock
 * */

#define PIN_5 (1U<<5)

#define LED_PIN PIN_5


int main(){

		RCC->AHB1ENR |= GPIOAEN ; // Enable clock access to GPIO A

		// Set PIN_5 to output
		GPIOA->MODER |=(1U<<10) ; // set bit 10 to 1

		GPIOA->MODER &=~(1U<<11) ; // set bit 11 to 0


		GPIOA->ODR |= LED_PIN ; // Switch LED ON

		GPIOA->ODR &=~LED_PIN ; // Switch back to off



} // End main
