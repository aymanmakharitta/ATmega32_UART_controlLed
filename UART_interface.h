/*
 * UART_interface.h
 *
 * Created: 10/12/2024 5:14:46 PM
 *  Author: Tech Mix
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


void UART_Init(void);

void UART_voidSendData(u8 copy_u8senddata);

u8  UART_u8ReceiveData(void);

void UART_voidSendStringData(u8* copy_u8sendstringdata);
void  UART_u8ReceiveStringData(u8* copy_u8receivestringdata);


u8 UART_u8ReceiveDataAvailable(void);









#endif /* UART_INTERFACE_H_ */