.INCLUDE "UART.INC"
 .INCLUDE "EXTRNAL_INT.INC"
  .INCLUDE "TIMER.INC"
 .INCLUDE "Ultrasonic.INC"

 // VECTOR table

 .ORG 0X00
 
 JMP MAIN // Rest code  
 JMP INT0_HANDL // ex0_int

  .ORG 0X1A     // The address of Uart recive int handeller 
  jmp RXC_COMP // jump to handeller function

 // Guard area

 .ORG 0X66 // Start of Internal SRAM
 
 
 
 
 MAIN:
 // set up stack pointer 
LDI R16,LOW(RAMEND)
OUT SPL,R16
LDI R16,HIGH(RAMEND)
OUT SPH,R16
//___________________





VOID_SET:


CALL UART_START // Intializing UART 

CALL INT0_EN // Enable INT0 PIN
CALL Timer0_config 
CALL ultrasonic_config
LDI R18,0X0F
IN R17,PINB // Read the value of PINB

VOID_LOAP :
 
 NOP

JMP VOID_LOAP

