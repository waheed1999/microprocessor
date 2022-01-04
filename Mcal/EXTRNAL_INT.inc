#ifndef INT_H_
#define INT_H_
.ORG 0X540
INT0_EN :
// INT0 ON Rising adge
// intro

IN R18, MCUCR // Read MCUCR value to R18 
LDI R19,0B00000011 // Set the target Bits to 1
OR R18,R19  // To make sur that no Bit will chang exept the target bits
  
  
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



RETI

#endif
