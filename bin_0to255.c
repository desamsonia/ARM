#include <lpc21xx.h>
#include "defines_gpio.h"
#include "delay_1.h"
#include "delay_1.h"

#define AL_LED 0 //p0.0 to p0.3 active low leds
#define AH_LED 4 //p0.4 to p0.7 active high leds
main()
{
	u32 i;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	while(1)
	{
	     for(i=0;i<=255;i++)
	     {
	   	WRITENIBBLE(IOPIN0,AL_LED,~i);
	  	WRITENIBBLE(IOPIN0,AH_LED,(i >> 4));
	  	delay_s(1);
	     }
	}
}
