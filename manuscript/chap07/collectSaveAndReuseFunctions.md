<link rel="stylesheet" type="text/css" href="./mcgowan.css" />
<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<h1>Collect, save, and re-use functions</h1>

<p>All that remains for your newly-gained facility with shell functions
is to collect a group of them, save them in a useful way, and make
them available for reuse: to make them part of your working
vocabulary.</p>

<p>To collect the functions, and save in a useful way means when you
return to a later terminal session, you don't have to re-enter them,
but think of then as commands, as if they were separate shell scripts.</p>

<p>In this  exercise, you'll collect,  save, and make the  functions you've
created in this book available for routine re-use.</p>

<h2>New Concepts</h2>

<ul>
<li>collect new commandline functions</li>
<li>save the functions into a library</li>
<li>re-use the function library</li>
<li>record command usage and results</li>
<li>save a list of functions</li>
<li>redirecting stderr and stdout</li>
</ul>

<h2>New Functions</h2>

<ul>
<li>gh -- Grep the History</li>
<li>quietly -- quiet the noise, e.g. stderr</li>
<li>ignore -- the stdout. there are times to ~</li>
<li>prov -- command provenance and results</li>
<li>function_list -- list of functions to this point.</li>
</ul>

<h2>History, and Quietly</h2>

<p>First, three simple little function to add peace and quiet to our
commands.  Two more will follow later in after saving the functions.
Adding these functions demonstrates how maintain a library of short
functions withour recourse to a text editor</p>

<p>The <strong>history</strong> builtin gets us started.  It's often a command,
or more likely, part of a command we remember:</p>

<pre><code>$ history
</code></pre>

<p>lists our command number, a one-up sequence from our last login
followed by the command. Here is a <a href="http://www.catonmat.net/download/bash-history-cheat-sheet.txt" title="Cheat sheet">cheat sheet of editor modes</a>
for the many command options.</p>

<p>So to make our life simpler, this function Grep's the History:</p>

<pre><code>gh () { history | grep -i ${*:-.}; }
</code></pre>

<p>When developing functions it may be useful to put diagnostics on the
standard error: <code>stderr</code>.  The first opportunity is what I call the
<em>semantic comment</em>.   The shell offers the sharp sign as a leading
comment delimiter:</p>

<pre><code>$ command with args ... #  this is a comment
</code></pre>

<p>which must be used with care:</p>

<pre><code>some_function ()
{
    : this is likely a comment
    ...
}
</code></pre>

<p>Here we say "likely" since it is possible to execute things on
such a line.  For the moment, the semantic comment:</p>

<pre><code>comment () { echo $* 1&gt;&amp;2; }
</code></pre>

<p>used anywhere, frequently in a function</p>

<pre><code>some_function ()
{
    comment this is certainly a comment
    ...
}
</code></pre>

<p>as the text <em>this is certainly a comment</em> is sent to the stderr.
The noisy syntax in the <strong>comment</strong> function, "1>&amp;2", says to
"redirect the standard output (1) onto the standard error (2)".
Once learned and put in very few functions, it may be forgotten
until you have to explain it to one more novice than yourself.</p>

<p>Two similar functions will further reduce the need for more noise.
These are <strong>quietly</strong> and <strong>ignore</strong>. We have a choice here. My
thought was "quietly" is for the <em>stderr</em>, and "ignore" is for
the <em>stdout</em>.   Occasionally, you can ignore your output; often
you will want the error messages to go quietly.</p>

<pre><code>quietly () { "$@" 2&gt;/dev/null; }
ignore  () { "$@"  &gt;/dev/null; }
</code></pre>

<p>Here <em>*/dev/null</em> is the proverbial bit-bucket. The "2>" syntax
says direct to the <em>stderr</em>, while the simple ">" directs the <em>stdout</em>.</p>

<p>So, for example:</p>

<pre><code>$ ignore ls  file  # makes no sense, i.e. throws the output
$ quietly ls file  # suppresses "file not found" message
</code></pre>

<h2>An Experiment in Comments</h2>

<p>Enter the following function on the command line, first entering the function 
definition, then executing each command in turn.</p>

<p>First, note since the function definition includes a trailing comment, the
closing <code>}</code> curly brace must be entered on a separate line.</p>

<p>Then execute the <code>comment_demo</code> function, then execute it as the argument 
to <code>quietly</code> and then to <code>ignore</code>.   </p>

<pre><code>$ comment_demo () { comment this is a comment;  # this is NOT a comment
  }
$ comment_demo
$ quietly comment_demo
$ ignore comment_demo
$ fbdy comment_demo
</code></pre>

<p>Here are the results of executing those commands</p>

<pre><code>comment_demo
this is a comment

quietly comment_demo

ignore comment_demo
this is a comment

fbdy comment_demo
comment_demo () 
{ 
    comment this is a comment
}
</code></pre>

