/*
 * UART_program.c
 *
 *  Created on: Jul 16, 2021
 *      Author: user
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"


void UART_VoidInit(void){

	UCSRA=0;
	UCSRB=0b00011000;
	UCSRC=0b10000110;
	UBRRL=103;
	UBRRH=0;



}

void UART_VoidTransmit(u8 Data){
	while(GET_BIT(UCSRA,5)==0);
	UDR=Data;
}
u8 UART_VoidRecieve(void){

	while(GET_BIT(UCSRA,7)==0);

   return UDR;
}
void UART_voidWriteString  ( u8 *ptr ){

	u8 i = 0 ;

	while( ptr[ i ] != '\0' ){

		UART_VoidTransmit(ptr[i] );
		i++;

	}

}

u8 String[20];
u8 * UART_voidReadString(void){
	u8 i=0;u8 x=0;

	while((x=UART_VoidRecieve()) != 13){ String[i++]=x;}
	String[i]='\0';
	return String;

}
