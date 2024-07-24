#include<lpc21xx.h>
#include "delay_1.h"
//#include "defines_gpio.h"
#include "uart_declaration.h"
#include <stdlib.h>

main()
{
	char *str1,*str2;
	int a,b,c,i;
	char ch,e;
	initUART();
	while(1)
	{
		printUART("\nEnter your choice: \n\r"); 
		str1 = readStr();
		ch = receiveUART();
		sendUART(ch);
		str2 = readStr();
		a = atoi(str1);
		b = atoi(str2);
		e = receiveUART();
		
		sendUART(e);
		if( ch == '+' && e == '=')
		{
			    c = a+b;  
			    s32UART_tx(c);
		}			
		else if(ch == '-' && e == '=')
		{			
       c = a-b;
       s32UART_tx(c);		
		}
		else if(ch == '*' && e == '=')
		{
			    c = a*b;
      s32UART_tx(c);		
		}
		else if(ch == '/'  && e == '=')
		{
           c = a/b;
     s32UART_tx(c);		
		}
  }
}	
	

	/*for(i=0;str1[i];i++)
		{
			str1[i] = receiveUART();	
		}
		str1[i] = '\0';
		
    for(i=0;str1[i];i++)
		{
			str2[i] = receiveUART();	
		}
		str2[i] = '\0';*/