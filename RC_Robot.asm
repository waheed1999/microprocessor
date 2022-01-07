 

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

 // Gurde erea 

 .ORG 0X66 // Start of Internal SRAM
 
 
 
 
 MAIN:
 // setup stack pointer 
LDI R16,LOW(RAMEND)
OUT SPL,R16
LDI R16,HIGH(RAMEND)
OUT SPH,R16
//_______________________________________________________





VOID_SET:


CALL UART_START // Intializing UART 



CALL INT0_EN // Enable INT0 PIN
CALL Timer0_config 
CALL ultrasonic_config
CALL Ultrasonic_GET
LDI R18,0X0F
IN R17,PINB // Read the value of PINB
OR R18,R17
OUT DDRB,R18 // PINB0,PINB1,PINB2 AND PINB3 OUTPUT WITHOUT CHANGE OTHER PINS


LDI R18,0XF0
IN R17,PINB // Read the value of PINB
AND R18,R17
OUT PORTB,R18 // PINB0,PINB1,PINB2 AND PINB3 IS LOW WITHOUT CHANGE OTHER PINS

VOID_LOAP :
 
 NOP

JMP VOID_LOAP

