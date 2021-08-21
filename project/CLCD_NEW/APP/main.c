/*
 * main.c
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */
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

	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT); // output led
	CLCD_voidInit();
	SPI_voidSlaveInit(); // initilization SPI
	u8 Data = 0; // defination data = 0
	while(1){
		//_delay_ms (1000);
		Data = SPI_u8SlaveTransmitReceive('1'); // transimmit the data through SPI in variable data
		//CLCD_voidSetPosition(1,1);
		//CLCD_voidWriteNumber(Data);



		if(Data=='1') {CLCD_voidWriteNumber(1);} // check the data if data == 1 --> led on
		else if(Data=='0') 
		{
			CLCD_voidWriteNumber(0); // if data == 0 --> led off
		}
	}
	return 0;
}
