




#include <stdint.h>

#include"peripheral_reg.h"

/*
 *
 * Goal: control LED at pin 12, from GPIO D
 *
 * Using Abstraction Implementation (header file containing register as structure)
 *
 *
 * Advantage of this implementation:
 *  - No mask values or bit shift operation are needed
 *  - Compiler will handle these operation internally
 *
 * */


int main(void)
{

	// Initialize the clck_reg with the base address
	RCC_AHB1ENR_t *clck_reg = (RCC_AHB1ENR_t*) 0x40023830 ;

	// Setting the clock for GPIO D (where I have my LED)
	clck_reg->gpiod_en = 1;


	// Initialize for GPIO-D Mod register
	GPIOx_MOD_t *portD_Mod = (GPIOx_MOD_t*) 0x40020C00;
	//0x4002 0C00 (base) + 0x00 = 0x4002 0C00

	// Configure pin 12 at Port D as output
	portD_Mod->pin_12 = 1;



	// Initialize for GPIO-D ODR register

	GPIOx_ODR_t *portD_ODR = (GPIOx_ODR_t*) 0x40020C14;
	// Recall:  0x4002 0C00(base)+ 0x14(offset) = 0x4002 0C14

	portD_ODR->pin_12 = 1; // Turn on the LED

	// Pin 12 is associate for LED4 in the schematic


	portD_ODR->pin_12 = 0; // Turn off the LED


} // End main
