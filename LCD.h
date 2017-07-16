/*
 * LCD.h
 *
 * Created: 6/14/2017 7:47:26 PM
 * Author: MOHAMED YOUSEF
 */ 

#ifndef LCD_H_
#define LCD_H_

#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char byte;

#define SET_BIT(reg, index) reg |= (1 << index)
#define CLR_BIT(reg, index) reg &= (~(1 << index))
#define GET_BIT(reg, index) ((reg >> index) & 0x01)
#define TOG_BIT(reg, index)	reg ^= (1 << index)

#define LCD_data_ddr  DDRA
#define LCD_data_port PORTA
#define LCD_data_pin  PINA

#define LCD_con_ddr  DDRB	
#define LCD_con_port PORTB
#define LCD_con_pin  PINB

#define LCD_RS  0
#define LCD_RW 1
#define LCD_enable  1

void LCD_init(void);
void LCD_send_command(byte command);
void LCD_send_data(byte data);
void LCD_print_string(byte *string);
void LCD_clear(void);


#endif /* LCD_H_ */
