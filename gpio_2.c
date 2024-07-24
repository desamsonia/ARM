#include "delay_declaration.h"
#include <lpc21xx.h>
main()
{
	PINSEL1 = 0;
	IODIR0 = 0xFFFFFFFF;
	IODIR1 = 0xFFFF0000;
	while(1)
	{
		IOSET0 = 0xFFFFFFFF;
		IOSET1 = 0xFFFF0000;
		delay_ms(100);
		IOCLR0 = 0xFFFFFFFF;
		IOCLR1 = 0xFFFF0000;
		delay_ms(100);
	}				
}	
