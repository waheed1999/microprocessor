

#ifndef UART_H_
#define UART_H_
.ORG 0X500

UART_START : // Start Uart communication with buade rate = 9600 bit/s

LDI R16,0X86; 
OUT UBRRH,R16;//USART Baud Rate Register : = 0x86 for boud =9600 with F_CPU =1MH
LDI R16,0X0C;
OUT UBRRL,R16;// USART Baud Rate Register : = 0x0C for boud =9600 with F_CPU =1MH
LDI R16,0X22;
OUT UCSRA,R16;//USART Control and Status Register A : double speed and watch flags
LDI R16,0XD8;
OUT UCSRB,R16;//USART Control and Status Register B :  Enabel RX & TX and the UART Interrupt
LDI R16,0X86;
OUT UCSRC,R16;// USART Control and Status Register C : Asynchronous Uart , no pariti ,one stop bit and 8-bit char size 
LDI R16 ,(1<<7) 
OUT SREG,R16 //Global Interrupt Enable 
RET

UART_SEND :
SBIC UCSRA,5//  IF USART Data Register Empty flag is cleared dont write on UDR Register  
OUT UDR,R20 // write the data which will be send 
//LDI R20,0X00 // MAKE SURE THAT R20 IS EMPTY
RET

UART_REC :
SBIC UCSRA,7// IF USART Receive Complete flag is cleared dont read the UDR Register
IN R20,UDR // Read the received data from the UDR Register
RET

#endif



