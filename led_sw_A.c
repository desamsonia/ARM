#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4

#define sw1 16
#define sw2 17
#define sw3 18
#define sw4 19

int main()
{
	while(1)
	{
		
		if(READBIT(IOPIN0,sw1) == 0)
		{
			WRITEBYTE(IOPIN0,AL_LED,0x8E);
			delay_s(1);
		}
		else if(READBIT(IOPIN0,sw2) == 0)
		{
			WRITEBYTE(IOPIN0,AL_LED,0x4D);
			delay_s(1);
		}
		else if(READBIT(IOPIN0,sw3) == 0)
		{
			WRITEBYTE(IOPIN0,AL_LED,0x2B);
			delay_s(1);
		}
		
		else if(READBIT(IOPIN0,sw4) == 0)
		{
			WRITEBYTE(IOPIN0,AL_LED,0x417);
			delay_s(1);
		}
		else 
		{
			WRITEBYTE(IOPIN0,AL_LED,0x0f);
			delay_s(1);
		}		
		}		
	}
	

