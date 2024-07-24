#include "uart.h"
#include "defines_gpio.h"
#include <lpc21xx.h>
#define AL_LED 3
#define AH_LED 7

int main()
{
	unsigned char ch;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	init_uart();
	while(1)
	{
		ch=receive_uart();
		send_uart(ch);
		WRITENIBBLE(IOPIN0,AL_LED,~ch);
		WRITENIBBLE(IOPIN0,AH_LED,ch>>4);
		hex_uart(48);
	}
/*unsigned char ch;
	char *str;
	init_uart();
//	ch=receive_uart();
	//send_uart(ch);
	str = readstr();
	print_uart("desam ");
	print_uart(str);*/
	return 0;
}