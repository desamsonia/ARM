#include <lpc21xx.h>
#include "defines.h"
int checkPalindrome(int number)
{
  int temp, remainder, rev=0;
  temp = number;

  while( number!=0 )
  {
     remainder = number % 10;
     rev = rev*10 + remainder;
     number /= 10;
  }

  if ( rev == temp ) return 0;
  else return 1;
}

int main()
{
  int number;

  if(checkPalindrome(number) == 0)
  else
  return 0;
}