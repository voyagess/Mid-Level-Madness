# Mid-Level-Madness
An extremely small programming language that makes use of only 6 unique instructions, it is by no means a good programming language but you can do a surprising amount in it .

## Commands


We all love variables, and if you love variables as much as I do, you can initialize variables by using the following command:

```javascript
= variable
```

When you initialize variables, they are always set to `0`. Don't worry though, you can change your variable as much as you like after it's initialized.

The space between statements doesn't matter either, for example, the following code will execute without showing an error.

```javascript
=variable 
```

You can have as many spaces as you like!

```javascript
=                              variable
```

Unlike most programming languages, Mid-Level-Madness is simple. This is why in Mid-Level-Madness you can only increment a variable by `1` at a time. You can do this by using the `+` operator.

```javascript
= variable
+ variable
// variable equals 1
```

If you want your number to be even larger than `1`, you can chain these increments together to make this happen.

```javascript
= variable
+ variable
+ variable
// variable equals 2
```

Once you've finished adding to your variable and you are now bored, you can start decrementing your variable by `1` using the `-` operator!

```javascript
= variable
- variable
- variable
- variable
// variable equals -3
```

Now, most of you are probably wondering how we can see the value of our variable once we've changed it. Well, you can do this by using the output operator `<`.

```javascript
= variable
+ variable
+ variable
< variable
// 2
```

It works for negative numbers too!

```javascript
= variable
- variable
- variable
< variable
// -2
```

If regular output is too boring for you, then you can use the character output operator `:`

```javascript
= variable
+ variable
+ variable
: variable
// b
```

You can use this to output any letter you like.

```javascript
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

If you want to save time typing all of that out, then you can use the 'jump if not' operator. 

```javascript
label:
= variable
+ variable
j variable 26 label
: variable
// z
```

You are probably confused, so let me explain how this works to you.
<br>The `j` just tells the interpreter that you are working with a jump statement.
<br>The `variable` is whatever variable you are comparing to the number.
<br>The `26` is the value that the variable is being compared to, in this case, it will jump if variable is not equal to 26.
<br>The final part of the statement is the `label`. This simply states where you want to jump to, in this case it's to the label 'label'.

If you want to print characters like ` ` and `\n` then you can just use the numbers 27 and 28 respectively

```javascript
1.  = variable
2.  + variable
3.  j variable 27 2
4.  : variable
5.  //  
```

also note that labels are defined with a given name for the label, and then a `:`. 
<br>Note that you cannot use `j` in variable or label names, if you do it will cause an error.

You can also compare a variable to another variable in a jump statement.

```javascript
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

```javascript
1.  = variable
2.  + variable
3.  j variable 0 5
4.  < variable
5.  : variable
6.  // a
```

Now that you understand these few, simple commands, you can do anything you like.

## Side Notes

Note that you can also separate statements with the endline character `;` like such:

```javascript
=A;+A;<A
// outputs 1
```

## Examples


### Hello World!

```javascript
= h
= e
= l
= o
= w
= r
= d
= space
hinc:
+ h
j h 8 hinc
einc:
+ e
j e 5 einc
linc:
+ l
j l 12 linc
oinc:
+ o
j o 15 oinc
winc:
+ w
j w 23 winc
rinc:
+ r
j r 18 rinc
dink:
+ d
j d 4 dink
sink:
+ space
j space 30 sink
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

```javascript

=A
=B
=Ainc
=constA

IncB:
+B
j B 10 IncB

IncA:
+Ainc
+constA
j Ainc 12 IncA


ForB:

-B


IncreaseA:
-Ainc
+A
j Ainc 0 IncreaseA


ResetAinc:
+Ainc
j Ainc constA ResetAinc


j B 0 ForB

< A

```

## Interpreting
First you must either download the source code and compile it manually, or download the raw binary. After this, to run your program you must open the command line and enter `'.\mlm.exe filename.mlm'` where you replace `'filename.mlm'` with your input file. Note that if you find any errors with my language that means that it isn't functioning correctly, note that you are wrong and that what you thought was 'incorrect' or 'unexpected' is actually just a feature.
