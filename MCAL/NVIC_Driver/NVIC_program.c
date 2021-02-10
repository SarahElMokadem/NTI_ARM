/*
 * NVIC_program.c
 *
 *  Created on: Feb 7, 2021
 *      Author: Sarah
 */

#include "StdTypes.h"
#include "Utils.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void NVIC_voidInit(void)
{
	/*         Number of Groups and Sub Groups               */
#ifndef    SCB_AIRCR
#define    SCB_AIRCR      (*((u32 *)(0xE000ED00 + 0x0C)))
#endif
	/*  2 Groups & 2 Sub */
	SCB_AIRCR = NUM_GROUPS_AND_SUB;
}

void NVIC_voidEnableInterrupt(u8 Copy_u8InteruptNumber)
{
	if(Copy_u8InteruptNumber<32)
	{
		NVIC_ISER0 = ( 1 << Copy_u8InteruptNumber);
	}
	else if(Copy_u8InteruptNumber<60)
	{
		Copy_u8InteruptNumber -= 32;
		NVIC_ISER1 = ( 1 << Copy_u8InteruptNumber);
	}
	else{/*    Return ERROR    */}
}

void NVIC_voidDisableInterrupt(u8 Copy_u8InteruptNumber)
{
	if(Copy_u8InteruptNumber<32)
	{
		NVIC_ICER0 = ( 1 << Copy_u8InteruptNumber);
	}
	else if(Copy_u8InteruptNumber<60)
	{
		Copy_u8InteruptNumber -= 32;
		NVIC_ICER1 = ( 1 << Copy_u8InteruptNumber);
	}
	else{/*    Return ERROR    */}
}

void NVIC_voidSetPendingFlag(u8 Copy_u8InteruptNumber)
{
	if(Copy_u8InteruptNumber<32)
	{
		NVIC_ISPR0 = ( 1 << Copy_u8InteruptNumber);
	}
	else if(Copy_u8InteruptNumber<60)
	{
		Copy_u8InteruptNumber -= 32;
		NVIC_ISPR1 = ( 1 << Copy_u8InteruptNumber);
	}
	else{/*    Return ERROR    */}
}
void NVIC_voidClearPendingFlag(u8 Copy_u8InteruptNumber)
{
	if(Copy_u8InteruptNumber<32)
	{
		NVIC_ICPR0 = ( 1 << Copy_u8InteruptNumber);
	}
	else if(Copy_u8InteruptNumber<60)
	{
		Copy_u8InteruptNumber -= 32;
		NVIC_ICPR1 = ( 1 << Copy_u8InteruptNumber);
	}
	else{/*    Return ERROR    */}
}

u8 NVIC_u8GetActiveFlag(u8 Copy_u8InteruptNumber)
{
	u8 Local_u8Active = 0xFF;

	if(Copy_u8InteruptNumber<32)
	{
		Local_u8Active = GET_BIT(NVIC_IABR0 , Copy_u8InteruptNumber);
	}
	else if(Copy_u8InteruptNumber<60)
	{
		Copy_u8InteruptNumber -= 32;
		Local_u8Active = GET_BIT(NVIC_IABR1 , Copy_u8InteruptNumber);
	}
	else{/*    Return ERROR    */}

	return Local_u8Active;
}

void NVIC_voidSetPriority(u8 Copy_u8InteruptNumber , u8 Copy_PerPriority)
{
	if(Copy_u8InteruptNumber < 60)
	{
		/*        Bits From 4 : 7       */
		NVIC_IPR[Copy_u8InteruptNumber] = (Copy_PerPriority<<4);
	}
	else{/*    Return ERROR    */}
}
