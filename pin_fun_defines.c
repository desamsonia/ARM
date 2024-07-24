#include <lpc21xx.h>

void cfgPortPin(unsigned int portNo,unsigned int pinNo, int pinFunc)
{
	if(portNo == 0)
	{
		(pinNo < 16 ) ? (CFGPIN(PINSEL0,pinNo,pinFunc)) : (CFGPIN(PINSEL1,pinNo,pinFunc))
	}
  else if(portNo == 1)
  {
    if(pinNo > 15)
          CFGPIN(PINSEL2,pinNo,pinFunc);
	}
}
		
   

	