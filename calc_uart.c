#include "uart_declaration.h"

main()
{
char *str=0,ch,e;
int i,n,a,b,c;
initUART();
while(1)
{
n=0,a=0,b=0,c=0;
printUART("\nEnter expression:\n\r");
str = readStr();	
for(i=0;str[i] != '\0' ;i++)
{
   if(str[i] >= 48 && str[i] <= 57)
   {  
   str[i] = str[i] - 48;
   n=n*10+str[i];
   } 
   else if(str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i] == '/')
   {
   a=n;
   n=0;
   ch=str[i];
    } 
   else if(str[i] == '=')
   {
      e=str[i];
   }   
}
b=n;
printUART("           \n\r");
if( ch == '+' && e == '=')
		{
			    c = a+b;  
			    s32UART_tx(c);
			//fflush(stdin);
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