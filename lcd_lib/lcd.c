#ifndef _LCD_H
#define _LCD_H


#define LCD_PORT PORTA
#define LCD_DS 0
#define LCD_SH_CP   1
#define LCD_ST_CP   2

#pragma used+


void lcd_init();
void lcd_put_char(char c);
void lcd_puts(char *c);
void lcd_clear();
void lcd_gotoxy(char x , char y);


#pragma used-
#endif