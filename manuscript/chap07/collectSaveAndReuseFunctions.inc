
# Collect, save, and re-use functions 

All that remains for your newly-gained facility with shell functions
is to collect a group of them, save them in a useful way, and make
them available for reuse: to make them part of your working
vocabulary.

To collect the functions, and save in a useful way means when you
return to a later terminal session, you don't have to re-enter them,
but think of then as commands, as if they were separate shell scripts.

In this  exercise, you'll collect,  save, and make the  functions you've
created in this book available for routine re-use.

## New Concepts

+ collect new commandline functions
+ save the functions into a library
+ re-use the function library
+ record command usage and results
+ save a list of functions
+ redirecting stderr and stdout

## New Functions

+ gh -- Grep the History
+ quietly -- quiet the noise, e.g. stderr
+ ignore -- the stdout. there are times to ~
+ prov -- command provenance and results
+ function_list -- list of functions to this point.

## History, and Quietly

First, three simple little function to add peace and quiet to our
commands.  Two more will follow later in after saving the functions.
Adding these functions demonstrates how maintain a library of short
functions withour recourse to a text editor


The **history** builtin gets us started.  It's often a command,
or more likely, part of a command we remember:

    $ history

lists our command number, a one-up sequence from our last login
followed by the command. Here is a [cheat sheet of editor modes][bashhist]
for the many command options.

So to make our life simpler, this function Grep's the History:

    gh () { history | grep -i ${*:-.}; }

When developing functions it may be useful to put diagnostics on the
standard error: `stderr`.  The first opportunity is what I call the
*semantic comment*.   The shell offers the sharp sign as a leading
comment delimiter:

    $ command with args ... #  this is a comment

which must be used with care:

    some_function ()
    {
        : this is likely a comment
        ...
    }

Here we say "likely" since it is possible to execute things on
such a line.  For the moment, the semantic comment:

    comment () { echo $* 1>&2; }

used anywhere, frequently in a function

    some_function ()
    {
        comment this is certainly a comment
        ...
    }

as the text _this is certainly a comment_ is sent to the stderr.
The noisy syntax in the **comment** function, "1>&2", says to
"redirect the standard output (1) onto the standard error (2)".
Once learned and put in very few functions, it may be forgotten
until you have to explain it to one more novice than yourself.

Two similar functions will further reduce the need for more noise.
These are **quietly** and **ignore**. We have a choice here. My
thought was "quietly" is for the *stderr*, and "ignore" is for
the *stdout*.   Occasionally, you can ignore your output; often
you will want the error messages to go quietly.

    quietly () { "$@" 2>/dev/null; }
    ignore  () { "$@"  >/dev/null; }

Here **/dev/null* is the proverbial bit-bucket. The "2>" syntax
says direct to the *stderr*, while the simple ">" directs the *stdout*.

So, for example:

    $ ignore ls  file  # makes no sense, i.e. throws the output
    $ quietly ls file  # suppresses "file not found" message
	
	
## An Experiment in Comments

Enter the following function on the command line, first entering the function 
definition, then executing each command in turn.

First, note since the function definition includes a trailing comment, the
closing `}` curly brace must be entered on a separate line.

Then execute the `comment_demo` function, then execute it as the argument 
to `quietly` and then to `ignore`.   

The final use as an argument to `fbdy` shows why the `comment` function
is useful in itself.   Fortunately, bash offers another means taken up in
in a later chapter


    $ comment_demo () { comment this is a comment;  # this is NOT a comment
      }
    $ comment_demo
    $ quietly comment_demo
    $ ignore comment_demo
    $ fbdy comment_demo
    

Here are the results of executing those commands

    comment_demo
    this is a comment
    
    quietly comment_demo
    
    ignore comment_demo
    this is a comment
    
    fbdy comment_demo
    comment_demo () 
    { 
        comment this is a comment
    }
    

## Collecting

Now you will collect the functions you have created in this book.
With the exception of **hello**, they will all prove to be generally
useful:


    hello
    today
    dateArg
    fbdy
    foreach
    gh
    quietly
    ignore


To collect these functions, use the **fbdy** function.  If
you've used  more than  one terminal session  by this point,  you will
have to go back through the  chapters and re-enter them.  Use a single
terminal session to  do this.  A fair question  is *Why*?  Because
the shell  functions are in your  shell environment.  To  see all your
current functions, use this basic command.
It will also show a few other shell features:
    
    $ set | grep '()'

To collect all these functions,  execute this command: for the moment,
output will just be to your *stdout*, or terminal:

    $ fbdy hello today dateArg fbdy foreach gh quietly ignore
	
produces:


    today () 
    { 
        date +%Y%m%d
    }
    dateArg () 
    { 
        date "+$1: %$1"
    }
    fbdy () 
    { 
        declare -f ${*:-fbdy}
    }
    foreach () 
    { 
        cmd="$1";
        shift;
        for arg in "$@";
        do
            $cmd "$arg";
        done
    }
    gh () 
    { 
        history | grep -i $*
	}
	comment ()
	{
    	echo $* 1>&2
	}
    quietly () 
    { 
        "$@" 2> /dev/null
    }
    ignore () 
    { 
        "$@" > /dev/null
    }


### Examine your work 

