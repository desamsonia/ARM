#include<lpc21xx.h>
#include "delay_1.h"
#include "defines_gpio.h"
#include "uart_declaration.h"


main()
{
//	unsigned char c;
	initUART();
	
/*SETBIT(IODIR0,7);
	SETBIT(IODIR0,6);
	SETBIT(IODIR0,5);
	SETBIT(IODIR0,4);*/
	
	while(1)
	{
		/*c = receiveUART();
		if( c == 'B')
			  CPLBIT(IOPIN0,7);
		else if(c == 'C')
			  CPLBIT(IOPIN0,6);
		else if(c == 'A')
			  CPLBIT(IOPIN0,5);
		else if(c == '1')
			 CPLBIT(IOPIN0,4);
		*/
		
    printUART("sonia reddy");
		sendUART(13);
		sendUART(10);
		delay_ms(500);
		
	}
}
			