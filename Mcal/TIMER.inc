#ifndef  TIMER_H_
#define  TIMER_H_
.ORG 0X570


Timer0_config :  // This function initializ the timer0 in normal mode
	  LDI R23,0x04
	  out TCCR0, R23 ;prescaler 256
	;sbi portb,pb0
	 /* LDI R23 ,0
	  OUT TCNT0 ,R23*/

	
RET




Timer0_start :  // This function start time count     
      LDI R23 ,0
	  OUT TCNT0 ,R23    ;start count = 0
	
RET


Timer0_stop :  // This function stop time count  Hent : ( No clock source to timer0 "TCCR0" )
             LDI R22, 0
			 out TCCR1B,R22      ;stop 

RET


Timer0_get:  // This function get the value of time
          IN R24,TCNT0 ;STORE THE COUNTER
		  LDI R22 ,0x00
		  OUT TCNT0,R22  ;RESET COUNTER
RET



#endif


