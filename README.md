# Mid-Level-Madness
An extremely small programming language that makes use of only 6 unique instructions, it is by no means a good programming language but you can do a surprising amount in it .

## Commands


We all love variables, and if you love variables as much as I do, you can initialize variables by using the following command:

```java
= variable
```

When you initialize variables, they are always set to `0`. Don't worry though, you can change your variable as much as you like after it's initialized.

Always make sure you leave a space between your `=` and 'variable'!

```java
=variable 
// error as you forgot whitespace  
```

Unlike most programming languages, Mid-Level-Madness is simple. This is why in Mid-Level-Madness you can only increment a variable by `1` at a time. You can do this by using the `+` operator.

```java
= variable
+ variable
// variable equals 1
```

If you want your number to be even larger than `1`, you can chain these increments together to make this happen.

```java
= variable
+ variable
+ variable
// variable equals 2
```

Once you've finished adding to your variable and you are now bored, you can start decrementing your variable by `1` using the `-` operator!

```java
= variable
- variable
- variable
- variable
// variable equals -3
```

Now, most of you are probably wondering how we can see the value of our variable once we've changed it. Well, you can do this by using the output operator `<`.

```java
= variable
+ variable
+ variable
< variable
// 2
```

It works for negative numbers too!

```java
= variable
- variable
- variable
< variable
// -2
```

If regular output is too boring for you, then you can use the character output operator `:`

```java
= variable
+ variable
+ variable
: variable
// B
```

You can use this to output any letter you like.

```java
= variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
+ variable
: variable
// z
```

If you want to print characters like ` ` and `\n` then you can just use the numbers 27 and 28 respectively

```java
= variable
+ variable
j variable 27 2
: variable
//  
```

If you want to save time typing all of that out, then you can use the 'jump if not' operator. 

```java
1.   = variable
2.   + variable
3.   j variable 26 2
4.   : variable
5.  // z
```

You are probably confused, so let me explain how this works to you.
<br>The `j` just tells the interpreter that you are working with a jump statement.
<br>The `variable` is whatever variable you are comparing to the number.
<br>The `26` is the value that the variable is being compared to, in this case, it will jump if variable is not equal to 26.
<br>The final part of the statement is the `2`. This simply states what line you want the program to jump to if the conditions match, in this case it is `2` but you can set it to anything you like.

You can also compare a variable to another variable in a jump statement.

```java
1.  = variable
2.  = variable2
3.  + variable2
4.  + variable2
5.  + variable2
6.  + variable
7.  j variable variable2 6
8.  < variable
9.  // 3
```

You can even jump forwards!

```java
1.  = variable
2.  + variable
3.  j variable 0 5
4.  < variable
5.  : variable
6.  // a
```

Now that you understand these few, simple commands, you can do anything you like.

## Side Notes

If you want to write a comment, you don't need to have the `//`. Anything that isn't an MLM command will be interpreted as a comment.

```java
= variable
+ variable
THIS IS A COMMENT
+ variable
THIS IS ALSO A COMMENT
< variable
// 2
```

You also can't use comments at the end of a statement like such:

```java
= variable
+ variable
< variable  // 1
```

## Examples


### Hello World!

```java
= h
= e
= l
= o
= w
= r
= d
= space
+ h
j h 8 9
+ e
j e 5 11
+ l
j l 12 13
+ o
j o 15 15
+ w
j w 23 17
+ r
j r 18 19
+ d
j d 4 21
+ space
j space 27 23
: h
: e
: l
: l
: o
: space
: w
: o
: r
: l
: d
```


### Multiplication Program

```java
= A
= B
= Ainc
= constA
+ B
j B 111 4
+ Ainc
+ constA
j Ainc 111 7

// initiallise A as 6 and B as 8
// and initiallise two increments 'Ainc' and 'Binc'

- B


- Ainc
+ A
j Ainc 0 17

+ Ainc
j Ainc constA 21


j B 0 14

< A
```

If you want to change the two values being multiplied, then just change the jump statement at the start for `B` to the desired value and the value for `Ainc` to the desired value.


### Fibonacci calculator

```java
= x
= y
= z
= number
= constY

+ x
+ y
+ z
+ z

< x

+ number
j number 100 15

// start of main fibonacci loop
+ x
j x z 20

+ constY
j constY y 23

+ z
- y
j y 0 26

+ y
j y x 30

< z
- number
j number 0 19
```

Note that this program will run extremely slow due to the nature of this programming language.


## Interpreting
Once you've downloaded the source code, to run your MLM file, you must first change the file type to '.mlm'. This is not necessary but it is way cooler if you do this. Finally you must rename the file to 'input.mlm', put this file in the same directory as 'Mid_Level_Madness_interpreter.cc' and then compile and run 'Mid_Level_Madness_interpreter.cc'. If all went well, you should be seeing your code working perfectly. Note that if anything goes wrong it is 100% your fault as my code is perfect with no issues whatsoever. 
