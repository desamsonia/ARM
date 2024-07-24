#include <lpc21xx.h>

void init_uart(void)
{
	PINSEL0 = 0X05;
	U0LCR  = 0X83;
	U0DLL = 0X87;
	U0DLM = 0X01;
	U0LCR = 0X03;
}

void send_uart(unsigned char mydata)
{
	U0THR = mydata;
	while((U0LSR & (0X01 << 5)) == 0);
}

unsigned char receive_uart()
{
	unsigned char mydata;
	while((U0LSR & 0x01)==0);
	mydata = U0RBR;
	return mydata;
}

char *readstr()
{
	int i=0;
	static char a[100];
	while(1)
	{
		a[i] = receive_uart();
		send_uart(a[i]);
		if(a[i] == '\r' || a[i] == '\n')
			break;
		i++;
	}
	a[i] = '\0';
	return a;
}
	
void print_uart(unsigned char s[])
{
	int i=0;
	while(s[i] != '\0')
	{
		send_uart(s[i]);
		i++;
	}
}

void hex_uart(int n)
{
	unsigned char a[100];
	int r,i=0;
	while(n)
	{
		r=n%16;
		if(r>9)
			a[i++] = (r-10) + 'A';
		else if(r<9)
			a[i++] = r+48;
		n/=16;
		//i++;
	}
	a[i] = '\0';
	for(--i;i>=0;i--)
	send_uart(a[i]);
}	
		

int myatoi(unsigned char s[])
{
	int i=0,n=0;
	for(i=0;s[i];i++)
	{
		s[i] = s[i]-48;
		n=n*10+s[i];
	}
	return n;
}
		