/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: HAL
 * Version: V1.0 - 02/10/2021
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
#include "LCD_int.h"
#include "LCD_pri.h"

/* Functions Definitions */
void H_LCD_vid_Init(void)
{   
    /* 1. LCD Pin Directions */
	      /* Data Pins Directions */
	M_DIO_vid_WrtPorDir(M_DIO_PORTD, M_DIO_OUTPUT);
	      
		  /* Control Pins Directions */
		           /* Rs Pin */
	M_DIO_vid_WrtPinDir(M_DIO_PORTB, M_DIO_PIN0, M_DIO_OUTPUT);
	               /* R/W Pin */
	M_DIO_vid_WrtPinDir(M_DIO_PORTB, M_DIO_PIN1, M_DIO_OUTPUT);
	               /* Enable Pin */
	M_DIO_vid_WrtPinDir(M_DIO_PORTB, M_DIO_PIN2, M_DIO_OUTPUT);
	
	/* 2. Wait 30 ms */
	_delay_ms(30);
	
	/* 3. Select Function Set */
	H_LCD_vid_SendCmd(SET_8BTS_2LINES);
	
	/* 4. Wait 39 us */
	_delay_us(39);
	
	/* 5. Select ON/OFF Control */
	H_LCD_vid_SendCmd(DISPLAY_ON);
	
	/* 6. Wait 39 us */
	_delay_us(39);
	
	/* 7. Send Clear Command */
	H_LCD_vid_SendCmd(CLEAR_DISPLAY);
	
	/* 8. Wait 1.5 ms  */
	_delay_ms(1500);
	
	/* 9. Entry Mode Set */
	H_LCD_vid_SendCmd(ENTRY_MODE_SET);
	
}

void H_LCD_vid_SendChar(u08 copy_u08_Char)
{
	/* Set RS HIGH */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN0, M_DIO_HIGH);
	
	/* Set R/W as write(LOW) */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN1, M_DIO_LOW);
	
	/* Set E HIGH */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN2, M_DIO_HIGH);
	
	/*Send Command */
	M_DIO_vid_WrtPorVal(M_DIO_PORTD, copy_u08_Char);
	
	/* Set E LOW */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN2, M_DIO_LOW);
	
}
void H_LCD_vid_SendCmd (u08 copy_u08_Cmd )
{
	/* Set RS LOW */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN0, M_DIO_LOW);
	
	/* Set R/W as write(LOW) */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN1, M_DIO_LOW);
	
	/* Set E HIGH */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN2, M_DIO_HIGH);
	
	/*Send Command */
	M_DIO_vid_WrtPorVal(M_DIO_PORTD, copy_u08_Cmd);
	
	/* Set E LOW */
	M_DIO_vid_WrtPinVal(M_DIO_PORTB, M_DIO_PIN2, M_DIO_LOW);
	
}
void H_LCD_vid_SendStr (u08 *ptr_u08_Str )
{
	u08 Local_u08_Iterator = 0;
	while(ptr_u08_Str[Local_u08_Iterator] != '\0')
	{
		H_LCD_vid_SendChar(ptr_u08_Str[Local_u08_Iterator]);
		Local_u08_Iterator++;
	}
	
}

void H_LCD_vid_ClrDisp ()
{
	H_LCD_vid_SendCmd(CLEAR_DISPLAY);
}

void H_LCD_vid_GotoRowCol (u08 copy_u08_RowId, u08 copy_u08_ColId )
{
	u08 local_u08_GotoRowCol = 0;
	
	switch(copy_u08_RowId)
	{
		case H_LCD_ROW0: local_u08_GotoRowCol = 0x00 + copy_u08_ColId;  break;
		
		case H_LCD_ROW1: local_u08_GotoRowCol = 0x40 + copy_u08_ColId;  break;
	}
	
	H_LCD_vid_SendCmd (CURSOR_OFFEST | local_u08_GotoRowCol);
	
}
