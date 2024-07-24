#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4

unsigned int prime_Check(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num %i == 0)
			  return 0;
	}
	return 1;
}
main()
{
	int num;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	for(num=11;num<=50;num++)
	{
		if(prime_Check(num))
		{
			WRITENIBBLE(IOPIN0,AL_LED,~num);
			WRITENIBBLE(IOPIN0,AH_LED,num >> 4);
			delay_s(1);
		}
	}
}
			