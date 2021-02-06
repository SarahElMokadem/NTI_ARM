/*
 * 7Seg_interface.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Sarah
 */

#ifndef SSEG_INTERFACE_H_
#define SSEG_INTERFACE_H_

#include "StdTypes.h"

#define COMMON_CATHODE    0
#define COMMON_ANODE      1


void SSEG_VoidDisplayNumber(u8 number);
void SSEG_VoidDisplayHex(u8 number);



#endif /* SSEG_INTERFACE_H_ */
