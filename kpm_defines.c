#include "defiens_gpio.h"

void initkpm(void)
{
	WRITENIBBLE(IODIR1,Row0,15);
}

int colscan()
{
	return (REABNIBBLE(IOPIN1,Col0) == 15) ? 1:0;
}

int rowcheck()
{
	int r;
	for(r=0;r<4;r++)
	{
		WRITENIBBLE(IOPIN1,Row0,~(1<<r));
		if(colscan()==0)
			break;
	}
	WRITENIBBLE(IOPIN1,Row0,0);
	return r;
}

int colcheck()
{
	int c;
	for(c=0;c<4;c++)
	{
		if(READBIT(IOPIN1,Col0+c)==0)
			break;
	}
	return c;
}


unsigned int keyscan(void)
{
	unsigned int keyv,r,c;
	while(colscan()==1);
	r=rowcheck();
	c=colcheck();
	keyv=kpmlut[r][c];
	delay_ms(300);
	return keyv;
}