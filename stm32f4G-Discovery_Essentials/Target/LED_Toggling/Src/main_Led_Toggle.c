

#include <stdint.h>


int main(void)
{

	// Step 1 ============== Setting Register Values ==============

	/*
	 * In the LED as mentioned at the report, we need to use 3 registers:
	 *
	 * 1) RCC AHB1ENR (for clock enabling for GPIOD)
	 *
	 * 2) GPIO D Mode and 3) GPIO D Out reg
	 *
	 * So as a 1st step, we need the base addresses of RCC and GPIO D
	 *
	 * then the offset values
	 *
	 * base address + offset value = the register address we need
	 *
	 * So we can access to any peripheral registers
	 *
	 * The base address can be found in memory map section from the reference manual
	 */

	// Accessing the value of RCC AHB1ENR register to enable the clock (its base address)
	uint32_t* clck_register =  (uint32_t*) 0x40023830;

	/*
	 * Here I directly assign value to the pointer by type casting
	 * The number 0x40023830 is just a number
	 * We need to cast it to a pointer data --> we use (uint32_t*)
	 */


	// Accessing Mode register for GPIO D
	uint32_t* portD_Mode_Reg =  (uint32_t*) 0x40020C00;
	// 0x4002 0C00 (base) + 0x00 = 0x4002 0C00



	// Accessing Output register for GPIO D
	uint32_t* portD_Out_Reg =  (uint32_t*) 0x40020C14;

	// 0x4002 0C00 (base)+ 0x14 = 0x4002 0C14


	// ============== Step 2: Enabling the clock register ==============

	// Old one: *clck_register |= 0x08; // this a C shortcut


	*clck_register |=  1<<3 ;

	// this equivalent to *clck_register = *clck_register | 0x008


	// ============== Step 3: Configure Pin mode (output or input) ==============

	/*
	 * We are working with port D pin 12
	 *
	 * The register responsible isL GPIOx MODE
	 *
	 * Each 2 bits is for 1 pin
	 *
	 * 	why? because each pin has 4 states, so we need 2 bit
	 *
	 *
	 * 1st we will work with the long way (compute the mask)
	 * then use the shift bit technique
	 *
	 * See section 8.4 page 271 in the reference manual
	 *
	 * */

 // --------------- Working with GPIO_x MODE Reg (section 8.4.1) ----------------
	// step 3 a) clear the 24 and 25 bit (use and)

	// Old *portD_Mode_Reg &= 0xFCFFFFFF;

	/*
	 * we need to clear 24 and 25 th bit position
	 * We have 2 methods using bit shift:
	 * */


	//  Clearing 24 and 25th bit simultaneously

	*portD_Mode_Reg &= ~(3<<24); // for 25 bit

	/*
	 * binary value of 3: 11
	 *
	 * pushing 11 to 24 bit position --> 11 = 24 and 25 bits
	 * */


	// Step 3 b) make the 24th bit position to 1 (bit wise OR)

	*portD_Mode_Reg |= (1<<24);


	// --------------- Working with GPIO_x ODR Reg (section 8.4.6) ----------------


	while(1){
	// step 4: Turn LED on

	*portD_Out_Reg |= (1<<12);


	// Inserting a delay using a for loop

	for (uint32_t i = 0; i < 100000; i++) ;


	// Switching LED off: done by reset
	// so we need to insert 0 at bit 12

	*portD_Out_Reg &= ~(1<<12);


	// Wait after LED off using a for loop
	for (uint32_t i = 0; i < 100000; i++) ;


	} // End while to turn LED off



} // End main


