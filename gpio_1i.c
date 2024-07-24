#include "delay_declaration.h"
#include "defines_gpio.h"
#include <lpc21xx.h>
#define OPIN 7
main()
{
	SETBIT(IODIR0,OPIN);
	while(1)
	{
		WRITEBIT(IOPIN0,OPIN,1);
		delay_ms(100);
		WRITEBIT(IOPIN0,OPIN,0);
		delay_ms(100);
	}
		
}	