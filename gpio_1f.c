#include "delay_declaration.h"
#include <lpc21xx.h>
main()
{
//configure p0.07 as io pin
IODIR0 |= 1 << 7;
while(1)
{
		!((IOPIN0 >> 7) & 1) ? (IOSET0 = 1 << 7) : (IOCLR0 = 1 << 7);
		delay_ms(100);
}
}



