
# Custom Datatypes

Beside the standard basic datatypes, you can also create your own "custom" datatypes, but only based on the existing
standard datatypes.

## typedef

The first thing you learn is the `typedef` command. It is used to give existing datatypes a new name.
The syntax is ...

    typedef <sourcedatatypename> <newdatatypename>;

Here an example that creates a datatype whose name shows that it's for 32 Bit signed integers.

    typedef int si32;
    
    si32 Var = 4711;

### Creating a 16 Bit signed integer (si16) datatype for 16 and 32 Bit microcontrollers

But why can this be useful? The size of `int` is at least 2 Bytes, but can also be 4 Bytes. This means that `int` doesn't
have a fix bit width, it depends on the system you are compiling for. But when one of your variables needs a certain
width, e.g. 16 Bit, and you are writing your code accordingly, but you have to support 16 and 32 Bit micro controllers,
then you can create your own datatypes to suit your needs. There are actually header files that already do that for you.

    // 16 bit controller - int is 2 bytes (16 bits)
    typedef int si16;

and

    // 32 bit controller - int is 4 bytes (32 bits)
    typedef short int si16;

See, in one case I used `int` and in the other `short int` to get 16 Bit.


### Creating a boolean datatype

C89 unfortunately doesn't have a *boolean* datatype. But we can fake it using `typedef`.

    typedef unsigned char bool;

    #define false ((bool)0U)
    #define true  ((bool)1U)


### Readability

Another simple reason why you want to use custom datatype names is just to increase code comprehension and therefore
reducing human mistakes.

### Type Checks

There are actually tools, so called *static code analyzers*, that can do *strong type checking*.
Normally you get only warnings when the underlying datatypes do not match.

    typedef int si32;
    typedef int sint_32;

    si32    A = 0;
    sint_32 B = 5;

    A = B;

The assignment is technically correct and doesn't cause problems. So no warnings when checking the underlying datatype,
because both underlying datatypes are `int`. But with strong type checking it gives a message, because the datatype
names do not match (si32 != sint_32).


## struct

With the `struct` keyword we can bundle multiple datatypes to a single data structure. You have to give your *structure* a name
so that you can use it to create variables of that type. Let's see how this is done. The `struct` syntax is ...

    struct <structname>
    {
        <datatype> <membername>;
        <datatype> <membername>;
                 .
                 .
                 .
        <datatype> <membername>;
    };

An example

    struct Person
    {
        char         Name[100];
        unsigned int Birthyear;
        unsigned int Height;
    };

This *struct* acts like a template. The moment you create a variable of that *struct* type the variable occupies the memory
of 100 characters and 2 unsigned integers, that's in total 108 Bytes (100+4+4) for this example. Let's create an instance of that *struct*.

    struct Person Marco;

Now we can start filling the *struct* members.

    strcpy(Marco.Name, "Marco");
    Marco.Birthyear = 1980;
    Marco.Height    = 170;

As you can tell, we are using the . (dot) to access a member of the *struct*.

We could have also initialized the variable at declaration. This would look like this ...

    struct Person Marco = {"Marco", 1980, 170};

You can also create nameless *structs*, and provide a name by using typedef. This way you don't need the `struct`
keyword anymore.

    typedef struct
    {
        char         Name[100];
        unsigned int Birthyear;
        unsigned int Height;
    } Person;
    
    Person Marco = {"Marco", 1980, 170};


## union

A `union` definition looks like a `struct` definition but the data is stored totally different. The members of a `struct`
are stored in a row in memory. When using *unions* the members are stacked on top of each other, referring to the same memory.
Depending on the member you are accessing the interpretation of the data is just different. Therefore it is very
important that your union members have the same size, otherwise you get alignment issues.

Let's compare with `struct`.

    struct MyStruct
    {
        int    MyInteger;
        float  MyFloat;
    };

    union MyUnion
    {
        int    MyInteger;
        float  MyFloat;
    };

The *struct* members occupy 4 Bytes each, makes a total of 8 Bytes. Whereas the Union members are pointing to the same 4
Bytes. Means you can interpret the 4 Bytes as integer or as float.

### Printing Float Bits

