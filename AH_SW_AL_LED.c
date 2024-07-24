// active high switches(7,8) and active low led (0)
#include <lpc21xx.h>
main()
{
	IODIR0 = 1 << 0 | 1 << 1;
	while(1)
	{
	  if((((IOPIN0 >> 7)&1) == 1) || (((IOPIN0 >> 8)&1) == 1)) { IOCLR0 = 1 << 0 | 1 << 1;}
		else { IOSET0 = 1 << 0 | 1 << 1; }
	}
}
			