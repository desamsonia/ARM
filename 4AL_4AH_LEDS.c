//2.a. Switch ON one by one led from left to right at the rate of 1 second

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
	unsigned int i ;
	WRITEBYTE(IODIR0,LED1,0XFF);
	IOSET0 = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3; //WRITENIBBLE(IOPIN0,0XFF);
	while(1)
	{
	  for(i=0;i<8;i++)
		{
			if(i<4)
			{
		  IOSET0 = 1 << (LED8-i);
		  delay_ms(100);
		  }
			
			else
			{
		  IOCLR0 = 1 << (LED8-i);
		  delay_ms(100);
		  }
		
  }	
 }	
}	
	



