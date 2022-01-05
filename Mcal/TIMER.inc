#ifndef  TIMER_H_
#define  TIMER_H_
.ORG 0X570


Timer0_config :  // This function initialize the timer0 in normal mode
	  LDI R20 , -255
	  OUT TCNT0 , R20 ;;;
	  LDI R20 , 0x02  ;;;
	  OUT TCCR0 , R20 ;;;
	
RET


Timer0_start :  // This function start time count
again: IN R20,TIFR
       SBRS R20 , TOV0
	   RJMP again
RET


Timer0_stop :  // This function stop time count  Hent : ( No clock source to timer0 "TCCR0" )


             LDI R20, 0x00
			 OUT TCCR0 , R20 

RET


Timer0_get:  // This function get the value of time
           LDI R20 , 0x00
		   LDI R20 , (1<<TOV0)
		   OUT TIFR ,R20
RET


#endif


