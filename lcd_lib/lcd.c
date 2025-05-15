#include <mega32.h>
#include <delay.h>
#include "lcd.h"


void send_ports(unsigned char a){
  unsigned char i = 0;
    for(i = 0; i < 8 ; i ++){
        if((a << i)&0x80)
            LCD_PORT |= (1 << LCD_DS) | (1 << LCD_SH_CP);
        else     
        LCD_PORT |= (1 << LCD_DS) ;
         
        LCD_PORT &= ~((1 << LCD_DS) | (1 << LCD_SH_CP)); 
         
            } 
            
    LCD_PORT |= (1 << LCD_ST_CP) ;
    LCD_PORT &= ~(1 << LCD_ST_CP);
}

void lcd_send_E(unsigned char data)   {     //simple 4 bit send to lcd pins
    unsigned char myport = 0;
    myport = ((data & 0x0f) << 3)   ;  
    
    myport = myport | 0x04 ; 
    send_ports(myport);
    delay_ms(1);
    myport = myport & ~(0x04) ;             //The lcd will read its pins after turning off the E pin
    send_ports(myport); 
    delay_ms(1);
     
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

void lcd_send_ERS_8(unsigned char data)   { //simple 8 bit send to lcd pins with RS , this is only needed for writing something on lcd
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
    LCD_DDR |= (1 <<LCD_DS) | (1 <<LCD_SH_CP) | (1 <<LCD_ST_CP);

    lcd_send_E(0x03);
    lcd_send_E(0x03);
    lcd_send_E(0x03);
    lcd_send_E(0x02);   //change to 4 bit mode 

    lcd_send_E_8(0x28);
    lcd_send_E_8(0x0C);
    lcd_send_E_8(0x06);
        
}  

void lcd_put_char(char c) {     //simple 1 character send to lcd
    lcd_send_ERS_8(c);          //as datasheet said , it should be same as asci table 

}


void lcd_puts(char *c) {        //simple string send to lcd
    while(*c != 0){             //this will stuck on loop until it hits null
    lcd_put_char(*c);           //sending every characters one by one to lcd
    c++;                        
    }
}

void lcd_clear(){
    lcd_send_E_8(0x01);
  }
  void lcd_gotoxy(char x , char y){
  
      switch (y) { 
      
      case 0:
          lcd_send_E_8(0x80 | x ); 
      break;
      case 1:
          lcd_send_E_8(0x80 | (x + 0x40)); 
      break; 
      
      }
  }