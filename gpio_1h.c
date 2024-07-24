#include "delay_declaration.h"
#include "defines_gpio.h"
#include <lpc21xx.h>
#define OPIN 7
main()
{
SSETBIT(IODIR0,OPIN); // SETBIT(IODIR0,OPIN)
while(1)
{
	SSETBIT(IOSET0,OPIN);
	delay_ms(200);
	SCLRBIT(IOCLR0,OPIN);
	delay_ms(200);
}
}