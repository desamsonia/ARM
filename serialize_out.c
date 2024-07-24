#include "delay_declaration.h"
#include "defines_gpio.h"
#define OPIN 7
#include <lpc21xx.h>
unsigned char ch= 'A';

main()
{
	int i;
	SETBIT(IODIR0,OPIN);
  for(i=7;i>=0;i--)
	{
		//WRITEBIT(IOPIN0,OPIN,READBIT(ch,i));
		READWRITEBIT(IOPIN0,OPIN,ch,i);
		delay_ms(104);
	}
	while(1);
}