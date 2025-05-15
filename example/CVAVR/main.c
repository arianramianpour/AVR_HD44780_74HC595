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
