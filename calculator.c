/*
 * Name: Muhammad Hussein Muhammad Salem
 *
 */
#include "calculator.h"

void calculate_vid(s08 Num1[], s08 Num2[], u08 operator)
{
	s32 operand1, operand2, result = 0;
	s08 buffer[10];

	operand1 = convert_To_Int(Num1);
	operand2 = convert_To_Int(Num2);

	switch(operator)
	{
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case '/':
		result = operand1 / operand2;
		break;
	case '*':
		result = operand1 * operand2;
		break;
	}

	convert_To_String(buffer,result);

	H_LCD_vid_GotoRowCol(H_LCD_ROW1,H_LCD_COL00);

	H_LCD_vid_SendStr(buffer);

}

