#include <lpc21xx.h>
#include "types.h"
#include "defines_gpio.h"
#include "delay_1.h"

#define AL_LED 0
#define AH_LED 4

//u32 check_Prime(u32);
u32 check_Prime(u32 n)
{
	u32 i;
	for(i=2;i<n;i++)
	{
		if((n%i) ==0)
			return 0;
	}
	return 1;
}
			
main()
{
	u32 data,cnt=0;
	WRITEBYTE(IODIR0,AL_LED,0xFF);
	IOSET0 = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3; // (or) WRITENIBBLE(IOPIN0,AL_LED,0x0F); set active low leds 
	while(1)
	{
		for(data = 2;data <= 255;data++)
		{
			if(check_Prime(data))
		   {
				 cnt++;
				 if(cnt <= 5)
				 {
			    WRITENIBBLE(IOPIN0,AL_LED,data);
			    WRITENIBBLE(IOPIN0,AH_LED,data >> 4);
			    delay_s(1);
				 }
		   }
	   }
  }
}
			
	
	



