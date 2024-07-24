#include "types.h"
#include "kpm.h"
#include "defines_gpio.h"
#include <lpc21xx.h>
#define AL_LED 0  //p0.0-p0.3
#define AH_LED 4  //p0.4-p0.7
int main()
{
	u32 keyp;
	Initkpm();
	WRITEBYTE(IODIR0,AL_LED,255);
	while(1)
	{
		keyp=keyscan();
		while(colscan()==0)
		{
			WRITEBYTE(IOPIN0,AL_LED,keyp^0x0f);
		}
	}
}
