# Binary & Hex Number System

## Counting in decimal, hex & binary system

The decimal system is called like that because it uses ten digits (0-9) to build numbers.
So the octal system accordingly uses 8 digits (0-7). The binary system uses, you guessed it, 2 digits (0-1) only.
What about systems with more digits than the decimal system? It’s the same. For example the hexadecimal system uses 16 digits.
The problem is that the Arabic numbers have no signs that represent digits higher than 9.
We could invent them, but we use simply our Latin letters for that in computer science, means we extend with A-F.
Let’s write them all down for the hex system. 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F. 

Let’s count to 20 in the decimal system, because not everyone sees what’s going on here.
And to visualize it more I will write also some zeros in front which we usually omit. 

DEC|
---|
000|
001|
002|
003|
004|
005|
006|
007|
008|
009|
010|
011|
012|
013|
014|
015|
016|
017|
018|
019|
020|

What we can see is that the first digit (most right position) counts from zero to nine, then it starts again from zero but
simultaneously the second digits does one step to 1. This pattern goes on. When also the second digit reaches 9 and the
first digit is also 9 then both switch to 0 and the third digit will become 1. That’s the moment we switch from 099 to 100.
In other words when every position does a full turn (switching from 9 again to 0) then the next position (to the left)
does one step.


Now the same for Hex, and let me put the decimal value along with it.

DEC | HEX
----|----
000 | 000
001 | 001
002 | 002
003 | 003
004 | 004
005 | 005
006 | 006
007 | 007
008 | 008
009 | 009
010 | 00A
011 | 00B
012 | 00C
013 | 00D
014 | 00E
015 | 00F
016 | 010
017 | 011
018 | 012
019 | 013
020 | 014

And now for binary. It looks weird because we have only 2 values. Bit we really are just following the exact same
principle.

DEC | BIN  
----|------
000 | 00000
001 | 00001
002 | 00010
003 | 00011
004 | 00100
005 | 00101
006 | 00110
007 | 00111
008 | 01000
009 | 01001
010 | 01010
011 | 01011
012 | 01100
013 | 01101
014 | 01110
015 | 01111
016 | 10000
017 | 10001
018 | 10010
019 | 10011
020 | 10100


## Construction of values - Converting to decimal

### Decimals

How can we build values or convert from one number system to another?
For that let's have again a look at the decimal numbers and how they are structured.

    4023

Fourthousandtwentythree. A random number.
We can split this number into the sum of

    4000+20+3

right? So every position has a certain position value or place value.
Even better is it if we write

    (4*1000) + (0*100) + (2*10) + (3*1)

There we can clearly see the ones, the tens, the hundreds, the thousands.
We can write it even in a way that we can see the position, by using 10 to the power of position number.

    (4*(10^3)) + (0*(10^2)) + (2*(10^1)) + (3*(10^0))

We count the positions from right to left, and the most right digit has position 0.


### Binaries

Now for binary numbers it's the same formula, but the place value of each position is not based on the value 10, but on 2.
Let's select a random 8 bit value.

    00110010

Let's break it down with the formula we learned before, but using the base of 2.

    (0*(2^7)) + (0*(2^6)) + (1*(2^5)) + (1*(2^4)) + (0*(2^3)) + (0*(2^2)) + (1*(2^1)) + (0*(2^0))

    (0*128) + (0*64) + (1*32) + (1*16) + (0*8) + (0*4) + (1*2) + (0*1)

    32 + 16 + 2

    50

Oh, did we just convert the binary into a decimal value? Yes, we did.
If you have a closer look at the place values of each bit, then you will notice that it starts with 1 and it doubles with
every bit. 1, 2, 4, 8, 16, 32, 64, 128, 256, ... That's the beauty of 2^x.

Also notice that the first bit has a place value of 1, which is an odd number, and all other bits are even numbers.
This means that you need this bit to build odd number values, or in other words, if you want to know if a number is odd,
you just have to look at the first bit.

    xxxxxxx0 -> even number
    xxxxxxx1 -> odd  number

I want to show you one more thing. Have a look at the following 7 binary values.

DEC | BIN
----|----------
  5 | 00000101
 10 | 00001010
 20 | 00010100
 40 | 00010100
 80 | 00101000
160 | 01010000
320 | 10100000

We started with 5. The next number is 10, then 20, and so on. So always multiplied by 2, right?
What happens to the binary value? It's a simple shift to the left by 1 bit. Do you see that?
So we can quickly multiply with 2 by shifting the whole pattern 1 bit to the left.
A multiplication with 4 would be a shift by 2 bits to the left, and so on. Let's make an example.

    3 * 2

We know the result is 6 and we can achieve that too by shifting the bit pattern of 3 by 1 bit to the left.

    0011 -> 0110

Let's see if it is correct.

    (0*(2^3)) + (1*(2^2)) + (1*(2^1)) + (0*(2^0))
    (2^2) + (2^1)
    4 + 2
    6

Perfect.




### Hexadecimals

Let's repeat for hex. Here a random value.

    0x15AD

    (1*(16^3)) + (5*(16^2)) + (A*(16^1)) + (D*(16^0))

Let's write the `A` and the `D` as decimals. See table above.

    (1*(16^3)) + (5*(16^2)) + (10*(16^1)) + (13*(16^0))

    (1*4096) + (5*256) + (10*16) + (13*1)

    5549

