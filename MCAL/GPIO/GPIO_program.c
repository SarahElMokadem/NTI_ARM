/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: Sarah
 */

#include "StdTypes.h"
#include "Utils.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void	DIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Mode)
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
				GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOA_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		case DIO_U8_PORTB:
			if(Copy_u8PinID< 8)
			{
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOB_CRL &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOB_CRL |= ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOB_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOB_CRH |= ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		case DIO_U8_PORTC:
			if(Copy_u8PinID< 8)
			{
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOC_CRL &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOC_CRL |= ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			/*        HIGH PORT          */
			else
			{
				Copy_u8PinID-=8;
				/* To deal With Bit Masking      1- Clear a specific Bits 2- Assign a specific Bits */
				GPIOC_CRH &= ~((u32)(0b1111)     <<Copy_u8PinID * 4) ;
				GPIOC_CRH |= ((u32)(Copy_u8Mode)<<Copy_u8PinID * 4) ;
			}
			break;
		}
	}else {/*Return ERROR*/}
}

void	DIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8Value)
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
				GPIOA_BSRR= (1<<Copy_u8PinID);
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
					GPIOB_BSRR= (1<<Copy_u8PinID);
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
						GPIOC_BSRR= (1<<Copy_u8PinID);
						//SET_BIT(GPIOC_ODR,Copy_u8PinID);
						break;
					case DIO_U8_LOW:
						GPIOC_BRR= (1<<Copy_u8PinID);
						//CLR_BIT(GPIOC_ODR,Copy_u8PinID);
						break;
					default:; /* Return ERROR */
					}
					break;
		}
	}else {/*Return ERROR*/}
}

u8	DIO_u8GetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
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


void DIO_voidSetPortDirection( u8 Copy_u8PortID , u8 Copy_u8Part , u8 Copy_u8Mode )
{/*           Range Check        */
	if(Copy_u8PortID<3)
	{
		switch( Copy_u8PortID )
		{
		case DIO_U8_PORTA:

			if(Copy_u8Part == LOW)
			{
				GPIOA_CRL = ( 0x11111111 * Copy_u8Mode );
			}
			else if(Copy_u8Part == HIGH)
			{
				GPIOA_CRH = ( 0x11111111 * Copy_u8Mode ) ;
			}
			break;
		case DIO_U8_PORTB:

			if( Copy_u8Part == LOW  )
			{
				GPIOB_CRL = ( 0x11111111 * Copy_u8Mode );
			}
			else if( Copy_u8Part == HIGH )
			{
				GPIOB_CRH = ( 0x11111111 * Copy_u8Mode );
			}
			break;
		case DIO_U8_PORTC:

			if(Copy_u8Part == LOW)
			{
				GPIOC_CRL = (0x11111111 * Copy_u8Mode );
			}
			else if ( Copy_u8Part == HIGH )
			{
				GPIOC_CRH = ( 0x11111111 * Copy_u8Mode );
			}
			break;
		}
	}else{/* RETURN ERROR */}
}


void DIO_voidSetPortValue( u8 Copy_u8PortID , u8 Copy_u8Part , u16 Copy_u16Value )
{
	/*           Range Check        */
	if(Copy_u8PortID<3)
	{
		switch( Copy_u8PortID )
		{
		case DIO_U8_PORTA:

			if( Copy_u8Part == LOW  )
			{
				GPIOA_ODR = (GPIOA_ODR & 0xFF00 ) | ( (u8)Copy_u16Value );
			}
			else if( Copy_u8Part == HIGH )
			{
				GPIOA_ODR = (GPIOA_ODR & 0x00FF ) | ( (u16)Copy_u16Value );
			}

			break;
		case DIO_U8_PORTB:

			if( Copy_u8Part == LOW  )
			{
				GPIOB_ODR = (GPIOB_ODR & 0xFF00 ) | ( (u8)Copy_u16Value );
			}
			else if( Copy_u8Part == HIGH )
			{
				GPIOB_ODR = (GPIOB_ODR & 0x00FF ) | ( (u16)Copy_u16Value );

			}

			break;
		case DIO_U8_PORTC:

			if(Copy_u8Part == LOW)
			{
				GPIOC_ODR = (GPIOC_ODR & 0xFF00 ) | ( (u8)Copy_u16Value );
			}
			else if  (Copy_u8Part == HIGH )
			{
				GPIOC_ODR = (GPIOC_ODR & 0x00FF ) | ( (u16)Copy_u16Value );
			}
			break;
		}
	}else{/* RETURN ERROR */}
}

u16 DIO_u16GetPortValue( u8 Copy_u8PortID , u8 Copy_u8Part )
{

	u16 Local_u16Value = 0xFFFF;
	/*       Range Check     */
	if(Copy_u8PortID<3)
	{
		switch( Copy_u8PortID )
		{
		case DIO_U8_PORTA:

			Local_u16Value = GPIOA_IDR;
			if( Copy_u8Part == LOW  )
			{
				Local_u16Value &= 0x00FF;
			}
			else if( Copy_u8Part == HIGH )
			{
				Local_u16Value &= 0xFF00;
			}

			break;
		case DIO_U8_PORTB:

			Local_u16Value = GPIOB_IDR;
			if( Copy_u8Part == LOW  )
			{
				Local_u16Value &= 0x00FF;
			}
			else if( Copy_u8Part == HIGH )
			{
				Local_u16Value &= 0xFF00;
			}

			break;
		case DIO_U8_PORTC:

			Local_u16Value = GPIOC_IDR;
			if      ( Copy_u8Part == LOW  )
			{
				Local_u16Value &= 0x00FF;
			}
			else if ( Copy_u8Part == HIGH )
			{
				Local_u16Value &= 0xFF00;
			}

			break;
		}
	}
	return Local_u16Value;
}


void DIO_voidTogglePin(u8 Copy_u8PortID, u8 Copy_u8PinID)
{
	/*           Range Check        */
	if(Copy_u8PortID<3)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8_PORTA:
			TOG_BIT(GPIOA_ODR, Copy_u8PinID);
			break;
		case DIO_U8_PORTB:
			TOG_BIT(GPIOB_ODR, Copy_u8PinID);
			break;
		case DIO_U8_PORTC:
			TOG_BIT(GPIOC_ODR, Copy_u8PinID);
			break;
		}
	}else{/*  RETRUN ERROR   */}
}
