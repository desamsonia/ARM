#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4
main()
{
	int i,n;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(1)
	{
	n=128;
	for(i=0;i<8;i++)
	{
		
		WRITEBYTE(IOPIN0,AL_LED,(n>>i)^0x0f);
	//	IOSET0 = 1 << (7-i);
		//IOCLR0 = 1 << (7-i);
		delay_s(1);
	}
	n=1;
	for(i=0;i<8;i++)
	{
		WRITEBYTE(IOPIN0,AL_LED,(n<<i)^0x0f);
		delay_s(1);
	}
}
	}
	