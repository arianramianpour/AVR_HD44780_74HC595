A simple library for HD44780 LCD connected to an 74HC595 witch i connected to an AVR Chip(tesetd on Atmega32a)

All setting and user commands are in lcd.h file

Example with PORTB [Click here to see](https://bin.hightechrobo.com/paste.php?id=329).

Example with PORTA [Click here to see](https://bin.hightechrobo.com/paste.php?id=330).

Example with CodeVisionAVR


```c
#include <mega32.h>
#include <delay.h>
#include "lcd_lib/lcd.h"


 
void main(void)
{

    lcd_init();
while (1)
      {
              lcd_clear();
              lcd_putchar('a'); 
              lcd_gotoxy(3,1);  
              lcd_puts("Hi i am arian");
              delay_ms(500);
              lcd_clear();
              lcd_puts("Hi i am arian");
              lcd_gotoxy(9,1);
              lcd_putchar('a'); 
              
              
              delay_ms(500);  


      }
}
```

