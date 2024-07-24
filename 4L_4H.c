#include <lpc21xx.h>
#include "delay_1.h"
#include "defines_gpio.h"

#define AL_LED 0 //NOTE:p0.0 to p0.3 active low leds
#define AH_LED 4 //NOTE:p0.4 to p0.7 active high leds
main()
{
	u32 i,n;
	WRITEBYTE(IODIR0,AL_LED,255);
	 while(1)
	 {
		 n=128;
		 for(i=0;i<8;i++)
		 {
			 WRITEBYTE(IOPIN0,AL_LED,(n>>i)^0x0f);
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