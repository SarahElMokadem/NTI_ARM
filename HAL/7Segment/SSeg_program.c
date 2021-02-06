/*
 * 7Seg_program.c
 *
 *  Created on: Feb 5, 2021
 *      Author: Sarah
 */

#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "SSeg_interface.h"
#include "SSeg_config.h"

/*Array to Display the numbers and the Hex numbers*/
static u8 segCathode[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
static u8 segCathodeHEX[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

static u8 segAnode[]={0xC0 , 0xF9 , 0xA4 , 0xB0 , 0x99 , 0x92 , 0x82,0xf8, 0x80,0x90};
static u8 segAnodeHEX[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
/****************************************************/

#if(SSEG_COMMON_TYPE==COMMON_CATHODE)

  #if(SSEG_NUMBERS==1)

  void SSEG_VoidDisplayNumber(u8 number)
  {
  	DIO_voidSetPortValue(SSEG_PORT,segCathode[number]);
  }

  void SSEG_VoidDisplayHex(u8 number)
  {
  	DIO_voidSetPortValue(SSEG_PORT,segCathodeHEX[number]);
  }
  #elif(SSEG_NUMBERS==2)
  void SSEG_VoidDisplayNumber(u8 number)
  {
  	DIO_voidSetPortValue(SSEG1_PORT,segCathode[number/10]);
  	DIO_voidSetPortValue(SSEG2_PORT,segCathode[number%10]);
  }

  void SSEG_VoidDisplayHex(u8 number)
  {
  	DIO_voidSetPortValue(SSEG1_PORT,segCathodeHEX[number%10]);
  	DIO_voidSetPortValue(SSEG2_PORT,segCathodeHEX[number%10]);
  }
  #endif

#elif(SSEG_COMMON_TYPE==COMMON_ANODE)

  #if(SSEG_NUMBERS==1)

  void SSEG_VoidDisplayNumber(u8 number)
  {
  	DIO_voidSetPortValue(SSEG_PORT,segAnode[number]);
  }

  void SSEG_VoidDisplayHex(u8 number)
  {
  	DIO_voidSetPortValue(SSEG_PORT,segAnodeHEX[number]);
  }
  #elif(SSEG_NUMBERS==2)

  void SSEG_VoidDisplayNumber(u8 number)
  {
  	DIO_voidSetPortValue(SSEG1_PORT,segAnode[number/10]);
  	DIO_voidSetPortValue(SSEG2_PORT,segAnode[number%10]);
  }

  void SSEG_VoidDisplayHex(u8 number)
  {
  	DIO_voidSetPortValue(SSEG1_PORT,~segAnodeHEX[number%10]);
  	DIO_voidSetPortValue(SSEG2_PORT,~segAnodeHEX[number%10]);
  }
  #endif

#endif
