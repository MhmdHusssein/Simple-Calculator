/*
 * Name: Muhammad Hussein Muhammad Salem
 *
 */
/* Simple Calculator / Keypad and LCD */

#define NOT_PRESSED    0

/* Files Inclusion */

/* 1. User Defined Libraries */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "calculator.h"
#include "conversion_functions.h"

/* 2.Standard Libraries */
#include "util/delay.h"

/* 3. MCAL Files */
#include "DIO_int.h"

/* 4. HAL Files */
#include "LCD_int.h"
#include "KPD_int.h"

int main()
{
	s08 local_s08_Num1[5] = {NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED};
	s08 local_s08_Num2[5] = {NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED,NOT_PRESSED};
	u08 local_u08_Operator=0;
	u08 local_u08_Iterator1=0;
	u08 local_u08_Iterator2=0;
	u08 local_u08_Result = 0;

	H_LCD_vid_Init();
	H_KPD_vid_Init();

	while(1)
	{
		do{
			local_s08_Num1[local_u08_Iterator1] = H_KPD_U08_GetPressedKey();
		}while(local_s08_Num1[local_u08_Iterator1] == NOT_PRESSED);

		H_LCD_vid_SendChar(local_s08_Num1[local_u08_Iterator1]);
		local_u08_Iterator1++;
		_delay_ms(200);

		while(1)
		{
			do{
				local_s08_Num1[local_u08_Iterator1] = H_KPD_U08_GetPressedKey();
			}while(local_s08_Num1[local_u08_Iterator1] == NOT_PRESSED);

			H_LCD_vid_SendChar(local_s08_Num1[local_u08_Iterator1]);

			if(local_s08_Num1[local_u08_Iterator1] == '+')
			{
				local_u08_Operator = '+';
				local_s08_Num1[local_u08_Iterator1] = '\0';
				break;

			}else if(local_s08_Num1[local_u08_Iterator1] == '-')
			{
				local_u08_Operator = '-';
				local_s08_Num1[local_u08_Iterator1] = '\0';
				break;

			}else if(local_s08_Num1[local_u08_Iterator1] == '*')
			{
				local_u08_Operator = '*';
				local_s08_Num1[local_u08_Iterator1] = '\0';
				break;

			}else if(local_s08_Num1[local_u08_Iterator1] == '/')
			{
				local_u08_Operator = '/';
				local_s08_Num1[local_u08_Iterator1] = '\0';
				break;

			}

			local_u08_Iterator1++;
			_delay_ms(200);

		}

		do{
			local_s08_Num2[local_u08_Iterator2] = H_KPD_U08_GetPressedKey();
		}while(local_s08_Num2[local_u08_Iterator2] == NOT_PRESSED);

		H_LCD_vid_SendChar(local_s08_Num2[local_u08_Iterator2]);
		local_u08_Iterator2++;
		_delay_ms(200);

		while(1)
		{
			do{
				local_s08_Num2[local_u08_Iterator2] = H_KPD_U08_GetPressedKey();
			}while(local_s08_Num2[local_u08_Iterator2] == NOT_PRESSED);

			H_LCD_vid_SendChar(local_s08_Num2[local_u08_Iterator2]);

			if(local_s08_Num2[local_u08_Iterator2] == '=')
			{
				local_u08_Result = '=';
				local_s08_Num2[local_u08_Iterator2] = '\0';
				break;
			}

			local_u08_Iterator2++;
			_delay_ms(200);

		}

		calculate_vid(local_s08_Num1,local_s08_Num2,local_u08_Operator);

		_delay_ms(2500);
		H_LCD_vid_ClrDisp();
		_delay_ms(200);

		local_u08_Iterator1=0;
		local_u08_Iterator2=0;

	}


	return 0;
}
