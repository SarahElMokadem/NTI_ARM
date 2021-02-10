/*
 * NVIC_config.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Sarah
 */

#ifndef NVIC_CONFIG_H_
#define NVIC_CONFIG_H_

/* NUM_GROUPS_AND_SUB can be:-
 * GROUPS_16_SUB_0
   GROUPS_8_SUB_2
   GROUPS_4_SUB_4  //group 2 bit
   GROUPS_2_SUB_8  //group 1 bit
   GROUPS_0_SUB_16
 *
 */

#define    NUM_GROUPS_AND_SUB        GROUPS_4_SUB_4

#endif /* NVIC_CONFIG_H_ */
