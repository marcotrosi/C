#include <stdio.h>

int main(void)
{
   printf("%.35f\n", 0.1f);
   printf("%.35f\n", 100000.0f);
   printf("%.35f\n", 0.1f * 1000000.0f); // using float literal
   printf("%.35f\n", 0.1f * 1000000.0);  // using double literal

   if( 100000.0f == (0.1f * 1000000.0) ) // using double literal
   {
      printf("is equal\n");
   }
   else
   {
      printf("is NOT equal\n");
   }
   
   return 0;
}

