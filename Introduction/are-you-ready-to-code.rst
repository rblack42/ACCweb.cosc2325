Are You Ready to Code?
######################

..  include::   /references.inc

..  _`ACM-ICPC`:    https://icpc.baylor.edu/


By now, you have had a few programming courses. For a few of you, you have
been writing programs for quite a while. My question is simple: are you ready
to code?

Silly question! Of course you are ready to code!

But are you really?

How Do You Code Now?
********************

The answer for many of you is also simple: "In my favorite IDE, which runs on
Windows."

Sorry! You are not ready to code.

What Is Wrong With My IDE?
**************************

Nothing really, if you expect to spend a lot of time working in that
environment. The problem is that you may have picked the wrong IDE. When you
get your first real job, you will discover what the right IDE is (for your
employer). You will need to drop what you love now, and learn to love a new
tool. You will also have to learn other new tools and procedures that dictate
how you will write code for that employer. 

Oh yeah! You will also learn that your code is going to be scrutinized by your
programming peers. You will face something called the "Peer-Review" where your
code is basically shredded by others, and you get to defend every line you
wrote (Shudder!)

Where Can You Code?
*******************

An even bigger problem lurks out there, ready to bite you! You may not end up
working exclusively on a Windows machine. You might have to work on a Mac, or
on a system running Unix/Linux. Are you ready for that?

A Real Example
**************

In my email the other day, I got a summary of the results from the `ACM-ICPC`_
(*International Collegiate Programming Contest*) World Finals, a major
competition to see who has the best programmers in the world. (Hint, the
top-placing US team came in 13th, not a good sign!)

Here is where you would be programming in this competition:


    * Hardware:
    
        * Intel i7 NUC (Model NUC5i7RYHR )
            * CPU - 5th Generation Intel Core i7-5557U (3.1+ GHz)
            * RAM - 16 GB
            * Disk - 128 GB SSD
            * Graphics - Intel Iris Graphics 6100
        * External screen: Lenovo ThinkVision L2321x LCD Monitor Model 4014-HB6 (23in wide, 1920x1080 Native Resolution) 
        * External keyboard: Lenovo 41A5100, sub-model KU-0225, USB 
        * External mouse: Lenovo 41U3013, USB

    * Software:
        * OS:
            * Ubuntu 16.04.1 LTS Linux (64-bit)
        * Desktop:
            * GNOME
        * Editors
            * vi/vim
            * gvim
            * emacs
            * gedit
            * geany
        * Languages:
            * Java
                * OpenJDK version 1.8.0_91
                * OpenJDK Runtime Environment (build 1.8.0_91-8u91-b14-3ubuntu1~16.04.1-b14)
                * OpenJDK 64-Bit Server VM (build 25.91-b14, mixed mode)
            * C
                * gcc (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609
            * C++
                * g++ (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609
            * Python 2
                * Python 2.7.10 (implemented using PyPy 5.1.2). A list of the installed modules can be found here
            * Python 3
                * CPython 3.5.2.  A list of the installed modules can be found here
        * IDEs:
            * Java - Eclipse 4.6 (Neon)
            * C/C++ - CDT 9.0.1 under Eclipse 4.6
            * Python
                * PyDev 5.1.2 under Eclipse 4.6
                * Pycharm Community Edition 2016.2.3

The problems teams faced in this years competition are interesting. Here is
this year's problem set:

    * :download:`/files/icpc2017.pdf`

If you were lucky enough to reach this competition, you walked into a room with
nothing but your warm body, and faced the specified working environment. The
competition is timed, and teams work through the problems and submit their code
for testing. Points are awarded for the entries that actually work! 

Since this competition is pretty fast paced, I do not see that they considered
program style in their scoring. I certainly would have required a look at that,
perhaps as a last step when awarding points. 

Secondary Goal of this Course
*****************************

This brings me to the secondary goal of this course. I want to turn you into
professional programmers. Well, actually, I want to start you on the path to
becoming one. To do that, we are going to have to un-learn a few bad habits,
and learn some new good-habits. We will also need to learn some new tools, and
we will learn to work in a new environment. 

Specifically, here are the tools you will be using in this class (note: no IDEs
allowed!):

    * Hardware:

        * Hopefully your personal 64-bit laptop, or a school lab machine
    
    * Software:

        * Virtual Machine: VMware or VirtualBox

        * OS: Ubuntu linux
        
        * Languages:
            * GNU C/C++
            * Assembly language (several)

        * Editor: Vim_ (or one of its variants)
        * Source Code Control System: Git_ and Github_
        * Build tool: GNU Make_
        * Documentation system: Python Sphinx_ or LaTeX_

DON'T PANIC!
************

I do not expect you to become wizards in all of this, for most of you, you have
never heard of many of these items. We will introduce each one slowly, and get
you working with them as quickly as we can. I do recommend that you construct
"cheat-sheets" to help you learn how each tool is used. 

All of these tools have been in use in this course for many years. A few
students have trouble with some of them, but I am here to help you through
that. I have had quite a few old students contact me years later, thanking me
for pushing them in this direction. Once they got into "real jobs" they
discovered that being a professional programmer is not as easy as they thought
it would be! Having a good start is important, and *NOW* is the time to get
that start!

Meet Guido
**********

Although it is not politically correct, I like to introduce a character in my
courses. His name is Guido, thanks to my growing up watching old Mafia TV
shows. With apologies to every Guido out there, this Guido has to maintain your
code, and he has a very short fuse! He is not someone you want to cross! If you
write code that Guido is going to have a hard time maintaining, he will hunt
you down! You do NOT want that to happen, so think about Guido as you craft
your code. 

Guido know his stuff, and he expects you to write nice, clean, well documented
(and maintainable) code that *works*. Nothing else will do!

What is a Working Program Worth?
********************************

If you write a program that solves a problem I pose in this class, and it
works, it is worth a "C". 

What? Why is that?

I expect your code to work. That is what I expect from all programmers I have
ever worked with, or who worked for me. You have to do better than that to get
that "A" you thought you should get.

To get the "A", your code has to be neat (follow accepted style guidelines),
clear (good choices in names you choose), it has to compile and run error free
(even warnings are a bad thing). It has to be documented (not just with
embedded comments). It has to be tested (one sample run is not enough).

Oh! And Guido has to like what you wrote!

You will not get to this point without putting in some effort. I will get
progressively more picky about all of this as the course progresses. For now,
just think about how you currently work, and what habits you might need to
break.

Why?
****

There is a point to all of this picky stuff. I want you to enjoy what you do,
and end up working in a job where you are contributing in a real way to the
development of something cool. 

You will not get to that place by being sloppy at what you do. That "A" you are
convinced is essential to getting you that job will do no such thing. It may
get you standing in front of a potential employer, but the "A" will get you no
further. It is what you can demonstrate that you *know* and *can do* that will
get you that job. Most employers will run you through a testing process to
prove you can do the job. (I once faced a grueling six hour interview with a
team of folks who wanted to make sure I could run the entire IT department for
a major city. I aced that test because I practice what I preach!)

Programming can and should be enjoyable, and you should be proud of what you
can do! Otherwise, you are headed in the wrong direction.

You will spend an enormous amount of your life working at something. You better
enjoy that! In my over 50 years of working, I have not had one job I would not
gladly go back to and work there again. Maybe I was lucky, but I believe that
having the right attitude, and intentionally developing your skills will get
you a career like that as well.

..  vim:ft=rst spell:
