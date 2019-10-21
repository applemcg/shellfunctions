<link rel="stylesheet" type="text/css" href="./mcgowan.css" />
<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<h1>Shdoc -- SHell DOC comments</h1>

<p>A few of the scripting and system programming languages have comment
conventions for their functions.  <a href="http://www.oracle.com/technetwork/java/javase/documentation/index-jsp-135444.html" title="Oracle JavaDoc main page">JavaDoc</a> was possibly the
earliest example.  Others instances are <a href="https://en.wikipedia.org/wiki/Pydoc" title="Wikipedia Pydoc">pydoc</a>, <a href="http://perldoc.perl.org">perldoc</a>,
<a href="https://en.wikipedia.org/wiki/YARD_(software)">YARD</a>, <a href="https://en.wikipedia.org/wiki/RDoc" title="RubyDoc Wikipedia page">RDOC</a>, <a href="https://en.wikipedia.org/wiki/Mkd_(software)" title="mkd Wikipedia page">mkd</a> , ... and, in general, [asample][comparsion].</p>

<p>As yet, there is no similar feature for the shell. Let's begin.</p>

<h2>New Concepts</h2>

<p>This exercise sets a direction in documenting shell function behavior.</p>

<ul>
<li>document a function, lessons learned from Java, Perl, PYthon ...</li>
<li>shell array FUNCNAME</li>
<li>which function called this function</li>
<li><strong>awk</strong>, simple usage</li>
</ul>

<h2>New Functions</h2>

<ul>
<li>myname - what is the name of my calling function</li>
<li>report_notfunction - report if not called by it's argument</li>
<li>report_notpipe - report if standard input is not on a pipe</li>
<li>report_usage - used by reporting functions</li>
<li>shdoc - _shdoc over a list of functions</li>
<li>_shdoc -- supplies output function format for colon-comments</li>
<li>shd_justcolon -- returns leading colon comments</li>
</ul>

<h2>the convention</h2>

<p>Since the <code>fbdy</code> function, using the <em>declare</em> built-in, supplies
the function body in a standard format, it's safe to use that as the
conventional layout of a function.  With the standard layout, let's
adopt the convention as these others do, that <em>the first comment lines
after the function definition are special, and regarded as the
function API interface</em>.</p>

<h2>the first functions</h2>

<p>The main function is <code>shdoc</code>, using a few local utilities, and
others which will be described below.</p>

<pre><code>_shdoc () 
{ 
    : date: 2018-02-16;
    report_notfunction $1 &amp;&amp; return 1;
    echo "function ${1}_doc {";
    declare -f $1 | shd_justcolon;
    echo "}"
}
shdoc () 
{ 
    : this is a shell doclib "shdoc" comment;
    : an shdoc comment is the first ":"-origin lines;
    : in the shell function, the rest being the executable.;
    : 2019-01-28 use local _shdoc and produce declare -f format;
    foreach _shdoc ${*:-$(myname)}
}
shd_justcolon () 
{ 
    : returns leading colon-comments from a SINGLE function;
    report_notpipe &amp;&amp; return 1;
    awk '
    NR &gt; 2 {
             if ( $1 !~ /^:/ ) exit
             else              print
           }
    '
}
myname () 
{ 
    : ~ [n];
    : returns name of caller OR callers caller ...;
    : date: 2018-02-16;
    echo ${FUNCNAME[${1:-1}]}
}
</code></pre>

<p>So, <code>shdoc</code> takes an indefinite number of arguments, defaulting to
itself, <code>myname</code>, calling <code>shd_each</code> for each of them.  While it's
tempting to use the wild-card properties of the <em>declare</em> built-in,
this keeps the <em>awk</em> code simpler.</p>

<p>The <code>report_notfunction</code> is part of the <strong>report</strong> family of
functions.  These functions are built to report on <em>assertion
failures</em>.</p>

<p>And, lastly, the <code>myname</code> function, using the <em>bash</em> built-in array,
FUNCNAME, returns the name of the calling function N levels up the
stack.  It defaults to 1, returning the name of the immediate caller.</p>

<p>Here is the result of running shdoc on the same functions.</p>

<pre><code>$ shdoc ...

function _shdoc_doc {
    : date: 2018-02-16;
}
function shdoc_doc {
    : this is a shell doclib "shdoc" comment;
    : an shdoc comment is the first ":"-origin lines;
    : in the shell function, the rest being the executable.;
    : 2019-01-28 use local _shdoc and produce declare -f format;
}
function shd_justcolon_doc {
    : returns leading colon-comments from a SINGLE function;
}
function myname_doc {
    : ~ [n];
    : returns name of caller OR callers caller ...;
    : date: 2018-02-16;
}
</code></pre>