<p>The surprise with the last test: <code>fbdy collect_demo</code> is the
disappearance of the sharp comment.  To demonstrate, edit sharp (<code>#</code>)
comments into any of your functions.  Then either with <code>fbdy</code> or
declare -f notice all those nicely placed comments disappear.  This
then is why the <code>comment</code> function is useful in itself.  Fortunately,
bash offers yet another means to comment shell functions.  This will 
be taken up in a later chapter.</p>

<h2>Collecting</h2>

<p>Now you will collect the functions you have created in this book.
With the exception of <strong>hello</strong>, they will all prove to be generally
useful:</p>

<pre><code>hello
today
dateArg
fbdy
foreach
gh
quietly
ignore
</code></pre>

<p>To collect these functions, use the <strong>fbdy</strong> function.  If
you've used  more than  one terminal session  by this point,  you will
have to go back through the  chapters and re-enter them.  Use a single
terminal session to  do this.  A fair question  is <em>Why</em>?  Because
the shell  functions are in your  shell environment.  To  see all your
current functions, use this basic command.
It will also show a few other shell features:</p>

<pre><code>$ set | grep '()'
</code></pre>

<p>To collect all these functions,  execute this command: for the moment,
output will just be to your <em>stdout</em>, or terminal:</p>

<pre><code>$ fbdy hello today dateArg fbdy foreach gh quietly ignore
</code></pre>

<p>produces:</p>

<pre><code>today () 
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
    echo $* 1&gt;&amp;2
}
quietly () 
{ 
    "$@" 2&gt; /dev/null
}
ignore () 
{ 
    "$@" &gt; /dev/null
}
</code></pre>

<h3>Examine your work</h3>

<ul>
<li>did you see all the functions?</li>
<li>if not, you can use the results here to re-enter the missing.</li>
<li>have you recently used the <strong>gh</strong> function?  it should help to 
run down the missing.</li>
</ul>

<p>You're now ready to save, so you can easily re-use your functions.</p>

<h2>Saving</h2>

<p>As one extra  feature, to  document your  work, I've  added  a useful
function, <strong>prov</strong> standing for the word
<a href="http://www.merriam-webster.com/dictionary/provenance">provenance</a>,</p>

<p>First, enter the <strong>prov</strong> function, and just for fun, <strong>function_list</strong>: </p>

<pre><code>prov ()
{ 
      printf "prov_doc ()\n{\n : $*\n}\n"; "$@"
}
function_list () 
{ 
    echo hello today dateArg fbdy foreach gh quietly ignore
}
</code></pre>

<p>So, now do this to save your work:</p>

<pre><code>$ prov fbdy $(function_list) prov function_list | tee firstlib
$ chmod +x firstlib 
$ cat firstlib
</code></pre>

<p>Produces this, and by virtue of the <strong>tee</strong> command, you've just
stored in <strong>firstlib</strong>.</p>

<pre><code>prov_doc ()
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
    "$@" 2&gt; /dev/null
}
ignore () 
{ 
    "$@" &gt; /dev/null
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
</code></pre>

<h3>Examine your work</h3>

<ul>
<li>There are three functions in the library, not listed in the <strong>function_list</strong>.
  How did they get there?</li>
<li>Particularly, the <strong>prov_doc</strong> function, where did that come from?</li>
<li>How might you modify the <strong>function_list</strong> to include itself and <strong>prov</strong>?</li>
<li>Do you need to add <strong>prov_doc</strong> to the book history?</li>
</ul>

<p>Your <strong>firstlib</strong> is ready for re-use.   </p>

<h2>Reuse</h2>

<p>Do this in two steps, first to show the underlying mechanism,
then how to make sure it's routinely available for each terminal
session.</p>

<h3>test in a new session</h3>

<ul>
<li>Keep your current terminal session.  </li>
<li>record your current directory:  echo $PWD</li>
<li>Open  another and  change directory to  the same location  as your original session.</li>
<li><p><em>source</em> your new library:</p>

<p>$ source firstlib        # or  ". firstlib"; that's a period
   $ fbdy $(function_list)  # shows the function bodies</p></li>
</ul>

<p>If everything is in order, you're ready for the next step.</p>

<h3>restore your library when logging in</h3>

<p>Use the shell's login sequence to enable your new library on each
terminal session.  The most straight-forward is to use your
<strong>.profile</strong>, routinely executed by the <em>login</em> sequence.  Add this
line to the end of your .profile:</p>

<pre><code>source {/the/directory/for/your/}firstlib
echo $(function_list) 1&gt;$2
</code></pre>

<p>You have enabled the functions in the firstlib and then written the
function names on the <em>stderr</em> as a reminder.  The <strong>function_list</strong>
and <strong>comment</strong> functions supplied the list, and then put them on the
standard error.</p>

<p>We  will see,  in a  later book,  my own  personal practice  is  a bit
different.  I like to keep my  profile clean of frequent changes, so I
use yet another file, which  I call <strong>.myrc</strong> for these personal
features.  So, after logging in, often, my first command is just:</p>

<pre><code>$ . ~/.myrc
</code></pre>

<p>which "sources" <em>.myrc</em>. The "rc" part is a  bit of Unix history,
standing for <strong>R</strong>untime <strong>C</strong>onfiguration.  So, it's <em>MY Runtime Configuration</em>.</p>

<p>Choose your preferred way to source the library, edit the file, and 
login yet one more time.  Notice that you saw the comment list of functions</p>

<h2>References</h2>

<h2>Future direction</h2>

<p>These commands show you the direction you'll take:</p>

<pre><code>$ set | grep '()'    # then
$ set | awk '$2 ~ /\(\)/ { print $1 }'
</code></pre>

<p>The  latter,  while   it  may  not  be  perfect,   is  the  basis  for
function-maintenance commands which will be a topic in a later book.</p>

<p>Mail me if <a href="mailto:martymartymcgowan@alum.mit.edu?subject=collecSaveandReuseFunctions">you have questions</a></p>