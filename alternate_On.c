#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 4
#define AH_LED 0

main()
{
	int i,j,k;
	WRITEBYTE(IODIR0,AH_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	for(i=0;i<=5;i++)
	{
		for(j=7,k=0;j>k;j--,k++)
		{
			SSETBIT(IOSET0,k);
			SCLRBIT(IOCLR0,j);
			delay_s(1);
			SCLRBIT(IOCLR0,k);
			SSETBIT(IOSET0,j);
		}
	}
	while(1);
}