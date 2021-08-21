/*
 * main.c
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */
//slave code
#include <stdio.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.H"

#include <util/delay.h>

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../HAL/CLCD_Eng_Hesham/CLCD_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/GIE/GIE_private.h"
#include "../MCAL/SPI/SPI_interface.h"


int main(void){
	//  initilization led as output
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);


	SPI_voidSlaveInit(); // SPI  initilization
	u8 received_Data = 0; // data definition = 0
	while(1){

		received_Data  = SPI_u8SlaveTransmitReceive('1'); // transimmit the data by SPI in variable data




		if(received_Data =='1') {DIO_voidSetPinValue(PORTC,PIN7,HIGH);} // check the received data if data == 1 --> led on
		else if(received_Data =='0')
		{
			DIO_voidSetPinValue(PORTC,PIN7,LOW); // if received data == 0 --> led off
		}
	}
	return 0;
}
