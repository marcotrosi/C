
# Flow Control

We learned a bit about datatypes and operators. To do some proper coding we also need to learn about the flow control
mechanisms of the C language. 

I’m sure you have heard of if-else, for-loop, while-loop, etc., and that’s exactly what we will talk about in this chapter.

## Decisions

### if-statement 

The if-statement is used to execute the next statement only if a certain condition is fulfilled, means if the condition
evaluates to true, means in C is non-zero.

    if( <expression> )
        <statement>;

Here `<expression>` could be a condition like `x > 10`, and `<statement>` could be for example a function call or an
assignment.

    if( x > 10 )
        printf("%s", x);

Means the `printf` statement/function call, gets only executed if `x` is bigger than `10`. Because if `x` is bigger than `10`,
e.g. `x=15`, then the whole expression/condition (`x > 10` => `15 > 10`) evaluates to *true*, because `15` is bigger than `10`, and
so the next statement gets executed. If `x` is `10` or smaller then the statement is simply not executed.

But what if we have to execute more than one statement?

    if( x > 10 )
        printf("%s", x);
        x = 0;

Because of the indentation, and especially Python users might think that, it looks like the assignment is also executed
only when `x` is bigger than `10`, but that's not the case. The assignment is executed always because the if-statement
controls only the very next statement, and C doesn't care about your indentation. You could even write a whole program
in a single line.

#### comma operator
But how to execute the assignment along with the printf?

One very stupid solution would be to use the *comma* operator. The *comma* operator? Yes, and we haven’t talked about the
comma operator yet because I don’t recommend its usage in “normal” lines of code.

    if( x > 10 )
        printf("%s", x), x = 0;

Don't do it! It's not readable. It's confusing and often you need way more expressions than just 2 and your code quickly
becomes cluttered.

#### goto
But what else could be used?

C has something called `goto`. You can define *labels* and jump to them with the `goto` keyword. In our case we could do again
something stupid, invert the condition and use `goto`.

    if( x <= 10 )
            goto skip;
            
    printf("%d", x);
    x = 0;
        
    skip: 

Omg, that's so ugly. Please don't do that.

If you really have to use goto someday, you should follow the following 2 rules ...

1. never jump backwards, jump only forwards.
2. don't leave the current scope, stay within your curly braces.

But everything can be solved also without goto. It's not needed.

#### grouping statements

Okay enough bad code seen for today. I show you how it is done properly. You can group the statements using curly braces
like this ...

    if( x > 10 )
    {        
        printf("%d", x);
        x = 0;
    }

All the statements within the curly braces become a single statement for the if-statement. I highly recommend to always
use curly braces even if it is only a single statement, because it's much more readable this way and when you have to add
more lines then you are already prepared.

#### coding style

One more thing regarding the curly braces. But this is a personal preference and such discussion can trigger a holy
style war in forums. 

I use the following style ...

    if(<expression>)
    {
       <statements>
    }

not ...

    if(<expression>){
       <statements>
    }

Because I like to see in my editor which curly braces belong together. So I put mine in the same column. You might hear
arguments like *“a good editor highlights bracket couples when positioning the cursor on one of them”*, but ...

