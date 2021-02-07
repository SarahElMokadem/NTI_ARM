/*
 * KeyPad_config.h
 *
 *  Created on: Feb 7, 2021
 *      Author: Sarah
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#include "StdTypes.h"
#include "Utils.h"
#include "GPIO_interface.h"

#define         KEYPAD_PORT         	 DIO_U8_PORTB
/*******************     Row         *******************************/
#define         FIRST_OUTPUT   	         DIO_U8_PIN12
/*******************     Column      *******************************/
#define         FIRST_INPUT         	 DIO_U8_PIN8


//#define         KEY_DEFAULT         		 '.'

#endif /* KEYPAD_CONFIG_H_ */
