/*
 * utils_basic.h
 *  Author: unknown_developer
 * Defines basic and vital types and macros for all upper layers.
 */ 


#ifndef UTILS_BASIC_H_
#define UTILS_BASIC_H_


#include "Platform_Types.h"

#ifndef NULL
#define NULL 0
#endif
#include "Platform_Types.h"

enum BIT_VALUE{
	HIGH = 1,
	ON = 1,
	ONE = 1,
	LOW = 0,
	OFF = 0,
	ZERO = 0,
	PULLUP_ON = 2,
	PULLUP_OFF = 3
};




#endif /* UTILS_BASIC_H_ */