1. First you need such an editor, and who is saying that you will read your code on your computer using your editor
   only. Or maybe you use cat or [bat](https://github.com/sharkdp/bat) to print code in the terminal or you even print code on paper or as PDF/HTML. 
2. Even with highlighted brackets it’s still easier to see. Especially when the opening bracket is on long lines.

But that's just my style and you have to find your own. If you have to indent code of other people you can use
[uncrustify](https://github.com/uncrustify/uncrustify). It’s a code beautifier with many control options.


### if-else-statement

Sometimes you don't only want or don't want to execute lines of code, but you want to execute other lines of code
instead.

Theoretically you could do the following ...

    if( x > 10 )
    {        
        doStuff();
    }

    if( x <= 10 )
    {        
        doOtherStuff();
    }

But for these use cases we have if-else.

    if( x > 10 )
    {        
        doStuff();
    }
    else
    {        
        doOtherStuff();
    }

Here the else-statement covers automatically all cases where x is not bigger than 10, means x is smaller or equal to 10.
But there is a subtle difference between the first and the second solution. In the first solution both if conditions are
evaluated always. In the second solution there is only one if condition that can be evaluated and if this expression
evaluates to false then the execution immediately continues in the else branch.

### the ternary operator

There is one more operator we haven't talked about yet, and this operator is like an inline-if-else. The ternary operator. 

    <expression> ? a : b

If the expression is true return a, else b. Here is the only super useful use case I know ...

    int NumOfErrors = 0;
    printf("the tool found %d error%s\n", NumOfErrors, (NumOfErrors == 1) ? "" : "s");
    
    NumOfErrors = 1;
    printf("the tool found %d error%s\n", NumOfErrors, (NumOfErrors == 1) ? "" : "s");
    
    NumOfErrors = 2;
    printf("the tool found %d error%s\n", NumOfErrors, (NumOfErrors == 1) ? "" : "s");

and the output would be ...

    the tool found 0 errors
    the tool found 1 error
    the tool found 2 errors

AND THIS my fellow friends, is how you avoid messages like *"the tool found 1 errors"*. Uh, disgusting and so easy to
fix as you can see.

### if-else if-else

In C you can have kind of nested if-else blocks to get multiple decisions. Other languages have extra keywords for that.
Python - elif. Lua - elseif. Perl - elsif. In C the syntax is as follows ...


    if( <expression1> )
    {        
        <statement1>;
    }
    else if( <expression2> )
    {        
        <statement2>;
    }
    else if( <expression3> )
    {        
        <statement3>;
    }
    else
    {        
        <statement4>;
    }

Of course you can nest as often as you want. Here again as soon as an expression evaluates to true the remaining
expressions are not evaluated anymore. This leads us directly to the switch-case-statement.

### switch-case

switch-case statements can be used similar to the if-else if-else-statement. The result of `<expression>`, which is most
of the time just a variable, decides to which case to jump and executes the code there.

    switch(<expression>)
    {
        case <value1>:
            <statements>;
    
        case <value2>:
            <statements>;
    
        case <value3>:
            <statements>;
    
        default:
            <statements>;
    }


And again, of course you can write as many cases as you need. 
Let's check an example and see how it behaves.


    #include <stdio.h>
    
    int main(void)
    {
       int Input = 0;
    
       printf("1. delete file\n");
       printf("2. copy file\n");
       printf("3. rename file\n");
       printf("please select 1, 2 or 3: ");
    
       scanf("%d", &Input);
    
       switch(Input)
       {
          case 1:
              printf("delete file\n");
    
          case 2:
              printf("copy file\n");
    
          case 3:
              printf("rename file\n");
    
          default:
              printf("unknown action\n");
       }
    
       return 0;
    }

I compile, execute and enter the following ...

    1. delete file
    2. copy file
    3. rename file
    please select 1, 2 or 3: 2

and the output is ...

    copy file
    rename file
    unknown action

As you can see the cases act like an entry point. My selection 2 (copy file) is where the code continues and all other
following cases are also executed. How can this be avoided? We have to use the `break` statement at the end of every
case and it is recommended to put a `break` also on the last case which is the `default` case in our example.
The `break` statement quits the whole switch-case immediately. By the way, the `default` case is not mandatory, but you can
use it to cover all cases not matching the explicitly listed cases. It's like the `else` of an if-else if-else-block.

       switch(Input)
       {
          case 1:
              printf("delete file\n");
              break;

          case 2:
              printf("copy file\n");
              break;

          case 3:
              printf("rename file\n");
              break;

          default:
              printf("unknown action\n");
              break;
       }

Now it works ...

    1. delete file
    2. copy file
    3. rename file
    please select 1, 2 or 3: 2
    copy file

One more example to show you how omitting the `break` statement can be used on purpose.

    #include <stdio.h>
    
    int main(void)
    {
       char Input = 0;
    
       printf("(Y)es or (N)o: ");
    
       scanf("%c", &Input);
    
       switch(Input)
       {
          case 'y':
          case 'Y':
              printf("do it\n");
              break;
    
          case 'n':
          case 'N':
              printf("don't do it\n");
              break;
    
          default:
              printf("unknown selection\n");
              break;
       }
    
       return 0;
    }

What has changed? First, instead of a number I read in a character.
The user can select either the upper case or the lower case variant, the execution continues at the `case` of what has
been select (y,Y,n,N) and if the lower case characters have been given by the user, then there is nothing to do but
there is also no `break` statement, so the code continues with the next case which is the upper case character.

If you like you can also use curly braces for each `case`.

    switch(<expression>)
    {
        case <value1>:
        {
            <statements>;
            break;
        }
    
        default:
        {
            <statements>;
            break;
        }
    }

This can give you some advantages when editing code with editors like Vim, which have certain features to select, copy,
delete, etc. regions quickly. Or when your editor can fold regions surrounded by curly braces.

## Loops

Often it is necessary to repeat some code. To avoid repetitive lines of code we can use various types of loops, which
allow repeating code in an elegant way. C has 3 different loops. The for-loop, the while-loop and the do-while-loop
(which in other languages may be called repeat-until).

The for-loop is usually used when you know how often you have to repeat a piece of code. The while-loop is used for zero
or more iterations, and the do-while loop is used for 1 or more iterations.

### for-loop

    for(<initialization>; <condition>; <increment>)
    {
        <statement>
    }

`<initialization>`, `<condition>` and `<increment>` are used to control the loop count variable. `<initialization>` is
used to set the starting point of the loop. Here you initialize the loop count variable. `<condition>` determines when
the loop ends. `<increment>` modifies the loop count variable. It can be also a decrement instead of an increment. You
should modify the loop count variable only here, and not somewhere else.

    int i;

    for(i=1; i<=10; i++)
    {
        printf("%d\n", i );
    }

Here another variant where the loop count variable is declared within the loop initialization, and decremented by steps of 2.

    for(int i=10; i>=0; i=i-2)
    {
        printf("%d\n", i );
    }

Coming back to the comma operator. The loop control might be a legit location for the usage of the comma operator. 

    for(i=0, j=1; i <= 10; i++, j=j+3)
    {
       doCrazyStuff();
    }


### break

The `break` keyword, which we learned before when we talked about switch-case, can also be used to immediately quit
any type of loop. The code execution continues right after the loop.

Here a useless example to show how `break` works in loops.


    #include <stdio.h>
    
    int main(void)
    {
       for(int i=1; i<=10; i++)
       {
          if( i == 7 )
          {
             break;
          }
    
          printf("%d\n", i);
       }
    
       return 0;
    }

This gives the following output ...

    1
    2
    3
    4
    5
    6

... because when `i` is 7 then the loop quits immediately.

### continue

There is also the `continue` keyword, that skips the rest of the current loop iteration and starts immediately the next
iteration. Here another useless example to demo the behavior of `continue`.


    #include <stdio.h>
    
    int main(void)
    {
       for(int i=1; i<=10; i++)
       {
          if( i == 7 )
          {
             continue;
          }
    
          printf("%d\n", i);
       }
    
       return 0;
    }

And the output will be ...

    1
    2
    3
    4
    5
    6
    8
    9
    10

... and you can see that there is no 7 printed, because when `i` was 7 the loop iteration was interrupted, the
`printf` was never reached, and the next iteration was started immediately.


### while-loop

    while(<condition>)
    {
        <statements>
    }

As long as the condition is fulfilled the code within the curly braces is executed. Use `break` and `continue` for more
control.


### do-while-loop

    do
    {
        <statements>
    }
    while(<condition>)


The do-while-loop is just like the while-loop but it enters at least ones because the condition is checked at the end of
each iteration. Use `break` and `continue` for more control.


### endless loops

The term *endless loop* can be interpreted in two ways.

1. Your program is buggy, for example due to a faulty loop condition which leads to an endless loop. This means your
   code never really continues, it's stuck in the loop. On a PC you have to kill your program. Microcontrollers have
   a so called "watchdog" mechanism for that. If you are stuck in an endless-loop, then you can't trigger the watchdog
   and the micro will be reset after some milliseconds.
2. A mechanism to create an endless loop (outside) but of course within the loop (inside) you need to take care of
   breaking the loop, otherwise your code is buggy and you have the situtation as descriped before under point #1.

Here some ways to create endless loops as in described under point #2.

    for(;;)
    {
        // take care of loop break inside loop body
    }

    while(1)
    {
        // take care of loop break inside loop body
    }


> **Core Messages**
>
> Avoid comma operator and `goto`.
>
> Always use curly braces for `if`, `else` and loops even if it is only for a single statement.
>
> Use `break` also for the last `switch` case.
