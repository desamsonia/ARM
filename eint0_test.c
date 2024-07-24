#include <LPC21xx.h>
#include "types.h"
#include "defines_gpio.h"

#define CFGPIN(WORD,PIN,FUNC) \
WORD=(PIN<16) ? \
((WORD&~(3<<(PIN*2)))|(FUNC<<(PIN*2))) : \
((WORD&~(3<<((PIN-16)*2)))|(FUNC<<((PIN-16)*2))) 

#define EINT0_LED 7

void eint0_isr(void) __irq
{
	CPLBIT(IOPIN0,EINT0_LED);
	EXTINT=1<<0;
	VICVectAddr=0;
}
void Enable_EINT0(void)
{
	SETBIT(IODIR0,EINT0_LED);
	CFGPIN(PINSEL0,1,3);
	//VICIntSelect=0;
	VICIntEnable=1<<14;
	VICVectCntl0=0x20|14;
	VICVectAddr0=(u32)eint0_isr;
	EXTINT=1<<0;
	EXTMODE=1<<0;
	//EXTPOLAR=0;
}

u32 count;
main()
{
	Enable_EINT0();
	while(1)
	{
		count++;
	}
}