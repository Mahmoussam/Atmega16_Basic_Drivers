/*
 * GPIO_types.h
 *  Author: unknown_developer
 * vital structures and types for GPIO 
 */ 


#ifndef GPIO_TYPES_H_
#define GPIO_TYPES_H_

/************************************************************************/
/* Enums and structures..                                               */
/************************************************************************/
// represents the result of modifying a GPIO register
typedef enum{
	SUCCESS,
	INVALID_BIT	,
	FAILED_DUE_PUD,
	FAILED
}GPIO_STATE;
typedef enum{
	INPUT,
	OUTPUT
}DATA_DIRECTION;

typedef enum{
	A_PORT,
	B_PORT,
	C_PORT,
	D_PORT
}GPIO_PORT;




#endif /* GPIO_TYPES_H_ */