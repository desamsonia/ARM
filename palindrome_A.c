#include "defines.h"
#include <lpc21xx.h>
#include "delay_A.h"

#define AL_LED 0
#define AH_LED 4

int palindrome(int num)
{
  int temp, r, rev=0;
  temp = num;

  while( num!=0 )
  {
     r = num % 10;
     rev = rev*10 + r;
     num /= 10;
  }

  if (rev==temp) return 0;
  else return 1;
}
main()
{
	int num;
	WRITEBYTE(IODIR0,AL_LED,255);
	WRITENIBBLE(IOPIN0,AL_LED,15);
	for(num=11;num<=255;num++)
	{
		if(palindrome(num) == 0)
		{
			WRITENIBBLE(IOPIN0,AL_LED,~num);
			WRITENIBBLE(IOPIN0,AH_LED,num >> 4);
			delay_s(2);
		}

  }
}	
	