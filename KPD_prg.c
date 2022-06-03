/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: HAL
 * Version: V1.0 - 09/10/2021
 *
 */

/* Files Inclusion */

/* 1. User Defined Libraries */
#include "STD_TYPE.h"
#include "BIT_MATH.h"

/* 2.Standard Libraries */
#include "util/delay.h"

/* 3. MCAL Files */
#include "DIO_int.h"

/* 4. HAL Files */
#include "KPD_int.h"
#include "KPD_pri.h"

/* Functions Definitions */

void H_KPD_vid_Init(void)
{
	/* Set Col as OUTPUT HIGH */
	for(u08 local_u08_COLS=0; local_u08_COLS<4; local_u08_COLS++)
	{
		M_DIO_vid_WrtPinDir(M_DIO_PORTA,local_u08_COLS,M_DIO_OUTPUT);
		M_DIO_vid_WrtPinVal(M_DIO_PORTA,local_u08_COLS,M_DIO_HIGH);
	}
	
	/* Set ROWS as INPUT Pulled Up */
	for(u08 local_u08_ROWS=4; local_u08_ROWS<8; local_u08_ROWS++)
	{
		M_DIO_vid_WrtPinDir(M_DIO_PORTA,local_u08_ROWS,M_DIO_INPUT);
		M_DIO_vid_WrtPinVal(M_DIO_PORTA,local_u08_ROWS,M_DIO_HIGH);
	}
	
}

u08  H_KPD_U08_GetPressedKey(void)
{
	u08 local_u08_GetPressedKey = 0;
	
	for(u08 local_u08_COLS=0; local_u08_COLS<4; local_u08_COLS++)
	{
		/* Set current COL LOW */
		M_DIO_vid_WrtPinVal(M_DIO_PORTA,local_u08_COLS,M_DIO_LOW);

		/* Create loop for ROWS */
		for(u08 local_u08_ROWS=4; local_u08_ROWS<8; local_u08_ROWS++)
		{
			
			if(M_DIO_u08_RedPinVal(M_DIO_PORTA,local_u08_ROWS) == M_DIO_LOW)
			{
				/* Mapping */
				local_u08_GetPressedKey = global_arr_u08_KeypadMapping[local_u08_COLS][local_u08_ROWS - 4];
				
				/* Single pressed */
				while(M_DIO_u08_RedPinVal(M_DIO_PORTA,local_u08_ROWS) == M_DIO_LOW)
				{
					
					
				}
			}
		}
		
		/* Set current COL HIGH */
		M_DIO_vid_WrtPinVal(M_DIO_PORTA,local_u08_COLS,M_DIO_HIGH);

	}
	
	return local_u08_GetPressedKey;
}
