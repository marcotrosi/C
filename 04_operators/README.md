# Operators

C has various [operators](https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B) that you can use to solve problems.
These operators can be split in different categories. Let's go through them step by step.


## Arithmetic Operators

OPERATOR NAME      | SYNTAX
-------------------|-------
Basic assignment   |`a = b`
Addition           |`a + b`
Subtraction        |`a - b`
Unary minus        |`-a`
Multiplication     |`a * b`
Division           |`a / b`
Modulo             |`a % b`
Prefix Increment   |`++a`
Postfix Increment  |`a++`
Prefix Decrement   |`--a`
Postfix Decrement  |`a--`


### Assignment

The assignment operator is very basic but also very important as it is used to store values in variables.
Sometimes you might read in compiler or static code analyzer messages the terms "*left hand side (LHS)*"
and "*right hand side (RHS)*", which are referring to the operands left and right of the operators,
unless it's a unary operator that is applied to single value/variable. In the overview table above `a` is LHS and `b` is
RHS. The assignment operator expects LHS a variable to which a value can be stored. RHS must be a value that fits the
type of the LHS variable. It doesn't matter if RHS is a value or a variable or an expression that results in that type.
The assignment operator can also be used in combination with a variable declaration.

    int Var1;           // variable declaration without initialization
    int Var2 = 4711;    // variable declaration with initialization

    Var1 = 123;                // assigning a value to Var1
    Var2 = Var1;               // assigning the value of Var1 to Var2
    Var1 = Var2 + (678 * Var1) // assigning the result of an expression to Var1

### Add, Sub, Mul, Div

If we ignore for now the data ranges there is not so much to learn about `+`, `-`, and `*`. But for the division
operator `/` I need to say some words.

It is not allowed to divide by 0, because a division by 0 is not defined.
So you always have to ensure that your divisor is different from 0.

Another thing you might ask yourself - what happens if the result of an integer division would result in a fraction?
Be aware that we are only talking about integer divisions. We will talk about other variants when we talk about data
types and casts.

    printf("%d", 5/3); // 5/3 would theoretically result in 1.66666667, but the fractional part gets ignored completely.
                       // So this will print 1. Notice that C does not round up or down. The fractional part is just cut away.


### Modulo

Modulo is a division with remainder. Before I explain too much using words, let's have a look at an example.

First let's have a look at the normal mathematical division.

    15.0/2 = 7.5

Now let's repeat the integer division where only the integer part is kept.

    15/2 = 7

And now the modulo operator returning the remainder.

    15%2 = 1

Why is it `1`? How to calculate that? You can for example ask "how often does the divisor fit into the dividend?" In
case of `15` and `2` the answer is `7`. Seven times does the `2` fit into the 15 completely, means `7*2=14`, and the
rest to `15` is `1`. `1` is what remains, so `15%2` is therefore 1, because modulo shows the rest. Why is the `7` so
familiar? Look at the integer division. We could calculate the modulo result using other operators.

    15 - ((15/2)*2)
    15 - (7*2)
    15 - 14
    1

So `a%b` is basically the short form of `a-((a/b)*b)`


Now let's modulo some numbers by `3` and let's have a look at the results.

    0 % 3 = 0
    1 % 3 = 1
    2 % 3 = 2
    3 % 3 = 0
    4 % 3 = 1
    5 % 3 = 2
    6 % 3 = 0
    7 % 3 = 1
    8 % 3 = 2
    9 % 3 = 0

Oh that's interesting - the result is always between `0` and `2`. Or in other words `a%b` has only results between `0`
and `b-1`

If you think this is a weird operator, there are actually many use cases where this is needed.


### Pre/Post In/Decrement

There is only one thing you need to know about ++a and a++. Both are incrementing `a` by `1`, but the prefix notation
returns the new value, whereas the postfix notation returns the old value.

    int a=3;
    printf("%d\n", ++a); // prints 4, because the increment is done first and the new value is then returned
    printf("%d\n", a++); // prints 4, because it increments to 5 but returns the old value 4

Respectively for the decrement operator in pre- and postfix notation.


## Relational Operators

OPERATOR NAME            | SYNTAX
-------------------------|-------
Equal to                 |`a == b`
Not equal to             |`a != b`
Greater than             |`a > b`
Less than                |`a < b`
Greater than or equal to |`a >= b`
Less than or equal to    |`a <= b`

