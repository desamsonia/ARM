#include <lpc21xx.h>
#include "defines_gpio.h"
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "delay_1.h"
#include <stdlib.h>
u32 isprime(u32 n)
{
	s32 i;
	if(n==2)
		return 1;
	for(i=2;i<n;i++)
	{
		if((n%i)==0)
			return 0;
	}
	return 1;
}
main()
{
	u32 arr[10];
	s32 i;
	InitLCD();
	srand(23);
	for(i=0;i<10;i++)
	{
		arr[i]=rand()%100;
	}
	for(i=0;i<10;i++)
	{
		U32LCD(arr[i]);
		CharLCD(' ');
		delay_ms(300);
		if(i==4)
			CmdLCD(GOTO_LINE2_POS0);
	}
	delay_s(2);
	CmdLCD(CLEAR_LCD);
	for(i=0;i<10;i++)
	{
		//if(isprime(arr[i]))
		//{
		//	delay_ms(300);
			U32LCD(arr[i]);
			CharLCD(' ');
		//}
	}
	while(1);
}
