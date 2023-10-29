---
title: Thoughts on Forth Programming
author: Felix Winkelmann
---

[ [Original Post](http://www.call-with-current-continuation.org/articles/forth.txt) ]

This is an attempt to describe my understanding of Forth philosophy
and some of its attributes that make it in my opinion particularly
interesting, together with things I find important about the language and
its use. All of this is my personal opinion, and should not be seen as
dogma. I have used various programming languages and didn't like most
of them. I think there are some very elegant and powerful languages,
like Scheme or Prolog, but none of them require such a rethinking of
programming, as Forth does.

Forth is quite "invidualistic", tailored to single persons or small
groups of programmers, mostly because it is natural and relatively
straightforward to implement a Forth system yourself (and you should)
and because the language is inherently malleable and adapts to your needs.
Therefore what I write is just one way of seeing Forth, which is both
a programming language and a engineering philosophy.

As I perceive it, there exist two schools of thought among Forth
programmers: the "classical" school that prefers extreme simplicity,
minimalism, short definitions and being down to the metal as much
as possible, and on the other hand the "modern" school that extends
the classic Forth model with features found in other languages and
which generally strives for making the language more accessible to the
computing mainstream by adding features, tools and generally attempts to
mix the ideas of stacks, reverse polish notation and heavy refactoring
with that what is commonly thought as both essential and desirable for
contemporary programming languages, but what just ends up being some
sort of Lisp with a funny notation. I personally belong to the former
camp which will become more obvious in the passages that follow.

First, Forth builds on some fundamental properties that make it quite
idiosyncratic and may appear quirky, due to its roots in simplicity
and compactness, considering that it emerged in the microcomputer era,
on machines that provided (for today's standards) severely limited
capacity. Yet these attributes result in certain rather peculiar
advantages. One such property is the use of reverse polish notation
and the lack or eschewal of local variables. As argument-passing to
subroutines and primitives takes place on the stack, factoring the
code becomes nearly trivial - expressions can be taken out of context
and moved into new definitions, just as in the "pointfree" style of
functional programming. The emphasis on short definitions and (usually)
a low subroutine call overhead additionally suggests isolating common
code sequences. Local variables make this much more difficult which is
why local variable facilities should be avoided.

Another useful feature is the hyperstatic environment, where later
redefinition of values does not change the meaning of previous uses.
This greatly enhances the stability of already compiled code and reduces
the pressure to find alternative names for existing definitions, if
shadowing of already defined words does not present a problem for code
defined later. Even though Forth provides a quite powerful namespacing
system using vocabularies, it is not strictly necessary to isolate
namespaces just to avoid polluting the environment, unless shadowing is
an issue.

Forth is usually interactive. Since the basic read-eval-print-loop is so
simple, you are able to test all functionality in an interactive manner,
as one of the first things you do is when implementing a forth is bringing
up the toplevel interpreter.  Imagine being able to debug device drivers
interactively (and not sitting in front of a Lisp machine where already
huge amounts of code must exist and work before you are even able to do
so in a high-level language) and you get a glimpse of how much easier
embedded systems programming, testing and epxloration can be.

Interactive debugging at the very early stage also hints at the fact
that bottom up is the usual way of designing and implementing things in
Forth. This carries with it a smell of improvisation and hacking, but
only because our mind is still conditioned on top-down methodologies,
on up-front design, layered architectures and an ideal of planning first
and doing the construction later, ignoring the fact that we seldom have
a full grasp of the complete problem we are trying to solve, and that
requirements, expectations and the knowledge of the underlying system
are fully known in advance, which is simply not true.

In Forth there is only memory - word and byte-sized cells of storage
in memory, and stacks. You step down on the level of assembly language
which may sound daunting, yet gives you full control over every aspect
of memory layout. There are no artificial barriers between you and the
machine's architecture, no abstractions that try to make you believe
you are not on a von Neumann machine, because that's what you are and
acknowleding this gives you in the end true, unveiled access to the
machine's resources. This is good, every C programmer has this level of
access (and needs it), but the Forth programmer will not be surprised
by intransparent machinations of the compiler and brittle abstraction
that just get in the way, like unclear structure layout or undefined
behaviour. When you program against a language standard, you are always
at the mercy of those who interpret it, but if you program against
an implementation then there is nothing unclear, especially if you
made the implementation yourself. In Forth, there is no "yak-shaving":
everything that is between you and your goal has been placed there by
yourself, this is an interesting experience that just shows you how
much of programming work involves doing workarounds for other people's
failures to anticipate what their work will be used for (and which is
something that is actually impossible.)

It just gets worse in languages that attempt to have direct machine
access, yet provide all sorts of restrictions that give a false feeling
of security and which require workarounds when these restrictions are
in the way, or that impose a model of safety that in its significant
complexity requires a lifelong study to truely master.  You can't have
both a language that provides direct low-level access to the machine
and that at the same time give you all advantages of a high-level
environment like automatic memory management. There will be a noticable
gap somewhere that will just require more code, more boilerplate, more
fragile and artificial abstractions. We want to have it both ways, and
believe anybody who promises to make that dichotomy less painful, but
it all fails, as it just moves too far away from the machine, making you
do things just to please the language, the compiler, or the "paradigm".

Now some may bring forward the performance side of things, that more
modern and more complex languages provide heavy duty optimizations that
a language that is basically interpreted can not support (albeit the
Forth interpreter is so low-level that the boundary between compiled code
and interpreted code becomes very thin, and on many CPUs the interpreter
consists of two or three machine instructions). This is technically true,
but whether you need all this heavy optimization work is an open question:
most of your code runs seldom (or never), particularly in the bloatware
that is produced nowadays, and the search for runtime performance has
taken on a somewhat religious meaning. We try to eke out every cycle
of speed, yet never worry about the huge amounts of code involved,
which increase memory traffic and cache misses.  There are many Forth
systems that provide native code compilers (and some of them are quite
sophisticated), but often this is not needed and just costs more in terms
of memory and complexity.  It is satisfying and reassuring to be able to
fully understand the code that is generated from your sources, even if we
ignore the security implications that highly optimizing compilers imply.

Which leads us to compactness, not only on the syntactic level, but on
the abstraction level. The inability to understand software has led to
a proliferation of layers, trying to shield the programmer from details
that he ought not know about. Operating systems (agglomerating their own
abstractions) live below runtime libraries, which in turn are the base
for application level libraries that lay the ground for language-level
abstractions, an ever growing tower of abstraction for abstractions sake,
or better: the admission of our lack of knowledge about what is actually
executing. This is considered a good thing nowadays ("ignorance is
strength"), but it actually gives you nothing but disadvantages. First,
the low-level interfaces to the functionality of operating systems,
binary file formats or direct hardware access aren't as arcane and
forbidding as they are commonly seen. They are only badly documented
(if at all), or contain undocumented extensions specific to particular
systems or applications. Or they are just shoddily designed by hardware
engineers that have decided that the "nice" part of the interface can
be done by the software guys.

In Forth, you ideally just have two layers: the application layer that
provides your programming interface to the problem at hand, and a hardware
layer that gives you primitives for accessing external devices. The real
art is then to unify these two layers, but art is not something that you
learn, you acquire it by other means: by pure experience and reflection.

People in the upper echelons of Forth programming (like Chuck Moore)
design their own hardware and make sure that the interfaces are easy to
use from Forth, but that's not for everybody and brings its own baggage
in terms of tools, languages, standards, paradigms.

Speaking of Mr. Moore: he laid down some wise rules for Forth programming
that appear self-evident but remain hollow phrases if you don't take an
active effort to enforce them.

The main principle is to "keep it simple". Sure, we all want that.
But why do so many insanely complex protocols and architectures
exist? Because no one takes this advice really seriously. After all,
complexity is what programmers thrive for, or better, the impression
of mastering it. Yet, the humbleness required to actually pursue it is
pretty uncommon among our profession. Simplicity not only means simple
code, it also means to simplify the requirements, the features, the
whole functionality.  It means to drop the bells and whistles, the nice
user interfaces, the eye candy, the useless interfaces and protocols,
the legacy support and all the other things that are purported to be
indespensable, but in reality are just compensations for real quality.

The principle to keep things simple has two important corrollaries: First,
"do not speculate" - do not write code or create abstractions that are
only intended for a possible use in the futrue. Meet the requirements that you
have now instead of planning for things that you can not be sure about.

The second corrollary is "do it yourself". This has severe repercussions
if you take this advice seriously. It also emphasizes the need to learn,
something a software developer should never be afraid of and should
actually enjoy. Doing everything yourself frees you from having to
understand mediocre abstractions, bloated libraries full of useless stuff,
and the bugs that necessarily infest code that was written for universal
use by people who have not (and can not) account for the universality of
applications that may possibly use that code. Reuse has become a dogma,
even though there are first signs that it is carefully questioned.
That emphasis on reuse just demonstrates the industrial drive to produce
assets, to create lasting value (call it codebases or intellectual
property). It's an illusion that denies the fact of software rot. What
you reuse of a library is usually just a tiny part, but you pay for all
the unused or pointless functionality and particularly for the bugs that
are not yours.

And this is an important point: to do everything yourself gives you a
superior understanding of the software you produce. It allows you to
modify it at every level to your needs. It makes it possible to be able
to account for every byte (if you do it right) in your binary. When was
the last time you were able to do that? So to program in Forth means,
you invariably implement it yourself, and don't worry about "standards".
As the old saying goes: "If you have seen one Forth - then you have seen
one Forth." And that's totally ok.

The age were single programmers were responsible for whole applications
are over, they say. We are supposed to think in teams and think of those
that come after us, taking over the responsibility. That thinking may
be appropriate if we think in terms of multimegabyte applications, of
all that web-scale megalomania, that, once again, denies that software
remains ephemeral and gets stale, fouls and finally rots.  That thinking
is born out of a taylorized idealistic model of software development where
the developers are little cogs in a big machine who plug together pieces
of Lego. It is a thinking that denies that the underlying assumptions
change, that requirements change, and that no programming language
adequately addresses the very real problems involved when large amounts
of functionality has to change in large amounts of code. We just pretend
it isn't that bad, that a bit of redesign, one or two new layers and
lots of unit testing will be enough and that, one day, we will clean
this all up. the big "rewrite" is something unthinkable, unspeakable,
an admission of weakness, of failure. This is all nonsense, or better:
propaganda. Following "best practices" just means repeating the same
mistakes as everybody else, ignoring intuition and avoid experimenting
with new approaches.

What plays into this is the matter of standards. There are Forth
standards, but one shouldn't take them too seriously.  Standards impose
interface designs that may be suboptimal on the platform you work on. They
are an attempt to do the impossible: to once settle all ambiguities
regarding the use of a language in all possible situations, for all
possible platforms, for all possible applications. The intention is,
of course, to simplify reuse, to ease porting. But we already talked
about this.  Standards can be helpful, but compliance should not be a
goal in itself. Additionally, a universal standard must by definition
be extremely vague. The more platforms are covered, the more vague it
must become to cover all possible implementations, which ends in absurdly
complex behavioural descriptions like you see in the C (or C++) standard,
that can only be understood by lawyers or those that think like them.

And nobody says that code can't be shared, that one should not learn
to understand other people's code or that designs should be hoarded
by lone rangers. But we should understand that in many cases it is
a single programmer or very small team that does the main design and
implementation work for a particular application, or component, simply
because programs (even simple ones) require getting intellectually deeply
involved (without interruptions, please!) into both the subject matter,
the formal or informal requirements, the possible outcomes of different
design decisions and so on. The big design meeting up front, the large
team where everybody knows exactly what everybody is doing at any moment,
is a myth. For fixing bugs and maintenance it may be possible to spread
the work over larger teams, but at that stage the software is already
dying, more or less slowly. It may take decades, but once it becomes
infeasible for a single person to rewrite the core functionality from
scratch, it is dead. No, the ideal is:  y o u  write it, you understand
it, you maintain and change it, you rewrite it as often as necessary
(remember compactness?), you throw it away and do something else.

Forth is a language for solving practical problems. It is a language
for turning LEDs on and off, for moving motors, for writing pixels into
a frame buffer, for writing device drivers, for bringing up something
runnable on single board computers. It is also a language for searching,
sorting and manipulating data and implementing the gruntwork that will
always be in one or the other way a job like that. If you want to parse
XML or JSON, it is surely possible, but it won't make you happy. It
is not a language for writing meaningless abstractions on top of other
meaningless abstractions, or for writing a library that solves a specific
problem in the most possible general way, using that fancy algorithm or
data format that happens to be hip today. It is an excellent tool for
writing virtual machines, assemblers, or custom data formats.  Once you
are willing to simplify the problem to the point where it is natural to
implement it in Forth, while at the same time you are just able to fulfil
the intended goal, you are on the right path. It requires out-of-the-box
thinking and a lot of thought, but rewards you with something that stands
a better chance of not being just another pile of code that barely works,
quickly rots, or ends up being a liability that you regret having ever
written and that has grown to a point where rewriting or replacing it
becomes harder and harder.

Writing "good" Forth code is very hard, or at least what I consider good
Forth code, which may be different from what others consider good. Forth
has been called a "write only language", but only because it requires
an additional effort to simplify your code to a point where everything
becomes obvious. This is an art, it is a moment of transcendence, which
I don't claim to have ever reached, but sometimes I get a glimpse of it,
an inkling of the fact that if I would work very hard on this, it will
become so simple, so heavily factored, using such obvious and clear names
that everything just falls into place. It is this moment that programmers
experience every once in a while, where a short, simple piece of code
just does what it is supposed to do, without any extra baggage, easily
understandable. To achieve it in Forth is much harder, it may require
more time, many rewrites, but the results are even more satisfying,
as the result is smaller, much simpler, fully self-contained and not
burdened by code that you can not trust. When you forget about that urge
of productivity, which has become the moloch we sacrifice our children to,
you may be able to achieve that particular thing that is called quality,
elegance, art. It may take a lifetime, you may never reach that far,
but still you should strive for it.

Or you remain a cog in the machine, developing on absurdly convoluted
"software stacks", using inadequate and brittle languages, connect barely
matching interfaces to only small parts of too many bloated libraries,
using insanely sophisticated tools of incomprehensble complexity and
trot on, asking yourself why everything sucks and why the last time
you actually enjoyed programming and were you could be genuinely and
deservedly proud on what you accomplished, was when you were a kid...
