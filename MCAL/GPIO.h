/*
 * GPIO.h
 *  Author: da_unknown_developer
 */ 


#ifndef GPIO_H_
#define GPIO_H_

/************************************************************************/
/* Includes                                                             */
/************************************************************************/

#include "atmega16_sfrs.h"
#include "utils_basic.h"
#include "GPIO_types.h"

/************************************************************************/
/* Functions Declarations                                               */
/************************************************************************/
GPIO_STATE init_pin(GPIO_PORT port , uint8_t pin , DATA_DIRECTION dd);
GPIO_STATE set_pin(GPIO_PORT port , uint8_t pin , enum BIT_VALUE bit_val);
uint8_t read_pin(GPIO_PORT port , uint8_t pin);



#endif /* GPIO_H_ */