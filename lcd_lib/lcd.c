#include <mega32.h>
#include <delay.h>
#include "lcd.h"

void lcd_send_E(unsigned char data)   {     //simple 4 bit send to lcd pins
    unsigned char myport = 0;
    myport = ((data & 0x0f) << 3)   ;  
    
    myport = myport | 0x04 ; 
    send_ports(myport);
    delay_us(5);
    myport = myport & ~(0x04) ;             //The lcd will read its pins after turning off the E pin
    send_ports(myport); 
    delay_us(5);
     
}

void lcd_send_E_8(unsigned char data)   {  //simple 8 bit send to lcd pins 
    unsigned char myport = 0;
    myport = (((data >> 4 ) & 0x0f) << 3)   ;  
    
    myport = myport | 0x04 ;
    send_ports(myport); 
    delay_ms(1);  
    myport = myport & ~(0x04) ; 
    send_ports(myport);
    delay_ms(1);
    
    myport = ((data  & 0x0f) << 3)   ;  
    
    myport = myport | 0x04 ;
    send_ports(myport);
    delay_ms(1);
    myport = myport & ~(0x04) ;
    send_ports(myport); 
    delay_ms(1);
     
}

void lcd_send_ERS_8(unsigned char data)   { //simple 8 bit send to lcd pins with RS
    unsigned char myport = 0;

    myport = (((data >> 4 ) & 0x0f) << 3) |  0x01 ;  
    
    myport = myport | 0x04 ; 
    send_ports(myport);
    delay_ms(1);
    myport = myport & ~(0x04) ;
    send_ports(myport); 
    delay_ms(1);
    
    myport = ((data  & 0x0f) << 3) | 0x01   ;  
    
    myport = myport | 0x04 ; 
    send_ports(myport);
    delay_ms(1);
    myport = myport & ~(0x04) ; 
    send_ports(myport);
    delay_ms(1);
     
}

void lcd_init(){                           // just like datasheet
    LCD_DDR |= (1 <<LCD_DS) | (1 <<LCD_SH_CP) | (1 <<LCD_ST_CP)

    lcd_send_E(0x03);
    lcd_send_E(0x03);
    lcd_send_E(0x03);
    lcd_send_E(0x02);   //change to 4 bit mode 

    lcd_send_E_8(0x28);
    lcd_send_E_8(0x0C);
    lcd_send_E_8(0x06);
        
}  