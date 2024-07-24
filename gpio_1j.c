#include "delay_declaration.h"
#include "defines_gpio.h"
#define OPIN 7
#include <lpc21xx.h>
main()
{
	//int t = 0;
	SETBIT(IODIR0,OPIN);

	while(1)
	{
		//WRITEBIT(IOPIN0,OPIN, t=!t);
		WRITEBIT(IOPIN0,OPIN, (!READBIT(IOPIN0,OPIN)));
		delay_ms(100);
	}
	}
