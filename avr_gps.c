/*****************************************************
Author                  : Arief Ismail
Chip type               : ATmega32
AVR Core Clock frequency: 16.000000 MHz
Compiler                : CodeVisionAVR 2.05.3
*****************************************************/

#include <mega32a.h>
#include <alcd.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

bit data_update;
unsigned char slot=0,z=0;
unsigned char latitude[12];
unsigned char latitude_indicator;
unsigned char longitude[12];
unsigned char longitude_indicator;
unsigned char waktu[12];
unsigned char status;
unsigned char buf[16];
int bujur;

// Data dari GPS kita ambil dalam kalimat NMEA GPGLL
interrupt [USART_RXC] void usart_rx_isr(void){
unsigned char data;
data=UDR;
    switch(slot){
    //data $GPGLL
    case 0:if(data=='$')slot=1;break;
    case 1:if(data=='G')slot=2;else if(data=='$')slot=1;break;
    case 2:if(data=='P')slot=3;else if(data=='$')slot=1;break;
    case 3:if(data=='G')slot=4;else if(data=='$')slot=1;break;
    case 4:if(data=='L')slot=5;else if(data=='$')slot=1;break;
    case 5:if(data=='L')slot=6;else if(data=='$')slot=1;break;
    case 6:if(data==',')slot=7;else if(data=='$')slot=1;break;
    
    //data latitude
    case 7:
    if     (data=='$') slot=1; 
    else if(data==','){z=0;slot=8;}
    else              {latitude[z]=data;z++;}
    break;
            
    //indikator N/S
    case 8:if(data=='$')slot=1;else{latitude_indicator=data;slot=9;}break;
    case 9:if(data==',')slot=10;else if(data=='$')slot=1;break;
    
    //data longitude    
    case 10:
    if     (data=='$') slot=1; 
    else if(data==','){z=0;slot=11;}
    else              {longitude[z]=data;z++;}
    break;
    //indicator E/W
    case 11:if(data=='$')slot=1;else{longitude_indicator=data;slot=12;}break;
    case 12:if(data==',')slot=13;else if(data=='$')slot=1;break;
    
    //data jam satelit UTC
    case 13:
    if     (data=='$') slot=1; 
    else if(data==','){z=0;slot=14;}
    else              {waktu[z]=data;z++;}
    break;
    
    //Indikator data sudah selesai diterima
    case 14:if(data=='$')slot=1;else{status=data;slot=0;data_update=1;}break;
    }
}

void main(void){
char i=0;
int jam_tampil;
    
//USART 9600bps
UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x06;
UBRRH=0x00;
UBRRL=0x67;

//LCD PORTB
//konfigurasi Port LCD harus masuk di menu konfigurasi CVAVR
lcd_init(16);

//Menyalakan backlight LCD
DDRA.3=1;
PORTA.3=1;
#asm("sei")
lcd_clear();
lcd_gotoxy(0,0);
lcd_putsf("test");

while (1)
      {
          if(data_update){
              if(status=='A'){
                  i++;
                    if(i<4){  
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_puts(latitude);lcd_putchar(0x20);lcd_putchar(latitude_indicator);
                      lcd_gotoxy(0,1);
                      lcd_puts(longitude);lcd_putchar(0x20);lcd_putchar(longitude_indicator);
                      }
                    else if(i<8){
                      bujur=(longitude[0]-'0')*100+(longitude[1]-'0')*10+(longitude[2]-'0');
                      //longitude_indicator='W';
                      if(longitude_indicator=='E')bujur=bujur/15;
                      else if(longitude_indicator=='W')bujur=-bujur/15;
                      
                      jam_tampil=(waktu[0]-'0')*10+(waktu[1]-'0')+bujur;
                      
                      if(jam_tampil>23)jam_tampil=jam_tampil-24;
                      else if(jam_tampil<0)jam_tampil=jam_tampil+24; 
                      
                      waktu[0]=jam_tampil/10+'0';
                      waktu[1]=jam_tampil%10+'0';
                      
                      lcd_clear();
                      lcd_gotoxy(0,0);
                      lcd_putchar(waktu[0]);
                      lcd_putchar(waktu[1]);
                      lcd_putchar(':');
                      lcd_putchar(waktu[2]);
                      lcd_putchar(waktu[3]);
                      lcd_putchar(':');
                      lcd_putchar(waktu[4]);
                      lcd_putchar(waktu[5]);
                      itoa(bujur,buf);
                      lcd_gotoxy(0,1);
                      lcd_putsf("GMT = ");lcd_puts(buf);
                      }
                  data_update=0;    
                  if(i>7)i=0;
                  }
              else if(status=='V'){
                lcd_clear();
                lcd_gotoxy(0,0);
                lcd_putsf("data not valid");
              }
          }
      }
}
