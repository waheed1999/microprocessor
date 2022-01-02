ORG 0X670

LM35_config : // Initializ ADC pin0
             LDI R21, 0x00
			 OUT DDRA , R21
			 LDI R21, 0xE3   
			 OUT ADMUX ,R21
			 LDI R21 , 0x8D
			 OUT ADCSRA , R21
RET
