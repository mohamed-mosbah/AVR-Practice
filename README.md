# AVR-Practice
Practicing Embedded Software Development on AVR microcontrollers

# MCAL
>The Microcontroller Abstraction Layer (MCAL) is the lowest software layer of the Basic Software. It is uC dependent and contains drivers to enable the access of on-chip peripheral devices of a microcontroller and off-chip memory mapped peripheral devices by a defined API. The purpose is to make higher software layers independent of the microcontroller.

Implemented MCAL Drivers till now are:
* DIO
* ADC
* External Interrupts
* Timers
* SPI

# HAL
>The Hardware abstraction layer (HAL) allows the microcontroller to interact with a hardware device at a general or abstract level rather than at a detailed hardware level.

Implemented HAL Drivers till now are:

* Character LCD
* Keypad
* Motor
* Sensors (Potentiometer and LM35)

