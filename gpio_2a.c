#include "delay_declaration.h"
#include <lpc21xx.h>
main()
{
	PINSEL1 = 0;
	IODIR0 = (1 << 0) | (1 << 15) | (15 << 27);
	IODIR1 = (1 << 16) | (1 << 31);
	while(1)
	{
		IOPIN0 ^= (1 << 0) | (1 << 15) | ( 15 << 27);
		IOPIN1 ^= (1 << 16) | (1<<31);
		delay_ms(100);
	}	
		
}