<p>Note, <code>shdoc</code> produces its comment in a function body by the same name
with the <em>_doc</em> ending.</p>

<h2>utility functions</h2>

<p>Here are the <strong>report<em></strong> functions, and a simple <strong>trace</em>call</strong>, and the
rest of their sub-functions.</p>

<pre><code>report_notfunction () 
{ 
    : returns: TRUE when 1st arg "ISN'T" a function,;
    : ... FALSE if it IS a function;
    : date: 2018-02-16;
    declare -f $1 &gt; /dev/null &amp;&amp; return 1;
    report_usage $1 "ISN'T" a function
}
report_notpipe () 
{ 
    : returns: TRUE when STDIN "ISN'T" a pipe;
    : ... FALSE if stdin is a pipe;
    : date: 2018-02-16;
    [[ -p /dev/stdin ]] &amp;&amp; return 1;
    report_usage "ISN'T" reading a pipe
}
report_usage () 
{ 
    : writes: usage message of report_... caller FAILURE to STDERR;
    : date: 2018-03-30;
    echo USAGE $(myname 3): $* 1&gt;&amp;2
}
</code></pre>

<p>Using <strong>isfunction</strong> is debatable.  My preference is to use meaningful
function names, even where the built-in or command is so simple.</p>

<p>And the result of <code>shdoc</code> on those functions:</p>

<pre><code>function report_notfunction_doc {
    : returns: TRUE when 1st arg "ISN'T" a function,;
    : ... FALSE if it IS a function;
    : date: 2018-02-16;
}
function report_notpipe_doc {
    : returns: TRUE when STDIN "ISN'T" a pipe;
    : ... FALSE if stdin is a pipe;
    : date: 2018-02-16;
}
function report_usage_doc {
    : writes: usage message of report_... caller FAILURE to STDERR;
    : date: 2018-03-30;
}
</code></pre>

<h2>awk digression</h2>

<p>This is our first encounter with the <strong>awk</strong> programming language.  It's
too useful in shell environments to not have brief mention in an application
such as this.</p>

<p><strong>Do this:</strong> Read the <a href="https://en.wikipedia.org/wiki/AWK" title="Awk programming language">main article</a>.</p>

<p>For our purpose, an awk script is made up of <em>pattern  { action }</em> pairs.</p>

<p>In its one use here, in the function <code>_shdoc</code>, the built-in <em>declare
-f</em> puts the function body on the standard output to <code>shd_justcolon</code>
using  <a href="https://en.wikipedia.org/wiki/AWK" title="Awk programming language">awk</a>, with its only pattern <code>NR &gt; 2</code>, works on every
line after the second, printing those lines which begin a
colon (:). The script exits when the first non-leading colon is 
encountered.</p>

<p>The <code>_shdoc</code> function adds the leading and trailing context.  It may
all have been done in awk.</p>

<p>The purpose of this exercise is to show the complementary nature of
awk to the shell.  It is much easier to read and understand the awk
code than the equivalent shell expressions for the task.   There's no
clear standard, but you will find a line between data-processing using
<strong>awk</strong> and manipulating system objects, files, directories, and their
relationships using the <strong>shell</strong> .</p>

<h2>Activity</h2>

<ol>
<li><p>write a shell function, using awk to print function names from
function definitions on the either the standard input or from named
files.  (hint: use the <code>cat ${*:--}</code> idiom and think, "what syntax
identifies a function name?" in the text)</p></li>
<li><p>add sufficient <strong>shdoc</strong> to the function. does it need much more
than the requirements in the activity request?</p></li>
</ol>

<h2>References</h2>

<ol>
<li><a href="https://en.wikipedia.org/wiki/AWK" title="Awk programming language">awk</a> -- pattern matching, execution language</li>
<li><a href="https://en.wikipedia.org/wiki/Comparison_of_documentation_generators">comparison</a> -- comparison of documentation generators</li>
<li><a href="http://www.oracle.com/technetwork/java/javase/documentation/index-jsp-135444.html" title="Oracle JavaDoc main page">javadoc</a> -- how to document java function definitions</li>
<li><a href="https://en.wikipedia.org/wiki/Mkd_(software)" title="mkd Wikipedia page">mkd</a> </li>
<li><a href="http://perldoc.perl.org">perldoc</a> -- how do document perl functions</li>
<li><a href="https://en.wikipedia.org/wiki/Pydoc" title="Wikipedia Pydoc">pydoc</a> -- how do document python functions</li>
<li><a href="https://en.wikipedia.org/wiki/RDoc" title="RubyDoc Wikipedia page">RDOC</a></li>
<li><a href="https://en.wikipedia.org/wiki/YARD_(software)">YARD</a> --</li>
</ol>
