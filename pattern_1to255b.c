#include <lpc21xx.h>
#include "types.h"
#include "delay_1.h"
#include "defines_gpio.h"
#define OPORT 8
u32 i;
main()
{
	WRITEBYTE(IODIR0,OPORT,0xFF);
	for(i=0;i<=255;i++)
	{
		WRITEBYTE(IOPIN0,OPORT,0xFF);
		delay_ms(100);
	}
	while(1);
}
	