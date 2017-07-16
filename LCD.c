/*
 * LCD.c
 *
 * Created: 6/14/2017 7:47:36 PM
 * Author: MOHAMED YOUSEF
 */ 

#include "LCD.h"

void LCD_init(void){
	LCD_data_ddr = 0xFF;
	LCD_data_port = 0x00;
	
	LCD_con_ddr = 0xFF;
	LCD_con_port = 0x00;
	_delay_ms(2);
	LCD_send_command(0x38);
	LCD_send_command(0x0C);
	_delay_ms(2);
}

void LCD_send_command(byte command){
	LCD_data_port = command;
	
	CLR_BIT(LCD_con_port, 0); //rs = 0
	CLR_BIT(LCD_con_port, 1); //rw = 0
	
	//enable - high and low
	CLR_BIT(LCD_con_port, 2);
	_delay_us(1000);
	SET_BIT(LCD_con_port, 2);
	
	_delay_ms(5);
}

void LCD_send_data(byte data){
	LCD_data_port = data;
	
	SET_BIT(LCD_con_port, 0); //rs = 1
	CLR_BIT(LCD_con_port, 1); //rw = 0
	
	//enable - high and low
	CLR_BIT(LCD_con_port, 2);
	_delay_us(1);
	SET_BIT(LCD_con_port, 2);
	
	_delay_ms(5);
}

void LCD_print_string(byte *string){
	while (*string != '\0'){
		LCD_send_data(*string);
		string++;
	}	
}

void LCD_clear(void){
	LCD_send_command(0x02);
}
