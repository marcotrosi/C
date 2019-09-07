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
first digit is also 9 then both switch to 0 and the third digit will become 1. That’s the moment we swith from 099 to 100.
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


## Construction of values

### Decimals

How can we build values or convert from one number system to another?
For that let's have again a look at the decimal numbers and how they are structured.

    4023

Fourthousandtwentythree. A random number.
We can split this number into the sum of

    4000+20+3

right? So every position has a certain adicity.
Even better is it if we write

    (4*1000) + (0*100) + (2*10) + (3*1)

There we can clearly see the ones, the tens, the hundreds, the thousands.
We can write it even in a way that we can see the position, by using 10 to the power of position number.

    (4*(10^3)) + (0*(10^2)) + (2*(10^1)) + (3*(10^0))

We count the positions from right to left, and the most right digit has position 0.


### Binaries

Now for binary numbers it's the same formula, but the adicity of each position is not based on the value 10, but on 2.
Let's select a random 8 bit value.

    00110010

Let's break it down with the formula we learned before, but using the base of 2.

    (0*(2^7)) + (0*(2^6)) + (1*(2^5)) + (1*(2^4)) + (0*(2^3)) + (0*(2^2)) + (1*(2^1)) + (0*(2^0))

    (0*128) + (0*64) + (1*32) + (1*16) + (0*8) + (0*4) + (1*2) + (0*1)

    32 + 16 + 2

    50

Oh, did we just convert the binary into a decimal value? Yes, we did.
If you have a closer look at the adicity of each bit, then you will notice that it starts with 1 and it doubles with
every bit. 1, 2, 4, 8, 16, 32, 64, 128, 256, ... That's the beauty of 2^x.

Also notice that the first bit has an adicity of 1, which is an odd number, and all other bits are even numbers.
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

We know the result is 6 and we can achieve that too by shifing the bit pattern of 3 by 1 bit to the left.

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

> **Core Message**
>
> The values of each bit are simply 2^bitpos, and they are just doubling with every position. 1, 2, 4, 8, 16, ...
>
> Hex can easily be converted to binary by converting each hex position individually.
>
> Odd and even numbers can be identified by looking at the first bit (position 0).
>
> A multiplication with 2 is just bitshifting the whole pattern to the left by 1 bit.

