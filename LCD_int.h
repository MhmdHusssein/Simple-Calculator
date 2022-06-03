/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: HAL
 * Version: V1.0 - 02/10/2021
 *
 */

#ifndef _LCD_INT_H
#define _LCD_INT_H


#define H_LCD_ROW0     0
#define H_LCD_ROW1     1


#define H_LCD_COL00    0
#define H_LCD_COL01    1
#define H_LCD_COL02    2
#define H_LCD_COL03    3
#define H_LCD_COL04    4
#define H_LCD_COL05    5
#define H_LCD_COL06    6
#define H_LCD_COL07    7
#define H_LCD_COL08    8
#define H_LCD_COL09    9
#define H_LCD_COL10    10
#define H_LCD_COL11    11
#define H_LCD_COL12    12
#define H_LCD_COL13    13
#define H_LCD_COL14    14
#define H_LCD_COL15    15

/* Fucntions Prototype */

void H_LCD_vid_Init(void);
void H_LCD_vid_SendChar(u08 copy_u08_Char);
void H_LCD_vid_SendCmd (u08 copy_u08_Cmd );
void H_LCD_vid_SendStr (u08 *ptr_u08_Str );

void H_LCD_vid_ClrDisp ();

void H_LCD_vid_GotoRowCol (u08 copy_u08_RowId, u08 copy_u08_ColId );


#endif 
