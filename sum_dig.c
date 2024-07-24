#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4

main()
{
	int n=45,sum=0,i;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(n)
	{
		i=n%10;
		sum = sum + i;
		n/=10;
	}
	WRITENIBBLE(IOPIN0,AL_LED,~sum);
	WRITENIBBLE(IOPIN0,AH_LED,sum >> 4);
}