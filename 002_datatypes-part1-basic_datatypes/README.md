# Data Types - Part 1 - Basic Data Types

This chapter may sound easy and it also kind of is easy, but still many SW errors are due to wrong data types or wrong
interpretation of data. It's actually a very important topic.

## Basic Data Types

C has data types in various sizes for signed integers, unsigned integers and floating point values.
The sizes (bit width) partially depend on the system for which code is compiled. On a 16 bit computer the data types may
have different sizes compared to a 64 bit computer.

Here an example graphic
![Basic Data Types](datatypes.png)

Read and run the datatypes.c file and learn which data types exist, how large they are and which min and max values they
can hold on your system.

## Interpretation

Every value, and they all are just a bunch of 1s and 0s, needs to be interpreted, and this is done by providing each
value a data type information.
When we write ...

    int Foo;

... then we know the number of bytes used for this variable `Foo` and we know how the 1s and 0s need to be interpreted.

We will talk later about the [binary number system](https://en.cppreference.com/w/c/io/fprint://en.wikipedia.org/wiki/Binary_number) and
[`printf`](https://en.cppreference.com/w/c/io/fprintf) but here an example regarding interpretation of value.

Compile and run the `interpretation.c` file.


