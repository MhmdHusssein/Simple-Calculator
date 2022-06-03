/*
 * Name: Muhammad Hussein Muhammad Salem
 * Layer: MCAL
 * Version: V1.0 - 01/10/2021
 *
 */
 
#ifndef _DIO_INT_H
#define _DIO_INT_H

/* copy_u08_PortId */
#define M_DIO_PORTA    0
#define M_DIO_PORTB    1
#define M_DIO_PORTC    2
#define M_DIO_PORTD    3

/* copy_u08_PinId */
#define M_DIO_PIN0     0
#define M_DIO_PIN1     1
#define M_DIO_PIN2     2
#define M_DIO_PIN3     3
#define M_DIO_PIN4     4
#define M_DIO_PIN5     5
#define M_DIO_PIN6     6
#define M_DIO_PIN7     7

/* copy_u08_DirId */
#define M_DIO_INPUT    0
#define M_DIO_OUTPUT   1

/* copy_u08_ValId */
#define M_DIO_LOW    0
#define M_DIO_HIGH   1


/*
 * Public Function Prototype
 */

void M_DIO_vid_WrtPinDir(u08 copy_u08_PortId, u08 copy_u08_PinId, u08 copy_u08_DirId);
void M_DIO_vid_WrtPinVal(u08 copy_u08_PortId, u08 copy_u08_PinId, u08 copy_u08_ValId);

u08  M_DIO_u08_RedPinVal(u08 copy_u08_PortId, u08 copy_u08_PinId);

void M_DIO_vid_WrtPorDir(u08 copy_u08_PortId, u08 copy_u08_DirId);
void M_DIO_vid_WrtPorVal(u08 copy_u08_PortId, u08 copy_u08_ValId);


#endif