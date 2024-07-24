#include <lpc21xx.h>
#include "defines_gpio.h"
#include "types.h"
#include "lcd.h"
#include "lcd_defines.h"
#include "delay_1.h"
#include <stdlib.h>

#define p1 0
main()
{
	s32 i,j,t;
	s32 arr[5];
	// = {4,1,6,8,10}; // 1 3 4 6 8  
	//WRITEBYTE(IODIR0,p1,0xff);
	for(i=0;i<10;i++)
	{
	arr[i++] = rand()%10+1;
	}
	InitLCD();
	while(1)
	{
		for(i=0;i<5-1;i++)
		{
			for(j=i+1; j<5;j++)
			{
				if(arr[i] > arr[j])
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}

		for(i=0;i<10;i++)
		{
			//WRITEBYTE(IOPIN0,p1,arr[i]);
			//CmdLCD(GOTO_LINE1_POS0);
			//U32LCD(arr[i]);
			CharLCD(arr[i]);
			delay_ms(500);
			//CmdLCD(CLEAR_LCD);
			
		}
	}	
	
}	