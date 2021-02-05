/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Sarah
 */

#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

void DIO_voidSetPinDirection(DIO_enuPort_type Copy_u8PortID,DIO_enuPin_type Copy_u8PinID,DIO_enuPinMode_type Copy_u8Mode)
{
	/*           Range Check        */
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16)  )
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			/*        LOW PORT           */
			if(Copy_u8PinID< 8)
			{
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOA_CRL &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOA_CRL |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOA_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOA_CRH |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		case DIO_U8_PORTB:
			if(Copy_u8PinID< 8)
			{
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOB_CRL &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOB_CRL |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOB_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOB_CRH |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		case DIO_U8_PORTC:
			if(Copy_u8PinID< 8)
			{
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOC_CRL &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOC_CRL |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOC_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOC_CRH |= ~((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		}
	}else {/*Return ERROR*/}
}

void DIO_voidSetPinValue(DIO_enuPort_type Copy_u8PortID,DIO_enuPin_type Copy_u8PinID,DIO_enuPinValue_type Copy_u8Value)
{
	/*           Range Check        */
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16)  )
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			switch(Copy_u8Value)
			{
			case DIO_U8_HIGH:
				GPIOA_BSRR= (1<Copy_u8PinID);
				//SET_BIT(GPIOA_ODR,Copy_u8PinID);
				break;
			case DIO_U8_LOW:
				GPIOA_BRR= (1<<Copy_u8PinID);
				//CLR_BIT(GPIOA_ODR,Copy_u8PinID);
				break;
			default:; /* Return ERROR */
			}
			break;
			case DIO_U8_PORTB:
				switch(Copy_u8Value)
				{
				case DIO_U8_HIGH:
					GPIOB_BSRR= (1<Copy_u8PinID);
					//SET_BIT(GPIOB_ODR,Copy_u8PinID);
					break;
				case DIO_U8_LOW:
					GPIOB_BRR= (1<<Copy_u8PinID);
					//CLR_BIT(GPIOB_ODR,Copy_u8PinID);
					break;
				default:; /* Return ERROR */
				}
				break;
				case DIO_U8_PORTC:
					switch(Copy_u8Value)
					{
					case DIO_U8_HIGH:
						GPIOA_BSRR= (1<Copy_u8PinID);
						//SET_BIT(GPIOC_ODR,Copy_u8PinID);
						break;
					case DIO_U8_LOW:
						GPIOA_BRR= (1<<Copy_u8PinID);
						//CLR_BIT(GPIOC_ODR,Copy_u8PinID);
						break;
					default:; /* Return ERROR */
					}
					break;
		}
	}else {/*Return ERROR*/}
}

u8 DIO_u8GetPinValue(DIO_enuPort_type Copy_u8PortID,DIO_enuPin_type Copy_u8PinID)
{
	u8 Local_u8Value = 0xFF;
	/*           Range Check        */
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16)  )
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			Local_u8Value = GET_BIT(GPIOA_IDR,Copy_u8PinID);
			break;
		case DIO_U8_PORTB:
			Local_u8Value = GET_BIT(GPIOB_IDR,Copy_u8PinID);
			break;
		case DIO_U8_PORTC:
			Local_u8Value = GET_BIT(GPIOC_IDR,Copy_u8PinID);
			break;
		}
	}else {/*Return ERROR*/}
	return Local_u8Value;
}

void DIO_voidSetPortDirection(DIO_enuPort_type Copy_u8PortID ,DIO_enuPinMode_type  Copy_u8Mode)
{
	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			GPIOA_CRL = ( 0xFF * Copy_u8Mode ) ;
			GPIOA_CRH = ( 0xFF * Copy_u8Mode ) ;
			break;
		case DIO_U8_PORTB:
			GPIOB_CRL = ( 0xFF * Copy_u8Mode ) ;
			GPIOB_CRH = ( 0xFF * Copy_u8Mode ) ;
			break;
		case DIO_U8_PORTC:
			GPIOC_CRL = ( 0xFF * Copy_u8Mode ) ;
			GPIOC_CRH = ( 0xFF * Copy_u8Mode ) ;
			break;
		}
	}
}

void DIO_voidSetPortValue(DIO_enuPort_type Copy_u8PortID , u16  Copy_u16Value)
{
	/*           Range Check        */
	if(Copy_u8PortID<3)
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			GPIOA_ODR= Copy_u16Value;
			break;
		case DIO_U8_PORTB:
			GPIOB_ODR= Copy_u16Value;
			break;
		case DIO_U8_PORTC:
			GPIOC_ODR= Copy_u16Value;
			break;
		}
	}else {/*Return ERROR*/}
}

u16 DIO_u16GetPortValue(DIO_enuPort_type Copy_u8PortID)
{
	u16 Local_u16Value = 0xFFFF;
	if(Copy_u8PortID<3)
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			Local_u16Value = GPIOA_ODR;
			break;
		case DIO_U8_PORTB:
			Local_u16Value = GPIOB_ODR;
			break;
		case DIO_U8_PORTC:
			Local_u16Value = GPIOC_ODR;
			break;
		}
	}else {/*Return ERROR*/}
	return Local_u16Value;
}
