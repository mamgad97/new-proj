///*
// * CLCD_program.c
// *
// *  Created on: Jun 11, 2021
// *      Author: AMIT
// */
//
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.H"
//
//#include <util/delay.h>
//
//#include "../../MCAL/DIO/DIO_interface.h"
//
//#include "CLCD_interface.h"
//#include "CLCD_private.h"
//#include "CLCD_config.h"
//
//
//void CLCD_voidInit          ( void ){
//
//	DIO_voidSetPortDirection( CLCD_DATA_PORT , 255 );
//	DIO_voidSetPinDirection ( CLCD_COTROL_PORT , CLCD_RS_PIN , OUTPUT );
//	DIO_voidSetPinDirection ( CLCD_COTROL_PORT , CLCD_RW_PIN , OUTPUT );
//	DIO_voidSetPinDirection ( CLCD_COTROL_PORT , CLCD_EN_PIN , OUTPUT );
//
//	_delay_ms(50);
//
//	/* Function Set Commend */
//	CLCD_voidWriteCommend( 0b00111100 );
//	/* Delay Between Each commend according to data sheet */
//	_delay_ms(1);
//
//	/* Display ON OFF */
//	CLCD_voidWriteCommend( 0b00001100 );
//
//	_delay_ms(1);
//
//	CLCD_voidWriteCommend( 0b00000001 );
//
//	_delay_ms(2);
//
//	/* Entry Mode Set */
//	//CLCD_voidWriteCommend();
//}
//
//void CLCD_voidWriteData     ( u8 Copy_u8Data ){
//
//	/* Rs --> 1 */
//	DIO_voidSetPinValue( CLCD_COTROL_PORT , CLCD_RS_PIN , HIGH );
//	/* Rw --> 0 */
//	DIO_voidSetPinValue( CLCD_COTROL_PORT , CLCD_RW_PIN , LOW  );
//	/* D0--> D7 --> Data */
//	DIO_voidSetPortValue( CLCD_DATA_PORT , Copy_u8Data );
//	/* Enable */
//	DIO_voidSetPinValue ( CLCD_COTROL_PORT , CLCD_EN_PIN , HIGH );
//	/* Waitig Before Making Pin LOW */
//	_delay_ms(1);
//	DIO_voidSetPinValue ( CLCD_COTROL_PORT , CLCD_EN_PIN , LOW  );
//	/* Delay Between Each Data */
//	_delay_ms(1);
//
//}
//
//void CLCD_voidWriteCommend  ( u8 Copy_u8Commend ){
//
//	/* Rs --> 1 */
//	DIO_voidSetPinValue( CLCD_COTROL_PORT , CLCD_RS_PIN , LOW );
//	/* Rw --> 0 */
//	DIO_voidSetPinValue( CLCD_COTROL_PORT , CLCD_RW_PIN , LOW  );
//	/* D0--> D7 --> Data */
//	DIO_voidSetPortValue( CLCD_DATA_PORT , Copy_u8Commend );
//	/* Enable */
//	DIO_voidSetPinValue ( CLCD_COTROL_PORT , CLCD_EN_PIN , HIGH );
//	_delay_ms(1);
//	DIO_voidSetPinValue ( CLCD_COTROL_PORT , CLCD_EN_PIN , LOW  );
//	_delay_ms(1);/**/
//
//
//}
//void CLCD_VoidSendString(u8* copy_u8string){
//
//	u8 lock_u8i=0;
//	while (copy_u8string[lock_u8i]!='\0'){
//		CLCD_voidWriteData(copy_u8string[lock_u8i]);
//		lock_u8i++;
//
//	}
//
//}
//
//void CLCD_VoidSendNumber(u64 Number){
//	u64 Reversed=1;
//	if (Number==0){
//		CLCD_voidWriteData('0');
//	}
//	else{
//		while(Number!=0){
//			Reversed=(Reversed*10)+(Number%10);
//			Number/=10;
//		}
//		while(Reversed!=1){
//			CLCD_voidWriteData((Reversed%10)+48);
//			Reversed/=10;
//		}
//	}
//
//
//}
//
//
//
//void CLCD_VoidSetPosition(u8 Row,u8 Col){
//	if(Row==1){
//		CLCD_voidWriteCommend(0x80+Col);
//	}
//	else if(Row==2){
//		CLCD_voidWriteCommend(0x80+64+Col);
//	}
//
//}
//
//
//void CLCD_voidWriteExtraChar(u8 *ptr,u8 len,u8 row,u8 col){
//	s8 i=0;
//	CLCD_voidWriteCommend(0x40);
//	for(i=0;i<len;i++){CLCD_voidWriteData(ptr[i]);}
//	CLCD_VoidSetPosition(row,col);
//	for(i=(len/8)-1;i>=0;i--){CLCD_voidWriteData(i);}
//}
//
//
//
//
//
//
//
//
//
//
//
