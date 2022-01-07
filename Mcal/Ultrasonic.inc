#ifndef  Ultrasonic_H_
#define  Ultrasonic_H_
.INCLUDE "TIMER.INC"
.INCLUDE "ROBOOT_FUNCTIONS.INC"
.ORG 0X670

ultrasonic_config : 
             sbi ddrd,pd4    //us config trigger (output)
			 SBI PORTD , PD4 
			 CALL DELAY_15
			 cbi ddrd ,pd2   ; echo int0 (input)
			 ;sbi ddrd ,pd0  
RET

Ultrasonic_GET://Get the value of ADC PIN0
    call Timer0_start
    call Timer0_get
	call Timer0_stop
    ldi R23,0xFA
	;call Timer0_get
	sub R24,R23
	BRMI BACK
	RET 
BACK:
CALL GO_BACK
RET

DELAY_15:
LDI R23,3
DELAY1:
LDI R22,5
DELAY2:
DEC R22
NOP 
BRNE DELAY2
DEC R23
BRNE DELAY1
RET
#endif


