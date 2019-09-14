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

It is not allowed to divide by 0, because a divsion by 0 is not defined.
So you always have to ensure that your divisor is different from 0.

Another thing you might ask yourself - what happens if the result of an integer divsion would result in a fraction?
Be aware that we are only talking about integer divisons. We will talk about other variants when we talk about data
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
It doesn't matter wheather we write 0/1, false/true, low/high, no/yes or any other binary representant.

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

Before you start with this section be sure to have understood [003_binary_and_hex_number_system](003_binary_and_hex_number_system/README.md).

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

