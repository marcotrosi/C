#include <stdio.h>

int main(void)
{
   unsigned char a=10;
   unsigned char b=3;
   unsigned char c=0;

   printf("::: Arithmetic Operators :::\n");
   printf("a=%u, b=%u, a+b => %u\n", a, b, a+b);
   printf("a=%u, b=%u, a-b => %u\n", a, b, a-b);
   printf("a=%u, b=%u, a*b => %u\n", a, b, a*b);
   printf("a=%u, b=%u, a/b => %u\n", a, b, a/b);
   printf("a=%u, b=%u, (float)a/b => %f\n", a, b, (float)a/b); // dividing as float
   //printf("%u\n", a/c); // division by zero not allowed
   printf("a=%u, -a => %d\n", a, -a); // because of the negative value I use %d for signed interpretation
   printf("a=%u, b=%u, a%%b => %u\n", a, b, a%b); // double % is required to print a single %
   printf("a=%u, ++a => %u\n", a, ++a); // creates a compiler warning that we can ignore for this demo
   printf("a=%u, --a => %u\n", a, --a); // creates a compiler warning that we can ignore for this demo
   printf("b=%u, b++ => %u\n", b, b++); // creates a compiler warning that we can ignore for this demo
   printf("b=%u, b-- => %u\n", b, b--); // creates a compiler warning that we can ignore for this demo
   printf("\n");

   printf("::: Relational Operators :::\n");
   printf("a=%u, b=%u, a==b => %u\n", a, b, a==b);
   printf("a=%u, b=%u, a!=b => %u\n", a, b, a!=b);
   printf("a=%u, b=%u, a>b => %u\n", a, b, a>b);
   printf("a=%u, b=%u, a<b => %u\n", a, b, a<b);
   printf("\n");

   printf("::: Logical Operators :::\n");
   printf("a=%u, b=%u, a&&b => %u\n", a, b, a&&b);
   printf("a=%u, c=%u, a&&c => %u\n", a, b, a&&c);
   printf("a=%u, b=%u, a||b => %u\n", a, b, a||b);
   printf("a=%u, c=%u, a||c => %u\n", a, b, a||c);
   printf("a=%u, !a => %u\n", a, !a);
   printf("c=%u, !c => %u\n", c, !c);
   printf("\n");

   printf("::: Bitwise Operators :::\n");
   // INFO: due to some bitwise operators and printf an implicit cast to int is done,
   //       which we have to revert by casting explicitely back to unsinged char
   //       I also print the HEX value so that you can convert in your head to binary
   //       and that you can try to comprehend what is happening to each bit
   printf("a=%u (0x%X)\n", a, a);
   printf("b=%u (0x%X)\n", b, b);
   printf("c=%u (0x%X)\n", c, c);

   printf("a=%u (0x%X), ~a => %u (0x%X)\n", a, a, (unsigned char)(~a), (unsigned char)(~a));
   printf("b=%u (0x%X), ~b => %u (0x%X)\n", b, b, (unsigned char)(~b), (unsigned char)(~b));
   printf("c=%u (0x%X), ~c => %u (0x%X)\n", c, c, (unsigned char)(~c), (unsigned char)(~c));

   printf("a=%u (0x%X), b=%u (0x%X), a&b => %u (0x%X)\n", a, a, b, b, a&b, a&b);
   printf("a=%u (0x%X), c=%u (0x%X), a&c => %u (0x%X)\n", a, a, c, c, a&c, a&c);

   printf("a=%u (0x%X), b=%u (0x%X), a&b => %u (0x%X)\n", a, a, b, b, a|b, a|b);
   printf("a=%u (0x%X), c=%u (0x%X), a&c => %u (0x%X)\n", a, a, c, c, a|c, a|c);

   printf("a=%u (0x%X), b=%u (0x%X), a&b => %u (0x%X)\n", a, a, b, b, a^b, a^b);
   printf("a=%u (0x%X), c=%u (0x%X), a&c => %u (0x%X)\n", a, a, c, c, a^c, a^c);

   printf("a=%u (0x%X), a<<1 => %u (0x%X)\n", a, a, a<<1, a<<1);
   printf("a=%u (0x%X), a>>1 => %u (0x%X)\n", a, a, a>>1, a>>1);

   return 0;
}
