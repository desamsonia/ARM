#include <lpc21xx.h>
#define sw1 4
#define sw2 5
#define LED 8
main()
{
	IODIR0 = 1 << LED;
	while(1)
	{
		if((((IOPIN0 >> sw1)&1) ==  0) || (((IOPIN0 >> sw2)&1) == 0))	IOSET0 = 1 << LED;
		else IOCLR0 = 1 << LED;
	}
}
	