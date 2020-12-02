#include <stdio.h>

int main(void)
{
   // an almost random number
   printf("0x85AB0000 interpreted as signed value is %d\n"  , 0x85AB0000);
   printf("0x85AB0000 interpreted as unsigned value is %u\n", 0x85AB0000);

   // write unsigned integer as hex value
   printf("42 as hex is %x\n", 42u);
   printf("42 as hex is %X\n", 42u);

   // ASCII character interpretation
   printf("%d\n", 65);
   printf("%c\n", 65);

   // or the other way around
   printf("%d\n", 'A');
   printf("%c\n", 'A');

   return 0;
}