* did you see all the functions?
* if not, you can use the results here to re-enter the missing.
* have you recently used the **gh** function?  it should help to 
  run down the missing.

You're now ready to save, so you can easily re-use your functions.

## Saving 

As one extra  feature, to  document your  work, I've  added  a useful
function, **prov** standing for the word
[provenance](http://www.merriam-webster.com/dictionary/provenance),

First, enter the **prov** function, and just for fun, **function_list**: 

    prov ()
    { 
          printf "prov_doc ()\n{\n : $*\n}\n"; "$@"
    }
    function_list () 
    { 
        echo hello today dateArg fbdy foreach gh quietly ignore
    }

So, now do this to save your work:
    
    $ prov fbdy $(function_list) prov function_list | tee firstlib
    $ chmod +x firstlib 
    $ cat firstlib

Produces this, and by virtue of the **tee** command, you've just
stored in **firstlib**.
    
    prov_doc ()
    {
        : fbdy hello today dateArg fbdy foreach gh quietly ignore prov function_list
    }
    hello () 
    { 
        echo 'Hello World!'
    }
    today () 
    { 
        date +%Y%m%d
    }
    dateArg () 
    { 
        date "+$1: %$1"
    }
    fbdy () 
    { 
        declare -f ${*:-fbdy}
    }
    foreach () 
    { 
        cmd="$1";
        shift;
        for arg in "$@";
        do
            $cmd "$arg";
        done
    }
    gh () 
    { 
        history | grep -i $*
    }
    quietly () 
    { 
        "$@" 2> /dev/null
    }
    ignore () 
    { 
        "$@" > /dev/null
    }
    prov () 
    { 
        printf "prov_doc ()\n{\n    : $*\n}\n";
        "$@"
    }
    function_list () 
    { 
        echo hello today dateArg fbdy foreach gh quietly ignore
    }

### Examine your work 

* There are three functions in the library, not listed in the **function_list**.
      How did they get there?
* Particularly, the **prov_doc** function, where did that come from?
* How might you modify the **function_list** to include itself and **prov**?
* Do you need to add **prov_doc** to the book history?

Your **firstlib** is ready for re-use.   

## Reuse 

Do this in two steps, first to show the underlying mechanism,
then how to make sure it's routinely available for each terminal
session.

### test in a new session 

* Keep your current terminal session.  
* record your current directory:  echo $PWD
* Open  another and  change directory to  the same location  as your original session.
* *source* your new library:
     
       $ source firstlib        # or  ". firstlib"; that's a period
       $ fbdy $(function_list)  # shows the function bodies

If everything is in order, you're ready for the next step.

### restore your library when logging in 

Use the shell's login sequence to enable your new library on each
terminal session.  The most straight-forward is to use your
**.profile**, routinely executed by the *login* sequence.  Add this
line to the end of your .profile:
    
    source {/the/directory/for/your/}firstlib
    echo $(function_list) 1>$2

You have enabled the functions in the firstlib and then written the
function names on the *stderr* as a reminder.  The **function_list**
and **comment** functions supplied the list, and then put them on the
standard error.

We  will see,  in a  later book,  my own  personal practice  is  a bit
different.  I like to keep my  profile clean of frequent changes, so I
use yet another file, which  I call **.myrc** for these personal
features.  So, after logging in, often, my first command is just:
    
    $ . ~/.myrc

which "sources" *.myrc*. The "rc" part is a  bit of Unix history,
standing for **R**untime **C**onfiguration.  So, it's *MY Runtime Configuration*.

Choose your preferred way to source the library, edit the file, and 
login yet one more time.  Notice that you saw the comment list of functions

## References


 [awk]:        https://en.wikipedia.org/wiki/AWK                       "Awk programming language"
 [bashhist]:   http://www.catonmat.net/download/bash-history-cheat-sheet.txt        "Cheat sheet" 
 [comparison]: https://en.wikipedia.org/wiki/Comparison_of_documentation_generators
 [javadoc]:    http://www.oracle.com/technetwork/java/javase/documentation/index-jsp-135444.html
                                                                       "Oracle JavaDoc main page"

 [jjhistory]:  https://www.youtube.com/watch?v=MbXofShhMv8         "Joe James on Command History"
 [martyutube]: https://www.youtube.com/channel/UCL-4038hJH6JTCJKoqunFuQ "Marty's YouTube Channel"
 [mkd]:        https://en.wikipedia.org/wiki/Mkd_(software)                  "mkd Wikipedia page"
 [perldoc]:    http://perldoc.perl.org
 [pydoc]:      https://en.wikipedia.org/wiki/Pydoc                              "Wikipedia Pydoc"
 [rdoc]:       https://en.wikipedia.org/wiki/RDoc                        "RubyDoc Wikipedia page"
 [yard]:       https://en.wikipedia.org/wiki/YARD_(software)


## Future direction 

These commands show you the direction you'll take:
    
    $ set | grep '()'    # then
    $ set | awk '$2 ~ /\(\)/ { print $1 }'

The  latter,  while   it  may  not  be  perfect,   is  the  basis  for
function-maintenance commands which will be a topic in a later book.

Mail me if [you have questions](mailto:martymartymcgowan@alum.mit.edu?subject=collecSaveandReuseFunctions)





