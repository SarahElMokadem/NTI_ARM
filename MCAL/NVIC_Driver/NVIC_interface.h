/*
 * NVIC_interface.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Sarah
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void NVIC_voidInit(void);
void NVIC_voidEnableInterrupt(u8 Copy_u8InteruptNumber);
void NVIC_voidDisableInterrupt(u8 Copy_u8InteruptNumber);

void NVIC_voidSetPendingFlag(u8 Copy_u8InteruptNumber);
void NVIC_voidClearPendingFlag(u8 Copy_u8InteruptNumber);

u8 NVIC_u8GetActiveFlag(u8 Copy_u8InteruptNumber);

void NVIC_voidSetPriority(u8 Copy_u8PerID , u8 Copy_PerPriority);

#endif /* NVIC_INTERFACE_H_ */
