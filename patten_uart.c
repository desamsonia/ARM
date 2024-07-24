#include<lpc21xx.h>
#include "delay_1.h"
#include "defines_gpio.h"
#include "uart_declaration.h"
#include "types.h"

int main()
{
	s32 row,col;
	initUART();
	for(row=1;row<=5;row++)
	{
		for(col=1;col<=(5-row+1);col++)
		{
			sendUART('*');
		}
		sendUART('\r');
		sendUART('\n');
	}
}