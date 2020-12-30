#include <stdio.h>
#include <math.h>


int isEqualDouble(double m, double n, double epsilon)
{
   return (fabs(m-n) <= epsilon);
}

int main(void)
{

   printf("        m is %.100lf\n", 0.1                    );
   printf("        n is %.100lf\n", 0.3 - 0.2              );
   printf("fabs(m-n) is %.100lf\n", fabs(0.1 - (0.3 - 0.2)));
   printf("  epsilon is %.100lf\n", 0.000000000001         );

   if(isEqualDouble(0.1, 0.3 - 0.2, 0.000000000001))
   {
      printf("is equal\n");
   }
   else
   {
      printf("is NOT equal\n");
   }
   
   return 0;
}

