/*
 * STK_program.c
 *
 *  Created on: Feb 10, 2021
 *      Author: Sarah
 */


#include "StdTypes.h"
#include "Utils.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

#ifndef    NULL
#define    NULL       (void *)0
#endif

static void (*STK_PfCallBack)(void) = NULL;
static u8 STK_u8IntervalMode;

void STK_voidInit(void)
{
	/*              Prescaller                 */
#if (STK_PRESCALLER==STK_AHB_DIV_1)
	/* Processor clock divided by 8*/
	STK -> CTRL = 0x00000004;
	//SET_BIT(STK -> CTRL, 2);

#elif (STK_PRESCALLER==STK_AHB_DIV_8)
	/* Processor clock divided by 1*/
	STK -> CTRL = 0x00000000;
	//CLR_BIT(STK -> CTRL, 2);
#else
#error "Wrong Choice of SysTick Prescaller"
#endif
}

void STK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/*     Range Check on 24 Bits       */
	if(Copy_u32Ticks  <= 16777216)
	{
		/*     Load Number of Ticks         */
		STK -> LOAD = Copy_u32Ticks;
		/*     Start Timer                  */
		SET_BIT(STK->CTRL , 0);
		/*     Wait the Flag                */
		while( (GET_BIT(STK->CTRL,16) ) == 0)
		{
			asm("NOP");
		}
		/*     Stop Timer                   */
		CLR_BIT(STK->CTRL , 0);
		STK -> LOAD =0;
		STK -> VAL  =0;
	}
}
void STK_voidIntervalSingle(u32 Copy_u32Ticks,void (*copy_pf)(void))
{
	/*         Range Check on 24 Bits       */
	if(Copy_u32Ticks  <= 16777216)
	{
		/*     Load Number of Ticks         */
		STK -> LOAD = Copy_u32Ticks;
		/*     Start Timer                  */
		SET_BIT(STK->CTRL , 0);
		/*     Save CallBack                */
		STK_PfCallBack = copy_pf;
		/*     MODE                         */
		STK_u8IntervalMode = STK_SINGLE_INTERVAL;
		/*     Enable SysTick Interrupt     */
		SET_BIT(STK -> CTRL , 1);
	}
	else{/*  RETURN ERROR  */}
}
void STK_voidIntervalPeriodic(u32 Copy_u32Ticks,void (*copy_pf)(void))
{
	/*         Range Check on 24 Bits       */
	if(Copy_u32Ticks  <= 16777216)
	{
		/*     Load Number of Ticks         */
		STK -> LOAD = Copy_u32Ticks;
		/*     Start Timer                  */
		SET_BIT(STK->CTRL , 0);
		/*     Save CallBack                */
		STK_PfCallBack = copy_pf;
		/*     MODE                         */
		STK_u8IntervalMode = STK_PERIODIC_INTERVAL;
		/*     Enable SysTick Interrupt     */
		SET_BIT(STK -> CTRL , 1);
	}
	else{/*  RETURN ERROR  */}
}
void STK_voidStopInternal(void)
{
	/*     Disable Interrupt            */
	CLR_BIT(STK->CTRL , 1);
	/*     Stop Timer                   */
	CLR_BIT(STK->CTRL , 0);
	STK -> LOAD =0;
	STK -> VAL  =0;
}
u32 STK_u32GetCounts(void)
{
	u32 Local_u32Remaining = 0;
	Local_u32Remaining = (STK -> LOAD) - (STK -> VAL);
	return Local_u32Remaining;
}
u32 STK_u32GetRemainingTime(void)
{
	u32 Local_u32Remaining = 0;
	Local_u32Remaining = STK -> VAL;
	return Local_u32Remaining;
}

void SysTick_Handler(void)
{
	u8 Local_u8Temp=0;
	if(STK_u8IntervalMode == STK_SINGLE_INTERVAL)
	{
		/*     Disable Interrupt            */
		CLR_BIT(STK->CTRL , 1);
		/*     Stop Timer                   */
		CLR_BIT(STK->CTRL , 0);
		STK -> LOAD =0;
		STK -> VAL  =0;
	}
	/* DO whatever you do when Interrupt Fires   */
	STK_PfCallBack();
	/*   Clear the Flag by Reading the Flag   */
	Local_u8Temp=GET_BIT(STK -> CTRL , 16);

}


/*  CLearing the Flag by SW
 * 1- Flag = 1 ;
 * 2- Flag = 0;
 * 3- Read Flag ==> Flag = 0;
 * 4_ Write Flag ==> Flag = 0;
 */
