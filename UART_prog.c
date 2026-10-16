/*
 * UART_prog.c
 *
 * Created: 10/12/2024 5:16:07 PM
 *  Author: Tech Mix
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "UART_interface.h"
#include "UART_reg.h"



void UART_Init(void){
	
	/*select baud-rate 9600 and double speed off*/
	CLR_BIT(UCSRA_REG,1);
	UBRRL_REG= 103;
	
	/*disable UART interrupt*/
	CLR_BIT(UCSRB_REG,5);
	CLR_BIT(UCSRB_REG,6);
	CLR_BIT(UCSRB_REG,7);
	
	
	/*
	select Asynchronous speed
	select one_bit stop 
	select 8_bit charchter size 
	disable parity 
	*/
	CLR_BIT(UCSRB_REG,2);
	UCSRC_REG=0b10000110;
	
	
	/*enable receive*/
	SET_BIT(UCSRB_REG,4);
	/*enable transmit*/
	SET_BIT(UCSRB_REG,3);
	
	
}

void UART_voidSendData(u8 copy_u8senddata){
	
	
	while(GET_BIT(UCSRA_REG,5)==0);
	
	
	UDR_REG=copy_u8senddata;

}

u8  UART_u8ReceiveData(void){
	
	while(GET_BIT(UCSRA_REG,7)==0);
		return UDR_REG;
}


void UART_voidSendStringData(u8* copy_u8sendstringdata)
{
	u8 i= 0; 
	while(copy_u8sendstringdata[i] != '\0'){

		UART_voidSendData(copy_u8sendstringdata[i]) ; 
		i++ ; 
	}	
	
	
}


void  UART_u8ReceiveStringData(u8* copy_u8receivestringdata)
{
	u8 i= 0;
	
	do 
	{copy_u8receivestringdata[i] = UART_u8ReceiveData();
		i++;
	} while (copy_u8receivestringdata[i-1] != '\#');
	
	copy_u8receivestringdata[i-1]= '\0';
	
}



u8 UART_u8ReceiveDataAvailable(void)
{
	return GET_BIT(UCSRA_REG, 7);
}