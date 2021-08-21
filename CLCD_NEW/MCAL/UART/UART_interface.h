/*
 * UART_interface.h
 *
 *  Created on: Jul 16, 2021
 *      Author: user
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

void UART_VoidInit(void);
void UART_VoidTransmit(u8 Data);
u8   UART_VoidRecieve(void);
void UART_voidWriteString(u8 *ptr);
u8 * UART_voidReadString(void);
#endif /* MCAL_UART_UART_INTERFACE_H_ */
