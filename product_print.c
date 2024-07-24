#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4
main()
{
	int num=14,p=1,i;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(num)
	{
		i = num % 10;
		p = p * i;
		num/=10;
	}
	WRITENIBBLE(IOPIN0,AL_LED,~p);
	WRITENIBBLE(IOPIN0,AH_LED,p>>4);
}