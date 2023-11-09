



#include<stdint.h>
#include<stdio.h>

struct Packet {


	uint8_t crc;
	uint8_t status;
	uint16_t payload;
	uint8_t bat;
	uint8_t sensor;
	uint8_t longAddr;
	uint8_t shorAddr;
	uint8_t addMore;


} ; // End Packet definition


int main(void){


	// Inputting some packet value
	uint32_t some_packet_value = 0XABCDEFCD ;


	// Instantiating

	struct Packet packet_1;


	// =============  Extracting fields value =====================

	packet_1.crc = (uint8_t)(some_packet_value & 0X3);
	// Mask value = 11 in binary = 3 hexa


	packet_1.status = (uint8_t)(some_packet_value>>2 & 0X1);


	packet_1.payload = (uint16_t)(some_packet_value>>3 & 0XFFF);

	// payload is of 12 bits --> we need 12 1 = FFF

	packet_1.bat = (uint8_t)(some_packet_value>>15 & 0X7);

	packet_1.sensor = (uint8_t)(some_packet_value>>18 & 0X7);


	packet_1.longAddr = (uint8_t)(some_packet_value>>21 & 0xFF);

	packet_1.shorAddr = (uint8_t)(some_packet_value>>29 & 0x3);

	packet_1.addMore = (uint8_t)(some_packet_value>>31 & 0x1);

	// Notice that the shift value increase more while we are going deeper in
	// packet fields (going deeper means to the left side)

	// =============  Printing fields value =====================

	printf("Content of the packet: \n");

	printf("- crc \t : %#X \n ",packet_1.crc);

	printf("- status \t : %#X \n ",packet_1.status);

	printf("- payload \t : %#X \n ",packet_1.payload);

	printf("========================================= \n ");

	printf("Size of the structure: %I64u bytes \n",sizeof(packet_1)) ;



}; // End main
