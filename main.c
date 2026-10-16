/*
 * UART_LCD_ControlLed.c
 *
 * Created: 10/16/2026 11:28:16 PM
 * Author : AYMAN KHALED
 */

#include <avr/io.h>

#include "BIT_MATH.h"
#include "STD_TYPE.h"

#include "DIO_interface.h"
#include "UART_interface.h"

#include "LCD_interface.h"

#define  F_CPU 16000000UL
#include <util/delay.h>


void LedToggle(void);

int main(void)
{
	/*intialize UART protocol*/
	UART_Init();
	/*intialize LCD*/
	LCD_voidInit();
	_delay_ms(2000);
	
	UART_voidSendStringData("ready...");
	LCD_voidGotoxy(1,0);
	LCD_voidSendString("system is ready");
	LCD_voidGotoxy(5,1);
	LCD_voidSendString("START");
	_delay_ms(2000);
	LCD_voidClearData();
	
	/*set led as output*/
	DIO_voidSetPinDir(DIO_PORTC,DIO_PIN2,OUTPUT);
	
	/*pointer to receive the data in */
	u8 *received_data;
	/*Allocate 32 bytes of memory to store the received data */
	received_data= malloc(32);
	
	
    
    while (1) 
    {
			
			
			if (received_data != NULL)
			{
				/*call receive function */
				UART_u8ReceiveStringData(received_data);
			}
			
			
			
				if (strcmp((char *)received_data, "LED ON") == 0)
				{
					LCD_voidClearData();
					DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,HIGH);
					UART_voidSendStringData("DONE");
					LCD_voidGotoxy(1,0);
					LCD_voidSendString("the led is on");
				}
				
				/****************************************************/
				
				
				else if (strcmp((u8 *)received_data,"LED OFF")==0)
				{
					LCD_voidClearData();
					DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,LOW);
					UART_voidSendStringData("DONE");
					LCD_voidGotoxy(1,0);
					LCD_voidSendString("the led is off");
				}
				
				/****************************************************/
				
				else if (strcmp((u8 *)received_data,"LED TOGGLE")==0)
				{
					LCD_voidClearData();
					UART_voidSendStringData("DONE");
					LCD_voidGotoxy(1,0);
					LCD_voidSendString("the led is toggle");
					/*Keeps the LED toggling continuously until a new UART command is received*/
					while(UART_u8ReceiveDataAvailable()==0)
					{
						LedToggle();
					}
				
				}
				
				/****************************************************/
				
				else if (strcmp((u8 *)received_data,"HELP")==0)
				{
					LCD_voidClearData();
					LCD_voidGotoxy(0,0);
					LCD_voidSendString("LED ON");
					LCD_voidGotoxy(0,1);
					LCD_voidSendString("LED OFF");
					_delay_ms(1000);
					LCD_voidClearData();
					LCD_voidGotoxy(0,0);
					LCD_voidSendString("LED TOGGLE");
					LCD_voidGotoxy(0,1);
					LCD_voidSendString("HELP");
					_delay_ms(1000);
					LCD_voidClearData();
					LCD_voidGotoxy(0,0);
					LCD_voidSendString("SEND: CMD#");
					_delay_ms(1000);
				}
				
				/****************************************************/

				else
				{
					LCD_voidClearData();
					LCD_voidGotoxy(1,0);
					LCD_voidSendString("Invalid Command");
				}
		}
    }









void LedToggle(void)
{
	
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,HIGH);
	_delay_ms(1000);
	DIO_voidSetPinVal(DIO_PORTC,DIO_PIN2,LOW);
	_delay_ms(1000);
	
}
