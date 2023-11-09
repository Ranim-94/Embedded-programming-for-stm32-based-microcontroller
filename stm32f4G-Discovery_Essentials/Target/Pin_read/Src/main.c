



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

	// Accessing Mode register for GPIO A

	uint32_t* portA_Mode_Reg = (uint32_t*) 0x40020000;



	// Accessing Output register for GPIO D
	uint32_t* portD_Out_Reg =  (uint32_t*) 0x40020C14;

	// 0x4002 0C00 (base)+ 0x14 = 0x4002 0C14


	// Accessing Input register for GPIO A
	// base address + offset = 0x40020000 + 0x10
	uint32_t* portA_In_Reg =  (uint32_t*) 0x40020010;


	// ============== Step 2: Enabling the clock register ==============


	*clck_register |=  1<<3 ; // Port D

	*clck_register |=  1<<0 ; // Port A

	// ============== Step 3: Configure Pin mode (output or input) ==============

	/*
	 * We are working with PD12 and PA0
	 *
	 * The register responsible isL GPIOx MODE
	 */

 // --------------- Working with GPIO_x MODE Reg (section 8.4.1) ----------------

 // configure PD12 as output

  // step 3 a) clear the 24 and 25 bit using 11 mask with & (use and)

  *portD_Mode_Reg &= ~(3<<24); // for 25 bit

  *portD_Mode_Reg |= (1<<24);


  // Configure PA0 as input

  *portA_Mode_Reg &= ~(3<<0);


  // read PA0 status via GPIO IDR and Extract first bit using an & mask
  // there are 2 steps here

  uint8_t pin_status = (uint8_t)(*portA_In_Reg & 0x1);

  // ------------- Implementing checking code --------------------


 while(1){

 // check pin A0 status

	 if(pin_status){

       *portD_Out_Reg |= (1<<12); // turn ON LED PD12

	 }else{

       *portD_Out_Reg &= ~(1<<12); // turn OFF LED PD12

	 } // End if else checking PA0 statuts


 } // End while



} // End main
