..  _course-overview:

Course Overview
###############

..  include::   /references.inc

Course Textbook
***************

The textbook (see :cite:`Patterson:2017`) selected for tyhis course is a bit
high level for what we want to cover. For that reason, I will not be teaching
strictly through that text, and will present the topics in an order I feel
makes more sense for what we want to accomplish. I will assign readings out of
the text to augment the lecture notes posted on this website.


Course Tools
************

We will use a number of development tools in this course. Some of these will
not be familiar to you, but they are an essential part of software development
in today's world, so it will be good for you to learn about these new things.

Read over the material at this link to set up your personal machine for this
course. If you choose to use lab machines, everything should be ready to go!

    * :ref:`virtual-machines`

What we will cover
******************

Welcome to *COSC2325 and the world of Assembly Language*. This course is
designed to give you a much deeper understanding of how modern computer systems
work. We will explore how computers are put together at the lowest level, and
how they *really* work. In fact, you will build a computer of your own by
creating a simulator for one (see :cite:`DictRef1`)

We will study the modern *Personal Computer* powered by a Pentium processor and
learn about *assembly language*. Later, we will explore hardware control
systems using popular microcontrollers; the Arm 32 bit processor, and the Atmel
AVR chip.


We will look closely at the modern computer:

* How the systems are organized
 
* How they are programmed at the lowest levels

We will focus on two types of systems

* The modern PC (Pentium - 64 bit)

* Microcontrollers (8-bit and 32-bit systems used for hardware control)


Prerequisites
*************

You are supposed to have at least two semesters experience in programming in a
high level language:

* C/C++

* Java

* Visual Basic (I had a minor role in designing this language)

We will be using C for some examples
    
You should be comfortable with the basic concepts of structured programming.
You should be able to write programs using the ``sequence``, ``decision block
(if-then-else)`` and the standard loops: ``do-while``, ``do-until`` and the
``counted loop``. 

This course assumes you know how to write simple programs. Do not forget that!
Just because you will be learning how to program in a new, strange language,
you still know how to program! Use your previous experience to guide you in
writing in this new language.

Your view of the computer
*************************

You already know how to program, so this should look at least vaguely familiar:

..  literalinclude::    code/hello.c
    :linenos:

You should be able to figure out what this program does. But
how do we get this running on our systems?

Before you answer that, we need to ask about the environment in which you
expect to run this program. Since it is written in a high level language, it
should run on just about any system. But, even so, we still need to figure out
what tools we need to be able to run this program.

Running the program
*******************

We will be using Linux (inside a ``virtual machine``) for our work (but the
program will run on Windows or Macs with suitable tools installed.

* This is a ``command line`` application
    * Not a ``GUI`` (graphical user interface) program

* we need some tools to even construct this program
    * we need an editor and a compiler to build the program

* Anything else?

Professional Programming tools
******************************

There are four basic tools needed by a professional programmer:

* A good programmer's editor

* A suitable compiler

* A source code control system


Almost all programmers use these tools, but many use then inside a tool called
an ``IDE`` (Integrated development environment). We will not use one of these!
My plan is to make sure you know how to program in any environment, not just
the one you might have been introduced to in a previous programming course. 


A good editor
*************

Stand by for a religious debate!

* I use ``vim``! (have for 40 years! Yikes!)
    * It is the best editor around (IMHO)
    * It is installed on almost every system except Windows
        * gVim_ is available to fix that!

* You should pick one you like and learn it well!
    * Use ``notepad`` at your own peril!
        * Real programmers will avoid working with you!

We need an editor to build our programs. But not just any editor. We want to
use one that understands what we are doing. A good programmer's editor can help
you write code that is properly formed and is presented in good style.

Believe it or not, but style matters - a lot! You are going to be judged by
your peers and your bosses on how well you program, and presenting your code in
an acceptable manner is very important to your career. I learned this early,
and it saved me a lot of heartaches!

I do not intent to ``force`` you to adopt the editor I use, but you should be
very selective in picking one for your own use.

        * It should be available on every platform you intend to use
        * It should understand the languages you will use
        * It should be scriptable
        * It should be free!

``vim`` satisfies all of these!

A suitable compiler
*******************

* We are going to learn assembly language, but we need help

* Input/output in assembly is hard
    * Input/output in C is easy
    * We will let C do this for us!

* A good compiler is available from The ``Free Software Foundation``
    * Specifically, we will use the Gnu_ C compiler
    * The Windows version of this is available with MinGW_
    * We will use versions of this compiler for all three processors we examine
      in this course!

A Source-Code-Control system
****************************

* Keeps track of changes to important files in a project

* Essential in a team development environment (not bad for single developers!)  

* Lets you ``roll back`` to previous versions if needed

* We will use Git_

Secondary goal of this course
*****************************

We are trying to teach you to be professional programmers, not just coders!

To do this you need to learn a few things:

* How to think your way through a programming assignment

* How to use the proper tools

* How to present your work in a professional manner

I am not doing this to be picky, I am doing this to prepare you for your career! 
I have been there, and I succeeded! I got to manage some incredible systems!


