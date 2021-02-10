/*
 * EXTI_private.h
 *
 *  Created on: Feb 8, 2021
 *      Author: Boon
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

typedef struct
{
	volatile u32 	IMR;
	volatile u32	EMR;
	volatile u32 	RTSR;
	volatile u32	FTSR;
	volatile u32 	SWIER;
	volatile u32	PR;

}EXTI_Type;

/*          Pointer to Struct
 *          this can make you point to any address of any element in the structure by making arrow(->)
 *          so when we move by 1 this means we move by 4 bytes              */
#define 	EXTI 		((EXTI_Type *)0x40010400)

#define 	EXTI_FALLING			1
#define 	EXTI_RISING				3
#define 	EXTI_IOC				5

#endif /* EXTI_PRIVATE_H_ */
