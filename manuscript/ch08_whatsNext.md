<link rel="stylesheet" type="text/css" href="./mcgowan.css" />
<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<p><link rel="stylesheet" type="text/css" href="./mcgowan.css" /></p>

<h1>Whats next? {#whatsNext}</h1>

<p>Before taking  a peek at what's  next, it's time to assess  where you are.
First, you've used these commands and shell built-ins,
in more or less the order encountered in the text:</p>

<pre><code>echo
date
declare
for
do
done
set
eval
local
shift
history
grep
awk
source
tee
chmod
cat
printf
</code></pre>

<p>If you have any questions about them, it's quite simple to search for
<strong>bash shell</strong> <em>command-name</em> in your favorite search engine.</p>

<p>You now possess the skills to begin crafting your own function library
and make it available for later terminal sessions.  You are now able
to collect and re-use functions as you come to need them.  You'll
collect them, store and re-use them as multiple instances of the one
case you have worked in the book.</p>

<p>As you do that, you'll recognize other challenges:</p>

<ul>
<li><p>how do I use these functions as part of another library?</p></li>
<li><p>can I repair a function quickly as the need arises and easily restore it 
to its proper library?</p></li>
<li><p>it seems I'm getting a large collection of functions: how do I keep them
straight?</p></li>
</ul>

<h2>Looking ahead {#whats-next-looking}</h2>

<p>The very next subject I'm planning is that of library management.  I've 
functions on hand to:</p>

<ul>
<li><p>capture a daily log of when functions were created.</p></li>
<li><p>quickly update a function library with additions or changes</p></li>
<li><p>delete a function or move a function from one library to another, </p></li>
</ul>

<p>This all belongs to a practice I've established on the content and form
of a function library:</p>

<ul>
<li><p>building a Quick-Reference, which may be part of </p></li>
<li><p>more extensive documentation</p></li>
<li><p>what you may, may not, and must do when <em>source</em>ing a library.</p></li>
</ul>

<p>This is all supported by what I've called: <em>Then only backup
system you'll ever need</em>. That said, in the last two years, I've been
an avid user of <a href="http://github.com/applemcg">github</a>.  Since I'm
not yet that experienced with <strong>git</strong>, so what you'll see in the
backup system I offer might be called a crutch, but I use it as the
routine check-point, preserving files in a more accessible state than
git offers: i.e., using ordinary commands, such as <strong>cp</strong> to
retrieve a backed-up version, which may be more than one edition old.</p>

<p>And to control versions,  the subject of the <em>cloud</em>
appears.  At this moment, that includes git, and 
<a href="http://Dropbox.com">Dropbox</a>,  so  a practice  and a  function
library to make that usage as  concise as you need.  In the last month
(Sept-Oct  2013)  I've started  using  Dropbox  as my  virtual  <strong>HOME</strong>
directory.</p>

<p>At some point I will discuss the distinction between using shell
function libraries and the more common parlance of the <em>shell script</em>.
If you haven't noticed this yet, I hadn't use the term before.  That's
conscious, since much of my practice is devoted to the command line.
We will need to make the connection between this view of the shell,
and connecting to the business needs.  A good place to do that is
constructing an application suitable for a
<a href="http://en.wikipedia.org/wiki/Cron">cron_job</a></p>

<h2>Further ahead</h2>

<p>I have shell functions for the major application areas of:</p>

<ul>
<li><p>file backup -- "The Only Backup You'll Ever Need"</p></li>
<li><p>database -- I've been carrying around a personal copy of the 
too-little-used 
<a href="http://www.amazon.com/Relational-Database-Management-Prentice-Hall-Software/dp/013938622X">RDB</a>. <br />
Originally built on <a href="http://www.grymoire.com/Unix/Awk.html">awk</a>
there are now <em>perl</em>-based implementations.   I've stayed close
to the author's original idea that <em>the shell is the only 4GL 
you'll ever need</em>.</p></li>
<li><p>documentation -- quite honestly, I'd worked on a nice auxiliary
library for Markdown, the technology used in this book.  However,
I'm doing most of my personal writing in Emacs' OrgMode.  Which
brings up another question: what is the better way to leave text for
the ages?</p></li>
</ul>

<p>Mail me if <a href="mailto:martymcgowan@alum.mit.edu?subject=whatsNext">you have questions</a></p>
