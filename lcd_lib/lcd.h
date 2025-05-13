#ifndef _LCD_H
#define _LCD_H


#define LCD_PORT PORTA  //Set the port
#define LCD_DDR DDRA    //set the DDR
#define LCD_DS 0        //DS Connceted to atmegapin
#define LCD_SH_CP   1   //SH_CP Connceted to atmegapin
#define LCD_ST_CP   2   //ST_CP Connceted to atmegapin

#pragma used+


void lcd_init();                    //You only need to run this once and its should run before all other commands 
void lcd_put_char(char c);          //This is used to print one character on lcd
void lcd_puts(char *c);             //This is used to print an string on lcd
void lcd_clear();                   //This will clear the lcd and return the cursor to 0,0
void lcd_gotoxy(char x , char y);   //This will force the cursor to print on selected x and y


#pragma used-
#endif