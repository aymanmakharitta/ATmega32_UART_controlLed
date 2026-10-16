/*
 * UART_reg.h
 *
 * Created: 10/12/2024 5:15:38 PM
 *  Author: Tech Mix
 */ 


#ifndef UART_REG_H_
#define UART_REG_H_


#define  UDR_REG        *((volatile u8*)0x2C)
#define  UCSRA_REG      *((volatile u8*)0x2B)
#define  UCSRB_REG      *((volatile u8*)0x2A)
#define  UCSRC_REG      *((volatile u8*)0x40)
#define  UBRRL_REG      *((volatile u8*)0x29)
#define  UBRRH_REG      *((volatile u8*)0x40)





#endif /* UART_REG_H_ */