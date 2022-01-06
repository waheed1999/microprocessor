#ifndef  Ultrasonic_H_
#define  Ultrasonic_H_
.INCLUDE "TIMER.INC"
.INCLUDE "ROBOOT_FUNCTIONS.INC"

.ORG 0X670

ultrasonic_config : 
             sbi ddrb,pb0    //us config
			 cbi ddrd ,pd2   ; echo int0
			 ;sbi ddrd ,pd0  
RET

Ultrasonic_GET://Get the value of ADC PIN0
    ldi R23,0xFA
	sub R24,R23
	BRMI BACK
	RET 
BACK:
CALL GO_BACK
RET
#endif


