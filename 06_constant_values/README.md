
# Constant Values

C has some ways to provide constant values. But upfront we talk quickly about literals and why it is useful to use constant
values.

## literals

What is a literal? Simply the fix values you are using for example to initialize your variables. 

    float Pi = 3.14f;

`3.14f` is the literal. Here some more examples for various types. 

    3
    3u
    3.0
    3.0f
    0xE
    'E'
    "I am a string"

Imagine you implement some functions to calculate surface, volume and perimeter of circles and spheres. You know these
functions use π and you decide to use `3.14f` everywhere. Suddenly you realize "damn, my `3.14f` is not precise enough, I
need more digits". Congrats, you have to change every occurrence of `3.14f` with `3.14159f`. Some seconds later you are
done. Maybe you run your unit tests and something is still off. After 30 minutes off debugging you realize you have typo
for three of your 6 locations. You wrote `3.14195f` instead of `3.14159f`. Okay, so you correct it. Finally it works.
If you would have used a constant value instead of a literal, some work could have been avoided.

Now you learned from your mistakes and you change the formulas using a constant value. So ...

    CirclePerimeter = 2 * 3.14f * Radius;

becomes ...

    CirclePerimeter = 2 * Pi * Radius;

and you define `Pi` somewhere. How to define `Pi` will be discussed now.


## \#define

One solution is to use a so called preprocessor macro.

    #define <macroname> <value>

The binary output is exactly like if you would have use a literal, because macros are just text replacement. You learned
that in [chapter 1](../01_hello_world/README.md) when we talked about `#include`. The same happens for macros.

    #define PI 3.14f
    
    CirclePerimeter = 2 * PI * Radius;

After the preprocessor has done the text replacement the line looks like before.

    CirclePerimeter = 2 * 3.14f * Radius;

If you remember also from [chapter 1](../01_hello_world/README.md), you can use the GCC option `-E` and have a look at
the preprocessed C file. Every occurrence of `PI` will be replaced with the defined text, which is in our case `3.14f`.

But macros have a pitfall. It doesn't look dangerous at first sight but when you think about it or when you ran already
into such in issue you will know what a pain they can be. 

Let's assume you need for whatever reason the following macros which you want to use in some formulas, and `OFFSET` and `P`
are needed also somewhere else separately (the meaning is not of importance).

    #define P      3
    #define OFFSET 2
    #define FACTOR 4
    #define SZ     OFFSET + P

    Result = FACTOR * SZ;

What is the result? On first glance everything feels right.
`SZ` is `OFFSET` + `P`, so `SZ` is `3+2`, makes `SZ` 5. So the result is `FACTOR * SZ`, is `4*5`, is `20`.

Unfortunately that's not the case. The preprocessor will do the text replacement and then the line looks like this. 

    Result = 4 * 2 + 3;

Ups - operator precedence. The multiplication is therefore calculated first, and the result will be `11` and not the
expected `20`. We learned in the [operators chapter](../04_operators/README.md) that we don't want to think about
operator precedence and we simply use parentheses to control the precedence ourselves. Let's do that.

    #define SZ  (OFFSET + P)

    Result = 4 * (2 + 3);

Now the parentheses are part of the macro `SZ` and no matter where you use `SZ` you can be sure that `OFFSET + P` is calculated first. 

The best would be to always use parentheses around macro definitions. Then you are on the safe side also for future
changes. I will show one more example for function-like macros in the upcoming functions chapter. 

By the way, it's common to use upper case letters for macro names. 


## const

The const keyword is used if you want to have a variable immutable. This means that an assignment after the declaration is not possible. 

    int       V = 0;
    const int C = 0;

    V = 123; // possible
    C = 123; // not possible

So we could define ...

    const float Pi = 3.14159f;

or 

    float const Pi = 3.14159f;

and use it ...

    CirclePerimeter = 2 * Pi * Radius;

As you can see, if you write `float const` or `const float` doesn't matter. We will learn more on that in the *pointers* chapter.


## enum

An enumeration is like a list of symbol names to which a value can be assigned automatically or explicitly. Although
enumerations are a type on their own, the underlying datatype of each enumerator is int. 

    enum MyEnum
    {
       <enumname>,
       <enumname>,
       <enumname,
       ...
       <enumname>
    };

Just like for *structs* and *unions* you can `typedef` a nameless `enum`. 

    typedef enum
    {
       <enumname>,
       <enumname>,
       <enumname,
       ...
       <enumname>
    } MyEnum;

By default the first enumerator is initialized with 0, the second with 1, and so on. It is possible to initialize enum
elements explicitly but if you think you need that then there is a high chance that you are using enums wrongly. You
should never rely on enumerators having specific values. You should use enums in a way that you could anytime add, move,
delete enumerators and your code still works. You shouldn't care which value is behind your enumerators. So never ever
use a literal for comparison, use the enumerator if you have created them, because your enum could change over time.

Here an example if you want to have your enumeration starting with 1 instead of 0.

    typedef enum
    {
       <enumname> = 1,
       <enumname>,
       ...
       <enumname>
    } MyEnum;

There is also the possibility to initialize more elements, also in between but I don't recommend it. At most your first
element should be initialized. Let the compiler do the rest.

I show you one method if you have to iterate your enum. You simply add one more element to the end and give it a proper name.

    typedef enum
    {
       DefaultConfig,
       UserConfig,
       PresetConfig1,
       PresetConfig2,
       ...
       NumOfConfigs
    } Configurations;

And now you can use your last element, here `NumOfConfigs`, for the for-loop break condition, as its value is the number
of elements in that enum without that last element `NumOfConfigs`.

    for(int i=0; i < NumOfConfigs; i++)
    {
       // do stuff
    }

This way your for loop always does the correct number of iterations no matter how many elements you add to or remove
from your enumeration in the future.

---

> **Core Messages**
>
> Avoid so called magic numbers (literals), especially when used twice or more times, and use constants instead.
>
> Put parentheses around your macros.
>
> Initialize at most the first enum element.

