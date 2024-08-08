/*
 * GccApplication1.c
 * Author : da_unknown_developer
 * Implementation of some peripherals ..
 */ 

#define F_CPU 1000000UL

#include "MCAL/GPIO.h"

int main(void)
{
	/*DDRA = 1;
	//INTERNAL PULLUP
	PORTA |= (1<<PA7);
	
	while (1) 
    {
		while(PINA & (1<<PA7))
			PORTA |=1;
		PORTA &= (~1);    
	}*/
	init_pin(A_PORT , 0 , OUTPUT);
	init_pin(A_PORT , 1 , OUTPUT);
	init_pin(A_PORT , 2 , OUTPUT);
	init_pin(A_PORT , 7 , OUTPUT);
	
	if(set_pin(A_PORT , 7 , PULLUP_ON) == SUCCESS){
		set_pin(A_PORT , 1 , HIGH);	
	}
	else{
		set_pin(A_PORT , 2 , HIGH);
	}
	while (1)
	{
		while(read_pin(A_PORT,7))
		{
			set_pin(A_PORT,0,HIGH);			
		}
		set_pin(A_PORT,0,LOW);
		
	}
	
}

