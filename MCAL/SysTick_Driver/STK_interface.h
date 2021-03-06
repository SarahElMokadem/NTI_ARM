/*
 * STK_interface.h
 *
 *  Created on: Feb 10, 2021
 *      Author: Sarah
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_


void STK_voidInit(void);
void STK_voidSetBusyWait(u32 Copy_u32Ticks);
/*
void STK_voidEnableSTK(void);
void STK_voidEnableInterrupt(void);
*/
void STK_voidIntervalSingle(u32 Copy_u32Ticks,void (*copy_pf)(void));
void STK_voidIntervalPeriodic(u32 Copy_u32Ticks,void (*copy_pf)(void));
void STK_voidStopInternal(void);
u32 STK_u32GetCounts(void);
u32 STK_u32GetRemainingTime(void);



#endif /* STK_INTERFACE_H_ */
