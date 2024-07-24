#include "delay_A.h"
#include <lpc21xx.h>
#include "defines.h"

#define AL_LED 0
#define AH_LED 4

#define AL_SW_INC 8
#define AL_SW_DEC 9
main()
{
	int cnt=0;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(1)
	{
		if(READBIT(IOPIN0,AL_SW_INC)==0)
		{
       while(READBIT(IOPIN0,AL_SW_INC)==0);
			cnt++;
			delay_ms(2);
		}
		else if(READBIT(IOPIN0,AL_SW_DEC)==0)
		{
      while(READBIT(IOPIN0,AL_SW_DEC)==0);
			cnt--;
			delay_ms(2);
		}
		if(cnt<0)
			cnt=0;
    else if(cnt>255)
               cnt=255;
		WRITEBYTE(IOPIN0,AL_LED,cnt^0x0F);	
	}	
}