The same boring formula. Nothing special. But I want to show you something interesting.
The base 16 is a factor of 2, and this makes it easy to convert hex into binary directly.
Therefore you just have to look at each position independently and you just need to memorize
or construct the bit values from 0 to F, means from 0 to 15.
We will take again the same value and convert it to binary quickly.

    0x15AD

And now just look at each position independently.

    1 5 A D

And convert each position to binary by using 4 bits.

    0001 0101 1010 1101

    0001010110101101

That's it. Done.


## Converting decimals

We learned how the number systems are build and how we can convert a hex or binary number to decimal.
What about the other direction? How can we convert a decimal value to hex or binary?
I know two methods which I want to show you with examples for hex and binary. 

### Method 1 to Binary - (converting in your head)

This method requires that you know the values for each binary position. 
Here the values as a reminder from position 7 to 0.

    128, 64, 32, 16, 8, 4, 2, 1

Here an example with 8 bits to keep it simple. As we know from the datatypes chapter unsigned integer can hold max the
decimal value 255. So let’s select a random number between 0 and 255 and convert to binary.

    97

First we have to determine the biggest bit position value that fully fits into 97. super simple - it’s 64. 128 would be
too big and the next in the list is 64. Now we just calculate the rest to 97. That’s 33. which next value fits into 33?
The 32. Rest is 1. And for that we also have a bit. So at the end we have 64+32+1, at looking at the binary values this means `01100001`.

This was method 1 in a very human logical way, which can be done in your head easily and especially easy with 8 bits
only, and because binary has only two states per bit - either the bit is 1 and you add the value, or the bit is 0 so you
don’t add it. But there is also a mathematical way for which I quickly need to remind or teach you how to divide with
rest/remainder.


#### Dividing with rest/remainder

What does it mean dividing with rest? Here some quick examples. The value right from the R is the rest or remainder.

    5/2 = 2 R 1

Theoretically this would 2.5 if we would divide with real numbers. But we only take the integer part, which is 2.
This is like 4/2 and the rest/remainder to 5 is 1. But I think you learned that in school before you learned fractions or real numbers.
Here some more examples using this method. Try to understand them, because we will need this now a lot.

    7/2  = 3 R 1
    8/2  = 4 R 0
    3/5  = 0 R 3
    10/4 = 2 R 2


### Method 1 to Binary

Now we try method 1 in a mathematical way, like a formula that can be turned into a software algorithm. For this we need to divide with rest/remainder.
For method 1 we first have to divide our decimal value with all the binary values starting with the highest, and then we
continue to always divide the rest/remainder until the rest/remainder is 0.

    97/128 = 0 R 97
    97/64  = 1 R 33
    33/32  = 1 R 1
    1/16   = 0 R 1
    1/8    = 0 R 1
    1/4    = 0 R 1
    1/2    = 0 R 1
    1/1    = 1 R 0

Do you see that all numbers before the R are only 0 or 1?
This is actually our result, and we just have to read the bits top-down left from the R.

    01100001

That was easy. Let's quickly check if it is correct. Which bits are set to 1? The bits at position 6, 5 and 1, which
means `64+32+1=97`. We can also easily see that in the division above.


### Method 1 to Hex

Same method can be used if we want to convert to Hex.
We again use some random value. For example ...

    3000

Looking at the Hex value list ...

    4096, 256, 16, 1

... we can see 4 digits are enough for this value 3000. 

Let’s start dividing ...

    3000/4006 = 0  R 3000
    3000/256  = 11 R 184
    184/16    = 11 R 8
    8/1       = 8  R 0

Simply reading the values top-down. 

    0 11 11 8
    0  B  B 8
    0x0BB8
    0xBB8

Okay cool, that worked too. 

The problem with method 1 is that you have to figure out with which value you need to start dividing.
And this brings us to method 2. 


### Method 2 to Binary 

Using this method 2 you only need to know to which system you want to convert a value. If you want to convert to binary
you have to divide by 2, if you want to convert to hex then you have to divide by 16. And again we divide with rest/remainder. 
After the first division we continue to divide the integer result until it's 0.

Let’s use the same value 97 as before, so that you can see the differences and similarities.

    97/2 = 48 R 1
    48/2 = 24 R 0
    24/2 = 12 R 0
    12/2 = 6  R 0
    6/2  = 3  R 0
    3/2  = 1  R 1
    1/2  = 0  R 1

And now read the bits, but this time bottom to top and on the right side of R.

Here one more example. The value is 213.

    213/2 = 106 R 1
    106/2 = 53  R 0
    53/2  = 26  R 1
    26/2  = 13  R 0
    13/2  = 6   R 1
    6/2   = 3   R 0
    3/2   = 1   R 1
    1/2   = 0   R 1

Read bottom to top.

    11010101


### Method 2 to Hex 

Same principle, we just divide by 16. Let’s start directly with the same value 3000 as before.

    3000/16 = 187 R 8
    187/16  = 11  R 11
    11/16   = 0   R 11

Read the result right from the R bottom to top.

    11 11 8
    B  B  8
    0xBB8


> **Core Message**
>
> The values of each bit are simply 2^bitpos, and they are just doubling with every position. 1, 2, 4, 8, 16, ...
>
> Hex can easily be converted to binary by converting each hex position individually.
>
> Odd and even numbers can be identified by looking at the first bit (position 0).
>
> A multiplication with 2 is just bitshifting the whole pattern to the left by 1 bit.


![decimal to binary methods](decimal_to_binary.png)
