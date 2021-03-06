
# Write a shell function 

The simplest shell functions may be written on a single line at the
command prompt.

## New Functions

In this chapter, you will write and use two simple shell functions:

+ hello - programmers birth announcement
+ today - from the date command.

## New Concepts

In this chapter you will learn these concepts, how to :

+ write a function on the command line in different formats,
+ call the function,
+ show the function text.
+ use features of the __date__ command

## Hello world 

In this  book, when you see a dollar sign, that stands in for your
command prompt.
    
    $ ...

Here is the Programmers Birth Announcement: **Hello World!**.  Type
this at your command prompt:
    
    $ hello () { echo 'Hello World!'; }

On the above line, following the command prompt, type everything from
**hello** thru the closing curly brace, followed by a carriage return.

You use the  function by typing its name, "hello"  at the command line.
Here  is the function  definition (on  line 1),  followed by  using it
(line 2), and the shell's response (line 3).  The next shell prompt is
on line 4.
     
    $ hello () { echo 'Hello World!' ; }
    $ hello
    Hello World!
    $ 

You can see the definition of a function with the **declare**
bash built-in:
     
    $ declare -f hello

Type that command. Notice your function has been slightly
reformatted. [More on that later](#inspectAfunctionBody).
Here is the results of the command:

    hello () 
    { 
        echo 'Hello World!'
    }

## Getting it right 

The function syntax: 

*name () { command ... ; }*

has a **name** of your choosing, and a **command** or
semi-colon-separated commands of your choosing.  While there are other
ways to define a function, I've found the parenthesis-pair simplest to
identify the name.  A pair of curly braces enclose the commands.  And
if the trailing curly brace is on the same line as a command, you need
a semi-colon separator.  You can separate commands on separate lines.
The only mandatory space in the function definition is the space
following the first curly brace.

For completenes, you will see two other formats to define a function.
In this book, we are using the most concise. The **hello** function could
have just as well been written as

    $ function hello () { echo 'Hello World!' ; }

or

    $ function hello { echo 'Hello World!' ; }

Experiment with both methods of defining the function and follow by
using the **declare** example above.


## More interesting 

Arguments, like file names and options, make functions more useful.
But before looking at how arguments are used, whet your appetite with
this one, called **today**:

    $ declare -f today
    today () 
    { 
        date +%Y%m%d
    }
    $ today
    20170616
    $

Type the definition and invoke your new function **today**.  Since the
**date** format specifcation takes almost any upper- or lower-case
letter, we'll experiment with the all the letter arguments to test
another function.

## Activity

* *What does the **declare** command tell you about the
  function syntax?*

* *how might you write a function to capture that idea?* a good
  answer requires you know how to use function arguments.  feel free
  to experiment.

* *what would you name that function?*

* investigate the options to the **date** command: search for
  *date manual page*.

Mail me if [you have questions](mailto:mcgowan@alum.mit.edu?subject=writeAshellFunction)





