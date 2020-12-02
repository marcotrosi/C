#include <stdio.h>

int main(void)
{
   char MyVar = -128;

   for(int i = 7; i >= 0; i--)
   {
      printf("%d", (MyVar >> i)&1);
   }
   printf("\n");

   return 0;
}

