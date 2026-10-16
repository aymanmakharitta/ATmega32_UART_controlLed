# ATmega32 UART Control LED

## Project Overview
An Embedded C project using the ATmega32 microcontroller to control an LED through UART serial commands.
The project is developed using Microchip Studio and simulated using Proteus.

## Features
- UART serial communication
- LED ON, OFF, and TOGGLE commands
- HELP command to display available commands
- LCD interface
- Proteus simulation

## Hardware and Software
- Microcontroller: ATmega32
- Programming Language: Embedded C
- IDE: Microchip Studio
- Simulation: Proteus
- Communication Protocol: UART
- Clock Frequency: 16 MHz

## UART Commands

| Command | Description |
|---|---|
| `LED ON#` | Turns the LED ON |
| `LED OFF#` | Turns the LED OFF |
| `LED TOGGLE#` | Toggles the LED state |
| `HELP#` | Displays available commands |

## How It Works

1. The ATmega32 receives a command through UART.
2. The received string is processed by the program.
3. The microcontroller identifies the requested operation.
4. The LED is controlled according to the received command.
5. The LCD displays relevant information.

## Author
Ayman Khaled Mohamed Mekharita
Electrical Power Engineering Graduate  
Damietta University
