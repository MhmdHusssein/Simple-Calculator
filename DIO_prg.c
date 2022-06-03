/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: MCAL
 * Version: V1.0 - 01/10/2021
 *
 */
 
/* Files Inclusion */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
 
#include "DIO_int.h"
#include "DIO_reg.h"
  
/*
 * Public Function Prototype
 */

void M_DIO_vid_WrtPinDir(u08 copy_u08_PortId, u08 copy_u08_PinId, u08 copy_u08_DirId)
{
	switch(copy_u08_PortId)
	{
		case M_DIO_PORTA: WRT_BIT(DDRA, copy_u08_PinId, copy_u08_DirId); break;
		case M_DIO_PORTB: WRT_BIT(DDRB, copy_u08_PinId, copy_u08_DirId); break;
		case M_DIO_PORTC: WRT_BIT(DDRC, copy_u08_PinId, copy_u08_DirId); break;
		case M_DIO_PORTD: WRT_BIT(DDRD, copy_u08_PinId, copy_u08_DirId); break;
		default: /* ERROR */ break;
		
	}
	
}

void M_DIO_vid_WrtPinVal(u08 copy_u08_PortId, u08 copy_u08_PinId, u08 copy_u08_ValId)
{
	switch(copy_u08_PortId)
	{
		case M_DIO_PORTA: WRT_BIT(PORTA, copy_u08_PinId, copy_u08_ValId); break;
		case M_DIO_PORTB: WRT_BIT(PORTB, copy_u08_PinId, copy_u08_ValId); break;
		case M_DIO_PORTC: WRT_BIT(PORTC, copy_u08_PinId, copy_u08_ValId); break;
		case M_DIO_PORTD: WRT_BIT(PORTD, copy_u08_PinId, copy_u08_ValId); break;
		default: /* ERROR */ break;
		
	}
	
	
}

u08  M_DIO_u08_RedPinVal(u08 copy_u08_PortId, u08 copy_u08_PinId)
{
	u08 local_u08_PinVal = 0;
	
	switch(copy_u08_PortId)
	{
		case M_DIO_PORTA: local_u08_PinVal = GET_BIT(PINA, copy_u08_PinId); break;
		case M_DIO_PORTB: local_u08_PinVal = GET_BIT(PINB, copy_u08_PinId); break;
		case M_DIO_PORTC: local_u08_PinVal = GET_BIT(PINC, copy_u08_PinId); break;
		case M_DIO_PORTD: local_u08_PinVal = GET_BIT(PIND, copy_u08_PinId); break;
		default: /* ERROR */ break;
		
	}
	
	return local_u08_PinVal;
}

void M_DIO_vid_WrtPorDir(u08 copy_u08_PortId, u08 copy_u08_DirId)
{
	if(copy_u08_DirId == M_DIO_OUTPUT)
	{
		switch(copy_u08_PortId)
		{
			case M_DIO_PORTA: DDRA = 0xff;          break;
			case M_DIO_PORTB: DDRB = 0xff;          break;
		    case M_DIO_PORTC: DDRC = 0xff;          break;
		    case M_DIO_PORTD: DDRD = 0xff;          break;		
		}	
	}else{
		switch(copy_u08_PortId)
		{
			case M_DIO_PORTA: DDRA = 0;             break;
			case M_DIO_PORTB: DDRB = 0;             break;
		    case M_DIO_PORTC: DDRC = 0;             break;
		    case M_DIO_PORTD: DDRD = 0;             break;		
		}
		
	}
}

void M_DIO_vid_WrtPorVal(u08 copy_u08_PortId, u08 copy_u08_ValId)
{
	switch(copy_u08_PortId)
		{
			case M_DIO_PORTA: PORTA = copy_u08_ValId;             break;
			case M_DIO_PORTB: PORTB = copy_u08_ValId;             break;
		    case M_DIO_PORTC: PORTC = copy_u08_ValId;             break;
		    case M_DIO_PORTD: PORTD = copy_u08_ValId;             break;		
		}
	
}
 
 