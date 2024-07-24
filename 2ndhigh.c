#include "defines.h"
#include "delay_A.h"
#include <lpc21xx.h>

#define AL_LED 0
#define AH_LED 4

 main()
 {
	 int max=0,max2=0,i,j;
	 WRITEBYTE(IODIR0,AL_LED,255);
	 WRITENIBBLE(IOPIN0,AL_LED,15);
	 i=j=456;
	 while(i)
	 {
		 if((i%10) > max )
			 max = i%10;
		 
		 i/=10;
	 }
	 while(j)
	 {
		 if(((j%10) > max2) && ((j%10) < max ))
			  max2 = j%10;
		 j/=10;
	 }
	 
	 WRITENIBBLE(IOPIN0,AL_LED,~(max2));
	 WRITENIBBLE(IOPIN0,AH_LED, max2 >> 4);
	 while(1);
 }