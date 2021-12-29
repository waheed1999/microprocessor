 

 .INCLUDE "UART.INC"
 .INCLUDE "EXTRNAL_INT.INC"



 .ORG 0X00
 RJMP MAIN // rest
 RJMP INT0_HANDL // ex0_int
 .ORG 0X60
 
 
 
 
 MAIN:
 // setup stack pointer 
LDI R16,LOW(RAMEND)
OUT SPL,R16
LDI R16,HIGH(RAMEND)
OUT SPH,R16
//_______________________________________________________





VOID_SET:


RCALL UART_START // Intializing UART 



RCALL INT0_EN // Enable INT0 PIN


VOID_LOAP :
 



RJMP VOID_LOAP

