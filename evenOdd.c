#include "delay_A.h"
#include <lpc21xx.h>
#include "defines.h"

#define AL_LED 0
#define AH_LED 4

#define AL_SW_EVEN 8
#define AL_SW_ODD  9
main()
{
	int num=0;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(1)
	{
		if(READBIT(IOPIN0,AL_SW_EVEN)==0)
		{
			if((num%2)!=0)
				num+=1;
		}
		if(READBIT(IOPIN0,AL_SW_ODD)==0)
		{
			if((num%2)==0)
				num+=1;
		}
		if(num==256)
			num=0;
		if(num==257)
			num=1;
		WRITEBYTE(IOPIN0,AL_LED,num^0x0f);
		num+=2;
		delay_s(1);
	}
}
