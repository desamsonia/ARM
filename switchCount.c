#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4

#define sw 8
main()
{
	int cnt=0;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(1)
	{
	if(READBIT(IOPIN0,sw) == 0)
	{
		
		//while(READBIT(IOPIN0,sw) == 0);
		cnt++;
		delay_ms(2);
		if(cnt > 255)
			cnt=0;
		WRITEBYTE(IOPIN0,AL_LED,cnt^0x0f);
	}
}
}
		