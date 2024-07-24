#include <lpc21xx.h>
#include "types.h"
#include "defines_gpio.h"
#include "pin_fun_declarations.h"

void CfgPortPin(u32 portNo,u32 pinNo, u32 pinFunc)
{
	if(portNo == 0)
	{
		if(pinFunc == GPIO_IN)
		{
			CLRBIT(IODIR0,pinNo); pinFunc = FUNC1;
		}
    else if(pinFunc == GPIO_OUT)
    {
      SETBIT(IODIR0,pinNo); pinFunc = FUNC1;
    }
    if(pinNo < 16) CFGPIN(PINSEL0,pinNo,pinFunc);
    else if((pinNo >= 16) && (pinNo <= 31))  CFGPIN(PINSEL1,(pinNo - 16),pinFunc);
	}
	else if(portNo == 1)
	{
   if(pinFunc == GPIO_IN)
		{
			CLRBIT(IODIR0,pinNo); pinFunc = FUNC1;
		}
    else if(pinFunc == GPIO_OUT)
    {
      SETBIT(IODIR0,pinNo); pinFunc = FUNC1;
    }
    if((pinNo >= 16) && (pinNo <= 31))  CFGPIN(PINSEL1,(pinNo - 16),pinFunc);
	}
}	

void SetPortPin(u32 portNo,u32 pinNo)
{
	(portNo == 0)  ?
	SSETBIT(IOSET0,pinNo) : 	SSETBIT(IOSET1,pinNo);
}	
	
void ClrPortPin(u32 portNo,u32 pinNo)
{
	(portNo == 0)  ?
	SCLRBIT(IOCLR0,pinNo) : 	SCLRBIT(IOCLR1,pinNo);
}		

void TogglePortPin(u32 portNo,u32 pinNo)
{
	(portNo == 0)  ?
	CPLBIT(IOPIN0,pinNo) : 	CPLBIT(IOPIN1,pinNo);
}

void Wr2portPin(u32 portNo,u32 pinNo,u32 bit)
{
	(portNo == 0) ?
	WRITEBIT(IOPIN0,pinNo,bit) : WRITEBIT(IOPIN1,pinNo,bit);
}

u32 RdPortPin(u32 portNo,u32 pinNo)
{
	return (portNo == 0) ?
		READBIT(IOPIN0,pinNo) : READBIT(IOPIN1,pinNo);
}

void CfgPortByte(u32 portNo,u32 startpinNo,u32 pinFunc)
{
	if(portNo == 0)
	{
		if(pinFunc == GPIO_IN)
		{
			WRITEBYTE(IODIR0,startpinNo,0x00);  pinFunc = FUNC1;
		}
    else if(pinFunc == GPIO_OUT)	
		{
			WRITEBYTE(IODIR0,startpinNo,0xFF);  pinFunc = FUNC1;
		}
		if(startpinNo < 16)  (PINSEL0 = (PINSEL0 & ~(0xFFFF << (startpinNo *2))));
    else if((startpinNo >= 16) && (startpinNo <= 31))  (PINSEL1 = (PINSEL1 & ~(0xFFFF << ((startpinNo-16) *2))));
	}
	else if(portNo == 1)
	{
   if(pinFunc == GPIO_IN)
		{
       WRITEBYTE(IODIR1,startpinNo,0xFF);  pinFunc = FUNC1;
		}
    else if(pinFunc == GPIO_OUT)
    {
      WRITEBYTE(IODIR1,startpinNo,0xFF);  pinFunc = FUNC1;
    }
    if((startpinNo >= 16) && (startpinNo <= 31))   (PINSEL2 = (PINSEL2 & ~(0xFFFF << ((startpinNo-16) *2))));
	}
}
void Wr2PortByte(u32 portNo,u32 startpinNo,u32 byte)
{
	(portNo == 0) ?
	WRITEBYTE(IOPIN0,startpinNo,byte):
	WRITEBYTE(IOPIN1,startpinNo,byte);
}	
		
			