If we want to print for example the bits of a `float` we can achieve this by putting an `int` and a `float` together in
one union, and then we use the `int` to print the bits. This is necessary because we need some bit operators which don't work with `float`.

    #include <stdio.h>
    
    typedef union
    {
       unsigned int MyInteger;
       float        MyFloat;
    } MyUnion;
    
    
    int main(void)
    {
       MyUnion Number;
    
       Number.MyFloat = 3.14f;
    
       for(int i=31; i>=0 ; i--)
       {
          printf("%d", (Number.MyInteger >> i) & 1);
       }
       printf("\n");
    
       return 0;
    }
    
This prints ...

    01000000010010001111010111000011

... which is the bit representation of `3.14f`.

Checking with [this website](https://www.h-schmidt.net/FloatConverter/IEEE754.html) you can see it's correct.
For more information you can read the Wikipedida [Floating-point_arithmetic](https://en.wikipedia.org/wiki/Floating-point_arithmetic) article,
but it's probably to hard for beginners. I will explain *floating point* types in an upcoming chapter.


### Accessing different parts of data/registers

Another use case for unions, which is handy on micro controllers, is that when using *unions* you can directly access
single bytes without bit shifting and masking operations, or the whole integer by using proper types.

Like in the following example where I used an `int` and an array of 4 `char`, both resulting in 4 Bytes on a 32 Bit machine.

For unions it is also possible to create nameless unions and use typedef to give a name, just as we did for *structs*.

    typedef union
    {
        int       Data;
        char      ByteData[4];
    } MyUnion ;

    MyUnion Var;

    Var.Data = 0xAA0055FF;

    for(int j=3 ; j >= 0 ; j--)
    {
       for(int i=7 ; i>=0 ; i--)
       {
          printf("%d", (Var.ByteData[j] >> i) & 1);
       }
       printf("\n");
    }
    


## Bitfields

Bitfields are a special feature of `struct` where you can give groups of bits a name and access these bits directly by
that name. Again useful for micro controllers where register bits have a specific purpose. But you are only allowed to use
`unsigned int` or `int` for these members as datatype. But that's not a problem, because the size of these isn't used
anyway - you have to specify explicitly how many Bits shall be used. Here is the syntax ...

    struct <StructName>
    {
        <datatype>  <membername> : <bitwidth>;
        ...
    };

As you can see, the only thing that has changed that there is an additional colon after the member name followed by
the number of bits. Let's have a look at an example ...

    typedef struct
    {
       unsigned int BitsA : 4; // bits 0 to 3
       unsigned int BitsB : 4; // bits 4 to 7
       unsigned int BitsC : 8; // bits 8 to 15
       unsigned int BitsD : 9; // bits 16 to 24
       unsigned int BitsE : 3; // bits 25 to 27
       unsigned int BitsF : 1; // bit  28
       unsigned int BitsG : 3; // bits 29 to 31
    } MyBitfield;

These Bits could be a description of a microcontroller register. Of course your members shall have names that reflect the
purpose. Now you can create a variable of that type and access each group of bits by member name.

    MyBitfield Var = {0}; // init all bits to 0
    Var.BitsE = 7;        // set the bits 25:27 to 1, because 7 is 111 in binary

After the assignment this `Var` bitfield looks like that in memory ...

    00001110000000000000000000000000

We defined 32 bits (0-31) and bit 31 is most left and bit 0 is on the right side. And you can indeed print the size of
MyBitfield and it will print 4 bytes (32 bits), and not `7 x sizeof(unsigned int = 4 Bytes) = 28 Bytes = 224 Bits`.

    printf("%lu\n", sizeof(MyBitfield));

We can also combine the Bitfield with a Union to also access all Bits at ones.

    typedef struct
    {
       unsigned int BitsA : 4; // bits 0 to 3
       unsigned int BitsB : 4; // bits 4 to 7
       unsigned int BitsC : 8; // bits 8 to 15
       unsigned int BitsD : 9; // bits 16 to 24
       unsigned int BitsE : 3; // bits 25 to 27
       unsigned int BitsF : 1; // bit  28
       unsigned int BitsG : 3; // bits 29 to 31
    } MyBitfield;

    typedef union
    {
        unsigned int Data;
        MyBitfield   Bits;
    } MyUnion;

    MyUnion Var;
    
    Var.Data = 0; // init all bits to 0

    Var.Bits.BitsE = 7;


Remember from the unions chapter that the union members are referring to the same memory. So here `Data` can be 4 Bytes
and the Bits are also 4 Bytes.
