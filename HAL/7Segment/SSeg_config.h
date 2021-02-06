/*
 * 7Seg_config.h
 *
 *  Created on: Feb 5, 2021
 *      Author: Sarah
 */

#ifndef SSEG_CONFIG_H_
#define SSEG_CONFIG_H_

/* Choose between 1-COMMON_CATHODE
 *                2-COMMON_ANODE
 */
#define      SSEG_COMMON_TYPE     COMMON_CATHODE

/* Choose number of Segments u want to use 1- 1
 *                                         2- 2
 *
 */
#define      SSEG_NUMBERS         1


/* In case 2 Seven segment choose which ports*/
#define      SSEG1_NUMBERS         DIO_U8_PORTA
#define      SSEG2_NUMBERS         DIO_U8_PORTB

/* Choose Which Port 1- DIO_U8_PORTA
 *                   2- DIO_U8_PORTB
 *                   3- DIO_U8_PORTC
 */
#define      SSEG_PORT            DIO_U8_PORTA



#endif /* SSEG_CONFIG_H_ */
