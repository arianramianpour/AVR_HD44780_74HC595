#include <mega32.h>
#include <delay.h>
#include "lcd.h"


 
void main(void)
{

          
          
              lcd_init();
              lcd_puts("Hi i am arian"); 
              lcd_gotoxy(5,1);  
              //delay_ms(1000);
              lcd_puts("Hi i am arian");
              delay_ms(1000);  



while (1)
      {


      }
}
