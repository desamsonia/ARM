//2b. Switch ON one by one led from right to left at the rate of 1 second 

#include <lpc21xx.h>
#include "delay_1.h"
#include "defines_gpio.h"

//active low leds
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3

//active high leds
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7

#define sw 9

main()
{
	WRITEBYTE(IODIR0,LED1,0XFF);
	IOSET0 = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3; //WRITENIBBLE(IOPIN0,0XFF);
	while(1)
	{

		for(i=0;i<8;i++)
    {
			
    		IOCLR0 = 1 << 0;
		    delay_ms(100);
		    IOCLR0 = 1 << 1;
		    delay_ms(100);
		IOCLR0 = 1 << 2;
		delay_ms(100);
		IOCLR0 = 1 << 3;
    delay_ms(100);		 
		 
		IOSET0 = 1 << 4;
		delay_ms(100);
		IOSET0 = 1 << 5;
		delay_ms(100);
		IOSET0 = 1 << 6;
		delay_ms(100);
		IOSET0 = 1 << 7;
		delay_ms(100);
		
	 }
}
	
	
