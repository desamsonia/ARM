//1. flash an led using any port pin 
#include <lpc21xx.h>
#include "delay_1.h"
#include "defines_gpio.h"
#define LED 27
main()
{
	unsigned int i;
	//IODIR0 = 1 << LED;
	SSETBIT(IODIR0,LED);// gpio as output pin
	while(1)
	{
		for(i=0;i<10;i++)
		{
			SSETBIT(IOSET0,LED); //IOSET0 = 1 << LED;
			delay_ms(100);
			SCLRBIT(IOCLR0,LED); //IOCLR0 = 1 << LED;
			delay_ms(100);
		}	
	}		
}