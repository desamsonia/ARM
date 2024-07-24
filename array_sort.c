#include "uart_declaration.h"
#include <lpc21xx.h>

void selection_sort(int *arr,int n)
{
	int i, j,temp=0; 
    for (i = 0; i < n - 1; i++)
   	{   
        for (j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
						{
                temp=arr[i];
							  arr[i]=arr[j];
							  arr[j]=temp;
            }							
    } 
}

int myatoi(char *str)
{
  int n=0,i;
	for(i=0;str[i] != '\0' ;i++)
   {
   if(str[i] >= 48 && str[i] <= 57)
   {  
   str[i] = str[i] - 48;
   n=n*10+str[i];
   }
  }
	return n;
}

int main()
{
char *c={0},*s={0};
int n1,i,j,k,temp;
int arr[50]={0};
initUART();
while(1)
{
	n1=0,j=0,k=0,i=0,temp=0;
  printUART("\nEnter number of elements:\n\r");
INPUT:	c = readStr();
	printUART(c);
	n1=myatoi(c);
	
	if(n1==0) 
	{
	printUART("Invalid input !!,Enter again\n\r");
	goto INPUT;
	}
	
	printUART("\nEnter array elemts:\n\r");
  for(i=0;i<n1;i++)
  {
		printUART("               \n\r");
		s=readStr();
		printUART(s);
		j=myatoi(s);
		arr[i] = j;
		j=0;
  }
	
  printUART("\nBefore Sorting:\n\r");
	for(i=0;i<n1;i++)
	{
		printUART("           \n");
	  s32UART_tx(arr[i]);
	}
	
	selection_sort(arr,n1);
	
	printUART("\nAfter sorting:\n\r");
	for(i=0;i<n1;i++)
	{
		printUART("           \n");
	  s32UART_tx(arr[i]);
		
	}
}
}