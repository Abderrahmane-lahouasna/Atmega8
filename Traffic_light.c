/*
 * Atmega8.c
 *
 * Created: 6/22/2023 5:26:07 PM
 * Author : T530
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
void _Traffic_line1_red(void);
void _Traffic_line1_green(void);
void _Traffic_line1_orange(void);
	
int main(void)
{  
	
	DDRD=0xFF;//set all portd as output
	PORTD=0x00;//clear portd
	DDRC=0xFF;//set all Portc as output
	PORTC=0x00;// clear portc
	DDRB=0xFF;//set all portb as output
	PORTB=0x00;//clear portb
	
    /* Replace with your application code */
    while (1) 
    {
		_Traffic_line1_red();
		_Traffic_line1_orange();
		_Traffic_line1_green();
    }
}

void _Traffic_line1_red(void){
	unsigned char array[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,
		0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,
	0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30};
	unsigned char counter=0;
	for (counter=0;counter<31;counter++)
	{
		PORTD=array[counter];
		PORTC|=(1<<0);
		PORTB|=(1<<0);
		PORTB&=~(1<<1);
		PORTB&=~(1<<2);
		PORTC&=~(1<<1);
		PORTC&=~(1<<2);
		_delay_ms(500);
	}
	}
	void _Traffic_line1_green(void){
		unsigned char array[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,
			0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,
		0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30};
		unsigned char counter=0;
		for (counter=0;counter<31;counter++)
		{
			PORTD=array[counter];
			PORTC &=~(1<<0);
			PORTC|=(1<<2);
			
			PORTB|=(1<<1);
			PORTB&=~(1<<0);
			PORTB&=~(1<<2);
			
			PORTC&=~(1<<1);
			
			_delay_ms(500);
		}
		}
	
void _Traffic_line1_orange(void){
	unsigned char array[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10};
	unsigned char counter=0;
	for (counter=0;counter<11;counter++)
	{
		PORTD=array[counter];
		PORTC &=~(1<<2);
		PORTC|=(1<<1);
		
		PORTB&=~(1<<1);
		PORTB&=~(1<<0);
		PORTB|=(1<<2);
		
		PORTC&=~(1<<0);
		
		_delay_ms(500);
	}
}	