There is not so much to tell about the relational operators, except that their result is kind of boolean.
But C unfortunately doesn't have a real boolean datatype. Instead `0` is treated like `false` and all non-zero
values are treated as `true`.

If you print for example the result of `3 == 3`, then the result is a non-zero number, and it's probably `1` for most
compilers, but you can not rely on that, because it is not specified in the C standard.


## Logical Operators

OPERATOR NAME          | SYNTAX
-----------------------|-------
Logical negation (NOT) |`!a`
Logical AND            |`a && b`
Logical OR             |`a \|\| b`

The result of the logical operators are also boolean-like.
Let's have a look at the logic tables of these operators.
It doesn't matter whether we write 0/1, false/true, low/high, no/yes or any other binary representative.

`a`|`b`|`a && b`
---|---|-------
`0`|`0`|`0`
`0`|`1`|`0`
`1`|`0`|`0`
`1`|`1`|`1`


`a`|`b`|`a \|\| b`
---|---|-------
`0`|`0`|`0`
`0`|`1`|`1`
`1`|`0`|`1`
`1`|`1`|`1`


`a`|`!a`
---|----
`0`|`1`
`1`|`0`

Attention here with the logical negation operator `!`. A non-zero number negated is zero, and zero negated is something
non-zero but it is not specified which non-zero value. Do not assume or rely on `!0` being `1`.


## Bitwise Operators

Before you start with this section be sure to have understood [03_binary_and_hex_number_system](../03_binary_and_hex_number_system/README.md).

The bitwise operators are, as the name implies, applied to every single bit of their operands.


OPERATOR NAME       | SYNTAX
--------------------|-------
Bitwise NOT         |`~a`
Bitwise AND         |`a & b`
Bitwise OR          |`a \| b`
Bitwise XOR         |`a ^ b`
Bitwise left shift  |`a << b`
Bitwise right shift |`a >> b`


### Bitwise NOT

The bitwise NOT, which is the only unary operator in that list, inverts every single bit in a value. Means that every
`0` becomes a `1`, and every `1` becomes a `0`. Let's have a look at an example using an 8bit value.

OPERAND/RESULT | VALUE
---------------|----------
`a`            |`01001110`
`~a`           |`10110001`

### Bitwise AND

Just write the operands one above the other and apply a logical AND for every single bit position.

OPERANDS/RESULT | VALUE
----------------|----------
`a`             |`01001110`
`b`             |`01101001`
`a & b`         |`01001000`

### Bitwise OR

OPERANDS/RESULT | VALUE
----------------|----------
`a`             |`01001110`
`b`             |`01101001`
`a \| b`         |`01101111`

### Bitwise XOR

For the exclusive OR (XOR) operator the result is `true` when only one of both operands is `true`.

`a`|`b`|`a ^ b`
---|---|-------
`0`|`0`|`0`
`0`|`1`|`1`
`1`|`0`|`1`
`1`|`1`|`0`

Here an 8bit example.

OPERANDS/RESULT | VALUE
----------------|----------
`a`             |`01001110`
`b`             |`01101001`
`a ^ b`         |`00100111`

### Bitwise left shift

For the bitwise left operation, every bit of `a` is shifted to the left by the same amount `b`.
All bits that are shifted out to the left are lost, and all bits coming in from the right side are zeros.

OPERANDS/RESULT | VALUE
----------------|----------
`a`             |`01001110`
`a << 1`        |`10011100`

### Bitwise right shift

Here the same but in the other direction.

OPERANDS/RESULT | VALUE
----------------|----------
`a`             |`01001110`
`a >> 3`        |`00001001`

## Applications for bitwise operations

### Setting and unsetting bits using bitwise operations

Especially in microcontroller development it is often necessary to set or unset specific bits.
Because the microcontroller registers can be used to configure the functionality of the microcontroller.
Often you have to set or unset specific bits, which have a certain meaning, but without changing the other
bits.

In the following examples I will write the binary and hex values.

#### Setting bits

Let's say we have an 8bit register with the following content ...

    10110110 (0xB6)

And we want to set the bit at position zero, means the most right bit.
So the result would be ...

    10110111 (0xB7)

How can this be achieved with bitwise operations?
We have to use the bitwise OR for setting bits. Let's check that out.


      10110110 (0xB6)
    | 00000001 (0x01) => apply bitmask
      ---------------
      10110111 (0xB7)

