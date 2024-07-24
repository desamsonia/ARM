#include "defines_gpio.h"

#define data 16
#define rs 24
#define rw 25
#define en 26

void writeLCD(unsigned char dat)
{
	IOCLR1 = 1 << rw;
	WRITEBYTE(IOPIN1,dat,data);
	IOSET1 = 1 << en;
	delay_us(1);
	IOCLR1 = 1 << en;
	delay_us(2);
}

void cmdLCD(unsigned char cmd)
{
	IOCLR1 = 1 << rs;
	writeLCD(cmd);
}

void charLCD(unsigned char assi)
{
	IOSET1 = 1 << rs;
	writeLCD(assi);
}

void initLCD(void)
{
	IODIR1 = oxff << data | 1 << rs | 1<<rw | 1 << en;
	delay_ms(15);
	cmdLCD(0x30);
	delay_ms(5);
	cmdLCD(0x30);
	delay_ud(100);
	cmdLCD(0x30);
	
	cmdLCD(0x38);
	cmdLCD(0x0E);
	cmdLCD(0x01);
	cmdLCD(0x06);
}	
	
	
void strLCD(unsigned char s[])
{
	int i=0;
	while(s[i] != '\0')
	{
		charLCD(s[i]);
		i++;
	}
}

void s32LCD(int n)
{
	int i=0;
	char a[100];
	if(n==0)
		charLCD('0');
	else
	{
		while(n)
		{
			a[i] = n%10+48;
			n/=10;
			i++;
		}
		a[i] = '\0';
	}
	
	for(--i;i>=0;i--)
	charLCD(a[i]);
}

void f32LCD(float f,int dp)
{
	int n=0,i;
	n=f;
	s32LCD(n);
	charLCD('.');
	for(i=0;i<dp;i++)
	{
		f=(f-n)*10;
		n=f;
		s32LCD(n+48);
	}
}
		
			