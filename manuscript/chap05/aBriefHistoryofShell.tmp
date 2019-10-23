body {
 	color: black;
 	font-family: Arial, Helvetica, sans-serif;
	max-width: 768px;
 	margin: 10px 15px 20px; 
}
p, dd, blockquote { 
 	text-align: justify;
}
a {
 	text-decoration: none;
}
a:link {
 	color: blue
}
a:visited {
 	color: purple
}
a:hover {
 	text-decoration: underline; 
} 

 
# A Brief History of Shell Commands

In the [first chapter](#writeAshellFunction), we composed one-line
functions on the command line.  And promised more information on
how to *compose simple functions on the command line*.  This
exercise fulfills the promise.  You will see how using the command
history makes it easy to create a shell function from an often-used
command.

A subsidary objective of this chapter is to postone the use of a 
text editor on a file.  If you are comfortable with any of the text
editors, by all means use your favorite.  You will still gain 
something from facility on the command line.

There is a short collection of composing functions on the command line
on my [YouTube channel][martyutube].  It should help to compose
and edit functions on the command line.

No new functions are introduced in this chapter.


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


## New Concepts

+ shell command history
+ identify two editor modes to edit command history
+ use command history numbers to recall a previous command
+ define a function by adding the function syntax, 
  either by editing a previously recovered command, or cutting and
  pasting a piece of history with a mouse.

To do this, you will walk thru some command history, navigating
forward and backward, finding a line and edit the line in your history
to turn it into a function.


## Shell Command History 

Here is an [excellent tutorial][jjhistory] on using the shell command
history.  

### Editor Modes 


The shell has two editor-based history modes, *vi* and *emacs*
as well as keyboard commands to navigate the shell history.  To use
the text editors for shell history, you navigate with the editor's
line and inter-line movement mechanisms.  

You might reasonably ask at this point, "So, what's with this editor
business?  I thought we wouldn't have to learn an editor."  Be
assured, it's easier to navigate thru command history if you can
handle the few cursor movement commands the editor offers.  Then
editing a single line is simply moving the cursor back and forth to
insert or delete characters.

To see all the available shell options use a **set -o** command.
Try that at your terminal window.  Execute this command to see which
your current editor mode is set at:

    $ set -o            # shows all the options and their state
    $ set -o | grep -E '^(vi|emacs)'  # collect the edit modes
    emacs           on
    vi              off
    $ 
    
This shows I am using the *emacs* mode, which I prefer to *vi*
mode or keyboard navigation.  The editor modes toggle: if one is on,
the other is off.  To set your preference, you might:

    $ set -o vi

to switch to the *vi* mode.  You may want to consult
[this cheat sheet of editor modes] [bashhist].  If this is your first
encounter with command history, I recommend vi mode.  Vi is a moded
editor.  After switching to vi mode, as above, and inspecting the
cheat sheet, the vi shortcuts are entered by preceeding the first
command with the _escape_ "[esc]" on my keyboard, followed by the
letter from the table.  Therefore to go back in history _[esc] k_.
The escape key toggles navigation while in vi mode. To continue back,
continue to strike the _k_ key; to go foward, the _j_.  To stop
navigation, the _[esc]_ key.

## history list
Recall your
[experiment with the dateArg function](#useFunctionArguments).  Your
first attempt was a simple date command:

    $ date +%F

Here's a piece of my recent shell history which shows how the command may be
turned into a function:

    $ history | awk '$1 > 616'

      617  date +%F
      618  date "+F: %F"
      619  set F
      620  date "+$1: %$1"
      621  set c
      622  date "+$1: %$1"
      623  history | awk '$2 ~ /date/'
      624  history | awk '$1 > 590'
      625  history | awk '$1 > 616'
    $ 

How did I discover the line number to begin?

I'm looking for the date command, so the first attempt (my # 623) was
to identify all the uses of _date_.   I thought I'd start at the
reported # 590, that proved to be more than I needed, so I settled
on #614, which was the latest bit of practice

Type the first three commands (617, 618, 619) at your terminal window
now.  And do **not** type the line numbers.  Line number 619 sets the
first **positional parameter** to the letter *F*, just as it would be
when passed to a function. You might try

    $ echo $1

or, if you still have the _ea_ alias:

    $ ea

to verify that.

Then, on  line 620, instead of  typing the whole command,  you may use
the  history to  recover  your  previous typing.   In  this case,  the
command is  quite brief; you could  have typed it  again from scratch.
If you need practice in your history, instead of typing 620 literally,
do this:

* go back two commands, on my terminal, and maybe yours, the
  up-arrow also works. In emacs mode, hit **[ctrl]P** to go
  back one, in vi mode, hit **[esc]** to enter command mode,
  where **K** goes back in history and **J** goes
  forward.

* use line-editing commands, again the **delete** or backspace
  keys may work.  If you need more help, consult the cheat sheet
  above.

* change the literal *F*. to the shell variable *$1* in both
  instances, and then either *Enter* or *Return* to execute
  the command.

On line 621, change the first positional parameter to the lower-case
*c*, and re-execute the command by stepping back two lines in
history to line 807.

You can repeat that for as many letter options as you'd like.  Also,
if you want to do any "out-of-bounds" testing, this is a good time to
try.

## The simple step -- the function 

With command history, it is now quite simple to turn your recent
efforts into a function.  All that is necessary is to wrap the latest
command instance with the function syntax, the most important part of
which is a proper name.  As it's possible to recall a history command
by number, here is how you might proceed:

    $ !622
    date "+$1: %$1"
    c: Mon Jul  1 09:58:20 2013
    $ dateArg () { date "+$1: %$1"; }
    $ fbdy  dateArg
    dateArg () 
    { 
        date "+$1: %$1"
    }
    $ 

Where my history line number was 622.  Inspect your history and
recover your command with the exclamation using the line-number or
your command.  Now, rather than type the whole function definition
*dateArg () { ... }*, simply retrieve the just-executed command by
going back one line in the history ( to the *date ...* command), but
not re-execute it.

* Move to the beginning of the just-retrieved line in your history
    buffer (i.e., do not hit the Enter key),

* then enter the function name, parenthesis, and opening brace,
  *dateArg () {* In front of the function text,

* and finally, go to the end of the line, and close with the
  semi-colon and closing brace, *; }*.

## Terminal Cut and Paste

Should using editor modes (vi or emacs) be a problem, your terminal
should also offer cut and paste from past history on the command line.

If that's your preferred mode, then

* start the command by entering the leading text:

     $ dateArg () {

* then follow by cutting and pasting the command:

     $               date "+$1: %$1"

* which will appead: 

     $ dateArg () {  date "+$1: %$1"

* and close by entering the closing syntax:

     $                              ; }

* yielding:

     $ dateArg () {  date "+$1: %$1"; }

and you have your function.    I recommend the editor modes.
The time investment will be repaid.

## Review 

* Assessment

    * do you have a preferred editor mode, or do you prefer keyboard
        navigation?

    * did you experiment with several options to the **date**
        command?

    * did you [refresh your experiment](#inspectAfunctionBody)
        with the *set \-\-* command?

* Questions

    * do you understand how the formatted **date** options behave?

    * ... how the *set \-\-* command works?

* *Did you understand the **history** command?*. The pipe to **awk** is
    a little bonus?

* *Did you succeed in creating the **dateArg** function?*

* *If not, can you assess where you got hung up?*

* *Are you able to recall all the functions you have written?*
    You will learn this shortly.

Here's a sneak peak at one of the next facets:

    $ gh () { history | grep -i ${*:-()}; }

What might you use it for?

You may  [Contact Me](mailto:martymcgowan@alum.mit.edu?subject=aBriefHistoryOfShell)

