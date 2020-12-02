#include <stdio.h>

int main(void)
{
   printf("10 / 4 is %d\n", 10/4);          // prints -> 10 / 4 is 2       
   printf("10 / 4 is %f\n", 10/4);          // prints -> 10 / 4 is 0.000000
   printf("10 / 4 is %f\n", 10.0/4);        // prints -> 10 / 4 is 2.500000
   printf("10 / 4 is %f\n", ((float)10)/4); // prints -> 10 / 4 is 2.500000
   printf("10 / 4 is %f\n", (float)(10/4)); // prints -> 10 / 4 is 2.000000

   return 0;
}
