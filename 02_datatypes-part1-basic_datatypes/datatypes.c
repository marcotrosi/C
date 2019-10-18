#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{

   printf("Let's print the byte size of every basic data type\n\n");

   printf("char %lu byte\n"           , sizeof(char)          ); 
   printf("short int %lu bytes\n"     , sizeof(short int)     ); 
   printf("int %lu bytes\n"           , sizeof(int)           ); 
   printf("long int %lu bytes\n"      , sizeof(long int)      ); 
   printf("long long int %lu bytes\n" , sizeof(long long int) ); 

   printf("unsigned char %lu byte\n"           , sizeof(unsigned char)          ); 
   printf("unsigned short int %lu bytes\n"     , sizeof(unsigned short int)     ); 
   printf("unsigned int %lu bytes\n"           , sizeof(unsigned int)           ); 
   printf("unsigned long int %lu bytes\n"      , sizeof(unsigned long int)      ); 
   printf("unsigned long long int %lu bytes\n" , sizeof(unsigned long long int) ); 

   printf("float %lu bytes\n"      , sizeof(float)      ); 
   printf("double %lu bytes\n"     , sizeof(double)     ); 
   printf("long double %lu bytes\n", sizeof(long double)); 
   
   printf("\nAnd now let's print what the min and max value are that each basic data type can hold\n");
   printf("To do so we need some macros defined in a header file called limits.h\n\n");

   printf("CHAR_BIT   number of bits in a char                = %d\n"   , CHAR_BIT  );
   printf("SCHAR_MIN  minimum value for a signed char         = %d\n"   , SCHAR_MIN );
   printf("SCHAR_MAX  maximum value for a signed char         = %d\n"   , SCHAR_MAX );
   printf("UCHAR_MAX  maximum value for an unsigned char      = %u\n"   , UCHAR_MAX );
   printf("CHAR_MIN   minimum value for a char                = %d\n"   , CHAR_MIN  );
   printf("CHAR_MAX   maximum value for a char                = %d\n"   , CHAR_MAX  );
   printf("SHRT_MIN   minimum value for a short               = %d\n"   , SHRT_MIN  );
   printf("SHRT_MAX   maximum value for a short               = %d\n"   , SHRT_MAX  );
   printf("USHRT_MAX  maximum value for an unsigned short     = %u\n"   , USHRT_MAX );
   printf("INT_MIN    minimum value for an int                = %d\n"   , INT_MIN   );
   printf("INT_MAX    maximum value for an int                = %d\n"   , INT_MAX   );
   printf("UINT_MAX   maximum value for an unsigned int       = %u\n"   , UINT_MAX  );
   printf("LONG_MIN   minimum value for a long                = %ld\n"  , LONG_MIN  );
   printf("LONG_MAX   maximum value for a long                = %ld\n"  , LONG_MAX  );
   printf("ULONG_MAX  maximum value for an unsigned long      = %lu\n"  , ULONG_MAX );
   printf("LLONG_MIN  minimum value for a long long           = %lld\n" , LLONG_MIN );
   printf("LLONG_MAX  maximum value for a long long           = %lld\n" , LLONG_MAX );
   printf("ULLONG_MAX maximum value for an unsigned long long = %llu\n" , ULLONG_MAX);

   printf("\nNotice that there is no unsigned minimum for any of the unsigned types,\n");
   printf("because the unsigned minimum is simply 0\n");

   printf("\nFloating point values shouldn't be missing in this list.\n");
   printf("To display the mins and max for floats we need to include float.h.\n");
   printf("Notice that unlike the signed values above, floats are symmetrical.\n");
   printf("This means that the minimums are just the negative maximums.\n\n");

   printf("FLT_MIN  most negative value of a float       = %f\n" ,  -FLT_MAX); 
   printf("FLT_MAX  max value of a float                 =  %f\n" ,   FLT_MAX); 

   printf("\nAttention - below this line you get freaking long numbers. Activate when ready for it ;-).\n");

   /* printf("DBL_MIN  most negative value of a double      = %lf\n\n",  -DBL_MAX);  */
   /* printf("DBL_MAX  max value of a double                =  %lf\n\n",   DBL_MAX);  */
   /* printf("LDBL_MIN most negative value of a long double = %Lf\n\n", -LDBL_MAX);  */
   /* printf("LDBL_MAX max value of a long double           =  %Lf\n\n",  LDBL_MAX);  */
    
   return 0;
}

