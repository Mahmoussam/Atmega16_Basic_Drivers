/*
 * CFile1.c
 *
 *  Author: da_unknown_developer
 * Implements GPIO interface
 */ 
#include "GPIO.h"

/************************************************************************/
/* Interfaces Implementations                                           */
/************************************************************************/
/*
* returns the address of the DD register for a given port
*/
static volatile uint8_t* resolve_DD_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
			return &DDRA;
			break;
		case B_PORT:
			return &DDRB;
			break;
		case C_PORT:
			return &DDRC;
			break;
		case D_PORT:
			return &DDRD;
			break;
		default:
			break;
	}
	return NULL;
}
/*
* returns the address of the PORT register for a given port
*/
static volatile uint8_t* resolve_PORT_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
			return &PORTA;
			break;
		case B_PORT:
			return &PORTB;
			break;
		case C_PORT:
			return &PORTC;
			break;
		case D_PORT:
			return &PORTD;
			break;
		default:
			break;
	}
	return NULL;
}
/*
* returns the address of the PIN register for a given port
*/
static volatile uint8_t* resolve_PIN_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
		return &PINA;
		break;
		case B_PORT:
		return &PINB;
		break;
		case C_PORT:
		return &PINC;
		break;
		case D_PORT:
		return &PIND;
		break;
		default:
		break;
	}
	return NULL;
}
/* init_pin:
* Initializes/changes data direction of given pin of a specific port 
* Arguments: 
*	GPIO_PORT port    => specified port where the pin occurs
*	uint8_t pin       => specified pin for which the data direction shall be modified
*	DATA_DIRECTION dd => data direction (input/output) for the specified pin
* Returns GPIO_STATE representing the operation status
*/
GPIO_STATE init_pin(GPIO_PORT port , uint8_t pin , DATA_DIRECTION dd){
	GPIO_STATE state = SUCCESS;
	volatile uint8_t *port_ptr = resolve_DD_port(port);
	
	if(port_ptr == NULL){
		state = FAILED;
		return state;
	}
	else if(pin >= IO_PORT_SIZE){
		state = INVALID_BIT;
		return state;
	}
	
	if(dd == OUTPUT)
		*port_ptr |= ( 1 << pin );
	else if(dd == INPUT)
		*port_ptr &= ~(1 << pin);
	else{
		//not supported
		state = FAILED;
	}
	return state;
}
/* set_pin:
* sets the logic or the internal resistor state of given pin of a specific port 
* Arguments:
*	GPIO_PORT port    => specified port where the pin occurs
*	uint8_t pin       => specified pin for which the state shall be modified
*	BIT_VALUE bit_val => logic state (HIGH / LOW / PULLUP_ON / PULLUP_OFF) for the specified pin
*	
* Returns GPIO_STATE representing the operation status
*/
GPIO_STATE set_pin(GPIO_PORT port , uint8_t pin , enum BIT_VALUE bit_val){
	GPIO_STATE state = SUCCESS;
	volatile uint8_t *dd_port_ptr = resolve_DD_port(port);
	volatile uint8_t *p_port_ptr = resolve_PORT_port(port);
	if(dd_port_ptr == NULL || p_port_ptr == NULL){
		state = FAILED;
		return state;
	}
	else if(pin >= IO_PORT_SIZE){
		state = INVALID_BIT;
		return state;
	}
	if(bit_val == PULLUP_ON || bit_val == PULLUP_OFF){
		if((*dd_port_ptr) & (1 << pin)){
			//the direction of pin is output instead of input ,doesn't make sense
			state = FAILED;
			
		}
		else if(bit_val == PULLUP_ON && (SFIOR & (1<<PUD)))
			//pull ups are disabled globally
			state = FAILED_DUE_PUD;
		
		else{
			if(bit_val == PULLUP_ON){
				*p_port_ptr |= (1<<pin);
				state = SUCCESS;
			}
			else if(bit_val == PULLUP_OFF){
				*p_port_ptr &= ~(1<<pin);
				state = SUCCESS;
			}
			else 
				state = FAILED;
		}
		
	}
	else{
		if(bit_val)
			*p_port_ptr |= (1<<pin);
		else
			*p_port_ptr &= ~(1<<pin);
		state = SUCCESS;
	}
	return state;
};
/* read_pin:
* reads signal on given pin of a specific port
* Arguments:
*	GPIO_PORT port    => specified port where the pin occurs
*	uint8_t pin       => specified pin for which the signal shall be fetched
*
* Returns the read bit..
*/
uint8_t read_pin(GPIO_PORT port , uint8_t pin ){
	volatile uint8_t * pin_port = resolve_PIN_port(port);
	if(pin_port == NULL)return -1;
	return (*pin_port) & (1<<pin);
}
