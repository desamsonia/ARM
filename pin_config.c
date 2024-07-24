#include <lpc21xx.h>
main()
{
	PINSEL0 = 0;
	PINSEL0 = 1;
	PINSEL0 = 2;
	PINSEL0 = 3;
	while(1);
}

