#ifndef INT_H_
#define INT_H_
.ORG 0X540
INT0_EN :
// INT0 ON Rising adge
// intro

IN R18, MCUCR // Read MCUCR value to R18 
LDI R19,0B00000011 // Set the target Bits to 1
OR R18,R19  // To make sure that no Bit will chang exept the target bits
  
  
  
  
OUT MCUCR,R18 // Load MCUCR value 
//_____________________
IN R18, GICR // Read GICR value to R18 
LDI R19,0B01000000 // Set the target Bits to 1


  
  
OR R18,R19 // To make sur that no Bit will chang exept the target bits
OUT GICR,R18 // Load GICR value 
//______________________
//Global Interrupt Enable
LDI R16 ,(1<<7) 
  
OUT SREG,R16 
RET



INT0_HANDL :
// Write What will happen in case of Rising adge Int0
IN R20,PINA
COM R20
OUT PORTA,R20

LDI R23,0x04
	out TCCR0, R23
	sbi portb,pb0
	   
HERE :
   SBIC PORTB,2     ;echo pin 
	rjmp HERE 
	reti
RCALL DELAY

RETI



DELAY:
LDI R16,0XFF
LDI R17,255
L1 :
DEC R16
L2:
DEC R17
BRNE L2
BRNE L1

RET
#endif
