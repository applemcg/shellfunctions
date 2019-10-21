<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" />
<link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>
<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" />
<link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<h1>Loop with foreach</h1>

<p>In the last chapter you used the <em>for ...  do; ... done</em>; syntax to
iterate over a list.</p>

<h2>New Concepts</h2>

<ul>
<li>avoid using a local variable in a function</li>
<li>re-use a command from the command history</li>
<li>use expanded positional parameter features</li>
</ul>

<h2>New Functions</h2>

<ul>
<li>foreach - execute function on args ...</li>
</ul>

<h2>The for syntax</h2>

<p>Now you will work with the <strong>for</strong> syntax to produce the <strong>foreach</strong>
function that handles many loop requirements.</p>

<p>The shell has other useful <em>looping</em> constructs, namely the <strong>while</strong>
loop, which executes while a conditional expression is true.  The
<strong>for</strong> loop is our focus here.  It executes for each of its arguments.</p>

<p>You  will use the <strong>for</strong> loop to write a function suggested in
your <a href="#useFunctionArguments">exercise with function arguments</a>:</p>

<pre><code>$ foreach dateArg {a..z}
</code></pre>

<p>Recall the dateArg function:</p>

<p>dateArg ()
{
    date "+$1: %$1";
} </p>

<p>So, the reason for the <strong>foreach</strong> function should now be clear:
<em>execute the first argument, a function or command "for each" of the
remaining arguments</em>  The <strong>bash</strong> shell has added the syntactic
sugar <em>{a..z}</em> to produce the lower case letters as separate arguments
in any command. Long before that feature became available, I used
functions named <em>letters, Letters</em>, and <em>LETTERS</em> to produce the
lower- and upper-case alphabets.</p>

<p>Recall the earlier example with <strong>dateArg</strong>: </p>

<p><em>for var in list... ; do command(s) using $var ... ; done</em></p>

<p>specifically:</p>

<pre><code>$ for opt in {a..z}; do dateArg $opt; done
</code></pre>

<p>If you don't have your <strong>dateArg</strong> function handy, re-enter it now.
Then type the above command to execute it.  Notice the generic <em>opt</em>
argument could be any relevant name.  Also, notice the position of the
dateArg function; it is called once per lower-case letter.</p>

<h2>The foreach function</h2>

<p>Enter this text to create your function, and test it:</p>

<pre><code>foreach () { for arg in ${@:2}; do $1 $arg; done; }
echo "# foreach dateArg ..."
foreach dateArg a e i o u     # a purposely shorter list
echo "# fbdy foreach dateArg"
fbdy foreach dateArg
</code></pre>

<p>Here are the <em>foreach dateArg</em> results:</p>

<pre><code># foreach dateArg ...
a: Sat
e: 18
i: i
o: o
u: 6
# fbdy foreach dateArg
foreach () 
{ 
    for arg in ${@:2};
    do
        $1 $arg;
    done
}
dateArg () 
{ 
    date "+$1: %$1"
}
</code></pre>

<p>The first <strong>foreach</strong> definition treats the first argument as the
command and the second and subsequent arguments to that command, which
may be a function.</p>

<p>Foreach may handle an indefinite number of arguments, the first is
always executed "for each" following argument. It uses the highlighted
parameter expansion syntax, in this case <em>${@:2}</em> which selects from
the second argument through the remainder.  This allows the use of
<em>$1</em> in it's position, saving the use of a local variable name.
Another reason for concise functions: you are not juggling too many
names or concepts to require local variable names.  Find your own
comfort level with local variables.  And always use the <em>local</em>
keyword.  Shell variables are <strong>global</strong> unless declared to be local.</p>

<p>Notice the use of <strong>fbdy</strong> it encourages writing concise functions.</p>

<p>The inspiration to write the <strong>foreach</strong> function came from teaching a
course in <a href="https://en.wikipedia.org/wiki/Tcl" title="Tcl in Wikipedia">Tcl</a>, which has a similar function.  It seems useful
to have available in the shell.</p>

<h2>Questions</h2>

<ul>
<li><em>did you compare the foreach function to the for command?</em></li>
<li><em>did you notice the additional syntax in the function?</em></li>
<li><em>did you notice how the function body was displayed?</em></li>
<li><em>what does ${@:2} mean?</em></li>
<li><em>is it possible to nest calls to foreach</em></li>
</ul>
