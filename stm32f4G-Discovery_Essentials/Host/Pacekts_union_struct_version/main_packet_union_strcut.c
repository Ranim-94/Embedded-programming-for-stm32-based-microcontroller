



// Goal: Implement a packet using combination of union and strcut


#include<stdio.h>
#include<stdint.h>


union Packet{

	// For storing packet value
	uint32_t packet_value;


	struct{

		uint32_t crc:2 ;// Instruct the compiler I allocate 2 bits of the 32  bits

		uint32_t status:1;
		uint32_t payload:12;
		uint32_t bat:3;
		uint32_t sensor:3;
		uint32_t longAddr:8;
		uint32_t shorAddr:2;
		uint32_t addMore:1;


	}packet_fields ;// End strcut packet fields


}; // End union Packet definition


int main(void){

	// Instantiating

	union Packet packet_1;

	// Assigning value
	packet_1.packet_value =  0XABCDEFCD ;


	// Now we don't need masking and bit wise operation
	// all the structure elements will be assign directly


	// =============  Printing fields value =====================

	printf("Content of the packet: \n");

    printf("- crc \t : %#X \n ",packet_1.packet_fields.crc);

	printf("- status \t : %#X \n ",packet_1.packet_fields.status);

	printf("- payload \t : %#X \n ",packet_1.packet_fields.payload);

	printf("========================================= \n ");



}; // End main
