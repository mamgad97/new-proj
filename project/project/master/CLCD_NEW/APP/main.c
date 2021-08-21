/*
 * main.c
 *
 *  Created on: May 29, 2021
 *      Author: AMIT
 */
// master kit code.
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
#include "../MCAL/UART/UART_interface.h"

int main(void){

	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT); // set led pin 2 in port C as output
	DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT); // set UART on pin 1 in port D as output
	DIO_voidSetPinDirection(PORTD,PIN0,INPUT); // set UART on pin 0 in port D  as input

	UART_VoidInit(); // iniallization  for the UART
	SPI_voidMasterInit(); // iniallization for the SPI master
	u8 sent_Data_master; // variable declaration.
	while(1){
		_delay_ms(1500); // delay to prevent data collision

		sent_Data_master=UART_VoidRecieve(); // put data recieved from bluetooth in sent data master
		SPI_u8MasterTransmitReceive(sent_Data_master); // transimmit  sent data master to other micro through SPI
		if(sent_Data_master=='1') {DIO_voidSetPinValue(PORTC,PIN2,HIGH);} // check if sent data master== 1 --> led on
		else
		{
			DIO_voidSetPinValue(PORTC,PIN2,LOW); // chech if sent data master == 0 --> led off
		}
	}
	return 0;
}
