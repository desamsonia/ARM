#include "types.h"
#include "delay_1.h"
#include <lpc21xx.h>
#include "pin_fun_declarations.h"
#include "defines_gpio.h"
#define OPORT 16
main()
{
	u32 i;
	CfgPortByte(0,OPORT,GPIO_OUT);
	for(i=0 ; i<=255;i++)
	{
		Wr2PortByte(0,OPORT,i);
		delay_ms(100);
	}
	while(1);
}