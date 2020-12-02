#include <stdio.h>

#define SIGN(x)     (((x)&1)<<31)
#define EXPONENT(x) (((x)&0xFF)<<23)
#define FRACTION(x) ((x)&0x7FFFFF)
#define FLOAT(a,b,c) SIGN(a)|EXPONENT(b)|FRACTION(c)

union BITS
{
   unsigned int UI;
   signed int SI;
   float F;
};

void printBits(unsigned int val)
{
   for(int i=31; i>=0; i--)
   {
      printf("%d", ((val >> i) & 1u));
   }
   printf("\n");
}

int main(void)
{
   union BITS Var;

   Var.UI = FLOAT(1, 0x7E, 0x200000);
   printf("float    %.80f\n", Var.F );
   printf("bits "), printBits(Var.UI);

   printf("signed int    %d\n", Var.SI);
   printf("unsigned int  %u\n", Var.UI);

   return 0;
}