If you check the logic table of the OR operator, then you will notice that as soon one of the two bits at each position
is 1 the result is 1.
So we can use the pattern `00000001` to keep the bits 1-7 unchanged and to set bit 0 explicitly to 1.
Generally speaking setting bits can be done with the following two rules

- use bitwise OR
- a 0 doesn't change the other operands bits
- a 1 sets the bit

What if we want to set another bit? Or maybe multiple bits? No problem. Just follow the 2 rules.
If we want to set the bit at position 3, then use ...

      10110110 (0xB6)
    | 00001000 (0x08) => apply bitmask
      ---------------
      10111110 (0xBE)

And one more trick. You can create these bits by shifting a 1 to the desired position.
`00000001 (0x01)` is basically `0x01 << 0` a zero shifted `1`.
`00001000 (0x08)` is `0x01 << 3` means a `1` shifted `3` bits to the left and so it ends up on position 3.
Wow, that's easy to remember.



#### Unsetting bits

Here we need the bitwise AND. Because it's like to opposite of the OR operator. If one of the 2 bits at each position is
0, the result is 0 for that position.

Let's say we want to unset bit 7. You can also say you want to set it to 0. Just a different wording.

      10110110 (0xB6)
    & 01111111 (0x7F) => apply (inverted) bitmask
      ---------------
      00110110 (0x36)

- use bitwise AND
- a 0 unsets the bit, or sets it to 0
- a 1 doesn't change the bit of the other operand

Can the so called *bitmask* also be generated as we did before with the bitwise OR? Yes.
We shift the 1 to the position we need, and then we invert bitwise all the bits.
`00000001 << 7` is `10000000`, and now invert using `~`, `01111111`. Done.


### Checking if bits are set

Sometimes you have to check if certain bits are set or not. How can this be achieved?

Let's say we have the following value ...

    01010111 (0x57)

and we want to know if bit 0 (most right bit) is set or not. We can set all other bits to 0 and now we can look at the
whole number. If the whole number is 0 then the bit was not set, if the whole number is 1 then the bit was set.

      01010111 (0x57)
    & 00000001 (0x01) => apply bitmask
      ---------------
      00000001 (0x01) => value is 1, bit was set

Now an example where the bit is not set.

      01010110 (0x56)
    & 00000001 (0x01) => apply bitmask
      ---------------
      00000000 (0x00) => value is 0, bit was not set


### Extracting bits

This is the same as in the previous section for checking bits, but with one more step.
We additionally have to shift to the right.

      01101001 (0x69)

Let's say we want to store the bits 3-5 into a variable.

       01101001 (0x69)
     & 00111000 (0x38) => apply bitmask
       ---------------
       00101000 (0x28)
    >> 00000011 (0x03) => shift to right by 3
       ---------------
       00000101 (0x05)


## Compound assignment operators

Some operators can be combined directly with an assignment.

    +=, -=, *=, /=, %=, <<=, >>=, &=, ^=, |=

But they are just another way of writing assignment and operator in case LHS of both operators is the same variable.

    a = a + b;

Can be written as ...

    a += b;

Because `a` is left from `=` and `+`.

I do not recommend the usage because it can be overseen easily and you should write code that can be understood quickly
without making mistakes.


## Operator precedence

Operators have a certain [precedence](https://en.cppreference.com/w/c/language/operator_precedence), means the order of
evaluation is not only from left to right, the order depends also on the operators.

    x = a * b + c;
    x = c + a * b;

How are these 2 lines evaluated? It's twice the same because multiplication is calculated before addition.
But we want to read and understand code fast and so I highly recommend using parentheses to control or highlight the
operator precedence explicitly.

    x = (a * b) + c;

Even if you think now that this is useless, especially for `*` and `+`, but trust me it gets more complicated with the
other operators, and the past decades have shown that it's smart to avoid human mistakes wherever possible.

---

> **Core Messages**
>
> Modulo % gives the remainder of a division with rest/remainder.
>
> Attention with the pre and post notation of the increment and decrement operators.
>
> Bitwise operators are important on microcontrollers. 
>
> Compound assignment operators may be overseen.
>
> Write readable and understandable code.
>
> Don't rely on operator precedence and use parentheses.
