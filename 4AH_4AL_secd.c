#include <lpc21xx.h>
#include "defines_gpio.h"
#include "delay_1.h"
#include "delay_1.h"

#define AH_LED 0 // 0 to 3 (active high leds)
#define AL_LED 4 // 4 to 7 (active low leds)
main()
{
	unsigned int i,j,k;
	WRITEBYTE(IODIR0,AH_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	for(i=0;i<5;i++)
	{
		for(j=0,k=7;k>j;j++,k--)
		{
			SSETBIT(IOSET0,j);// IOSET0 = 1 << j;
			SCLRBIT(IOCLR0,k);// IOCLR0 = 1 << k;
			delay_s(1);
			SCLRBIT(IOCLR0,j); // IOCLR0 = 1 << j;
			SSETBIT(IOSET0,k); // IOSET0 = 1 << k;
		}
	}
	while(1);
}
