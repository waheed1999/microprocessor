

#ifndef UART_H_
#define UART_H_
.INCLUDE "ROBOOT_FUNCTIONS.INC"
.ORG 0X500
.EQU PIN0 =0
.EQU PIN1 =1
.EQU PIN2 =2
.EQU PIN3 =3
.EQU PIN4 =4
.EQU PIN5 =5
.EQU PIN6 =6
.EQU PIN7 =7

UART_START : // Start Uart communication with buade rate = 9600 bit/s

LDI R16,0X86; 
OUT UBRRH,R16;//USART Baud Rate Register : = 0x86 for boud =9600 with F_CPU =1MH
LDI R16,0X0C;
OUT UBRRL,R16;// USART Baud Rate Register : = 0x0C for boud =9600 with F_CPU =1MH
LDI R16,0X22;
OUT UCSRA,R16;//USART Control and Status Register A : double speed and watch flags
LDI R16,0X98;
OUT UCSRB,R16;//USART Control and Status Register B :  Enabel RX & TX and the UART Interrupt
LDI R16,0X86;
OUT UCSRC,R16;// USART Control and Status Register C : Asynchronous Uart , no pariti ,one stop bit and 8-bit char size 
LDI R16 ,(1<<7) 
OUT SREG,R16 //Global Interrupt Enable 
RET

UART_SEND :
SBIC UCSRA,5//  IF USART Data Register Empty flag is cleared dont write on UDR Register  
OUT UDR,R20 // write the data which will be send 

RET

UART_REC :
SBIC UCSRA,7// IF USART Receive Complete flag is cleared dont read the UDR Register
IN R20,UDR // Read the received data from the UDR Register
RET








RXC_COMP :
CALL UART_REC // Holde the received value in R20 REG

LDI R19,'S'
SUB R19,R20 // To change Z flag
BRNE NOT_STOP // We watching Z flag IF (Z==0)->BRANCH
CALL STOP
 NOT_STOP:



LDI R19,'F'
SUB R19,R20 // To change Z flag
BRNE NOT_FORWARD // We watching Z flag IF (Z==0)->BRANCH
CALL GO_FORWARD
NOT_FORWARD:



LDI R19,'B'
SUB R19,R20 // To change Z flag
BRNE NOT_BACK // We watching Z flag IF (Z==0)->BRANCH
CALL GO_BACK
NOT_BACK:



LDI R19,'L'
SUB R19,R20 // To change Z flag
BRNE NOT_LEFT // We watching Z flag IF (Z==0)->BRANCH
CALL GO_LEFT
NOT_LEFT:



LDI R19,'R'
SUB R19,R20 // To change Z flag
BRNE NOT_RIGHT // We watching Z flag IF (Z==0)->BRANCH
CALL GO_RIGHIT
NOT_RIGHT:
 
LDI R19 , 'V'
 SUB R19,R20 
 BRNE BUZZER_OFF
 CALL BUZZER_ON
BUZZER_OFF:
          SBI DDRB , PB4
          CBI PORTB , PB4     ;CLEAR PB4

#endif




