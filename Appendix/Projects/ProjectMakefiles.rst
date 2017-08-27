Project Makefile
################

We want to build a project far more complicated than a simple one you
might have constructed in earlier classes. We will use ``make`` to
manage this project. We have a few new things to learn about ``make`` to
pull this off.

SubProject Directories
**********************

..  include::   /references.inc

First, you need to understand that most projects are not simple things
involving one or two files. They may involve many components scattered
in files and directories in a way that is logical to the project
designers. We need to show how to set up a very simple example of such a
layout, and this lecture will go over that.

First, the top level directory will never have any program code in it.
Instead, it is a wrapper for several other directories that will hold
things needed to build this project properly.

For now, let's start off with a simple setup that has a project
directory named something logical like ``ExampleProject``. We will put
other files in this directory later. For now, create a single
subdirectory named ``src`` in this top level directory. This is where
the main part of the application will live.

..  code-block:: bash

    $ cd cpp_template
    $ mkdir src

Now, create a ``Makefile`` in the top level directory that looks like
this:

:Makefile:

..  literalinclude:: code1/Makefile
    :linenos:

This makefile does nothing by itself to build the project. What it does
is launch another ``Makefile`` in the ``src`` subdirectory that
eventually will build the project.

:src/Makefile:

..  literalinclude::    code1/src/Makefile
    :linenos:

Obviously, we are not building anything yet.

..  note::

    The *echo* command is handy when you want to see exactly what
    ``make`` has created when you build a list of file names. You can debug
    a Makefile using thiese statements


In your top-level directory, do this:

..  code-block:: text

    $ make
    for dir in src; do  \
			(/Applications/Xcode.app/Contents/Developer/usr/bin/make -C $dir all); \
		done
    echo "building primary app"
    building primary app

The top level ``Makefile`` simply ran a second-level ``Makefile`` as
directed. In that second level file, we will actually build the project
program. 

Building the Program
********************

In the finest tradition in programming, let's build "Hello, World" in
this subdirectory.

:src/main.cpp:

..  literalinclude::    code2/src/main.cpp
    :linenos:

We need to modify the top level ``Makefile`` so we can build the
program, and run it:

:Makefile:

..  literalinclude::    code2/Makefile

And the ``src/Makefile`` needed to build (and run) it:

..  literalinclude::    code2/src/Makefile
    :linenos:

Running from the top level, we see this:

..  code-block:: bash

    $ make run
    /Applications/Xcode.app/Contents/Developer/usr/bin/make -C src run
    ./example
    Example Project

You should verify that the ``clean`` command also works as expected.

..  code-block:: bash

    $ make clean
    $ ls -l src

This should show both the program and the object files hve been deleted.

This is a good start. We have a simple program being compiled, linked,
and then run. But we are not done yet


Sub-Projects
************

Now that we are building a program involving more than one file, we can
explore another common setup in our project: libraries.

A big program will obviously have a ``main`` function that calls other
functions somewhere in your code. It is common to organize all of those
other functions into a set of files that focus on one majot part of the
code. We my have several files in one major component, so we might set
up a subdirectory just for that part of the project.

For this class, we do not need a bunch of directories to manage things,
one will do. Let's call it ``lib``:

..  code-block:: bash

    $ mkdir lib

In this directory, place a simple source file named ``factorial.cpp``:

:lib/factorial.cpp:

..  literalinclude::    code3/lib/factorial.cpp
    :linenos:

We need another ``Makefile`` in the ``lib`` directory to manage building
this library:

:lib/Makefile:

..  literalinclude::    code3/lib/Makefile

The key tool needed to build a libaray is the "archive" program named
``ar`` on Linux/Mac. WIndow does thing differently, and we will not
cover that here.

A "library" is just a single file containing one or more object files.
The name of this library is "demolib" but the actual file name is that
name with "lib" in front of t, and ".a" at the end: ``libdemolib.a``. We
will need to reference the basic name in later commands, so the base
name is defined in this ``Makefile``.

Linking
=======

Now that some parts of our final program are inside a library file, we
need to tell the linker to search that library for any missing function
references. Here is the new ``Makefile`` we need to do that:

:src/Makefile:

..  literalinclude::    code3/src/Makefile
    :linenos:

We only added  few lines to identify the directory to search for the
library, and the nase name of the library needed.

Here is a new ``main.cpp`` that calls this new function:

:src/main.cpp:

..  literalinclude::    code3/src/main.cpp
    :linenos:

Running the top level ``make`` command now produced this:

..  code-block:: bash

    make
    g++ -c main.cpp -o main.o
    g++ -o example main.o -L ../lib -ldemolib

So far, so good. We compiled the modified ``main.cpp`` and linked in the
library file. But, we still have a problem that may not be obvious.

Dependencies
************

Make operates by being told how files in your project relate t each
other. On any "target" line, we list the files neeed to build that
target. For instance, we need a ``.cpp`` file to build a ``.o`` file, we
need ``.o`` files to build the final program.

But, how is ``make`` going to figure out that if we modify the library
file, we need to recompile our ``mian`` file and relink to build the now
updated executable?

Clearly we need to change something here, and that something involves
header files!

Header Files
============

A header file is essentially a contract between two parts of yur
program. IN our example, we need a contract between ``main.cpp`` which
is going to call ``factorial`` and ``factorial.cpp`` which is going to
provide that functions. To make matters worse, these files are in
different directories.

The solution is to create a new file ``factorial.h`` that contains the
*prototype* specification for that ``factorial`` function, and "include"
that header in both ``main.cpp`` and ``factorial.cpp``. That way the
compiler will verify that both program files are written properly and
they will link together just fine!

To set this up, we need another directory, and we need to tewak our
``Makefiles`` in both ``src`` and ``lib``:

..  code-block::    bash

    $ mkdir include

Next create this file:

:include/factorial.h:

..  literalinclude::    code4/include/factorial.h
    :linenos:

We need to include this file in both ``main.cpp`` and ``factorial.cpp``:

:src/main.cpp:

..  literalinclude::   code4/src/main.cpp
    :linenos:

:lib/factorial.cpp:

..  literalinclude::   code4/lib/factorial.cpp
    :linenos:

We also need to modify all the ``Makefiles``:

:Makefile:

..  literalinclude::   code4/Makefile
    :linenos:

:src/Makefile:

..  literalinclude::   code4/src/Makefile
    :linenos:

:lib/Makefile:

..  literalinclude::   code4/lib/Makefile
    :linenos:

There is one critical point in this change. In the top level
``Makefile`` I needed to list the directories in the order shown so
``make`` would build the library before trying to build the program. This
is not the right way to do things, ``make`` should figure that out
itself. Correcting this involves teaching make how or files interrelate
better. We have actually added a new dependency: the include file. Here
is one (old-fashioned) way to do this. We change the ``Makefiles`` in
``src`` and ``lib``

:src/Makefile:

..  literalinclude::    code5/src/Makefile
    :linenos:

:lib/Makefile:

..  literalinclude::    code5/lib/Makefile
    :linenos:

Note that in both of these files, we added the include dependency at the
bottom of the ``Makefile``. That is essential to make sure ``make``
still builds things correctly.

Testing Code
************

There is one big missing element in our project at this point: testing!
While I was testing this code in this lecture, I ran into this:

..  code-block:: bash

    $ make run
    ./example
    Example Project
	    the factorial of 3 is 1

Tilt! That is not right! What happened and how do we fix this. 

You will not see this, but I had failed to do the factorial right when I
first entered (How did that happen?) 

In this simple program, there is not much to test, but we do have one
component worthy of testing. That ``factorial`` function should be
exercised to make sure it is working properly before we allow the rest
of the program to use it!

..  note::

    We cannot really test the entire program easily, since that may
    involve human interaction. (That is called "functional testing" and we
    will not explore that here.)

We can test components of our code. That is called "unit testing" and
there is a simple way to do that in C++ projects.

Catch
=====

The Catch_ project has produced a single header file named ``catch.hpp``
you can download from their site and add in your ``include`` file. Then,
we set up a new top-level directory called ``tests`` and set it up to
test our "units".

..  note::

    I will not show that file here, it is huge! You can find a copy on
    my GitHub_ account, or look for it on the Catch_ project website.

..  code-block:: bash

    $ mkdir tests

We need to modify the ``Make`` system to deal with testing now, so here
are the new files:

:tests/test_runner.cpp:

..  literalinclude::    code6/tests/test_runner.cpp
    :linenos:

This is just a file that Catch_ will prepare to run all tests you need
to run. Our ``Makefile`` in this directory will create a single program
called ``test_runner`` that will do the testing. All we need to do is
add another file that actually does the work!

:tests/test_factorial.cpp:

..  literalinclude::    code6/tests/test_factorial.cpp
    :linenos:

The test code is pretty simple. If we hand the ``factorial`` sone
parameter, we expect it to produce some known result. The test is just a
logical expression that should return "true" if the test passes, and
"false" if it does not! Simple! Any function you write can probably be
tested doing something similar!

Here is the ``Makefile`` needed to build the test program:

:tests/Makefile:

..  literalinclude::    code6/tests/Makefile
    :linenos:

We add another directory to our list of directories in the top-level
Makefile:

:Makefile:

..  literalinclude::    code6/Makefile
    :linenos:

Now, we can do this:

..  code-block:: bash

    $ make test

Sanity Check
************

As a last step in setting this admittedly  complex project setup, let's
do an acid test to make sure everything runs as extected:

..  code-block:: text

    $ make clean
    for dir in lib src tests; do  \
    			(/Applications/Xcode.app/Contents/Developer/usr/bin/make -C $dir clean); \
    		done
    rm -f factorial.o libdemolib.a
    rm -f example main.o
    rm -f test_runner test_factorial.o test_runner.o

    $ make
    for dir in lib src tests; do  \
    			(/Applications/Xcode.app/Contents/Developer/usr/bin/make -C $dir all); \
    		done
    g++ -c -I ../include factorial.cpp -o factorial.o
    ar -rcs libdemolib.a factorial.o
    g++ -c -I ../include main.cpp -o main.o
    g++ -o example main.o -L ../lib -ldemolib
    g++ -c -I ../include test_factorial.cpp -o test_factorial.o
    g++ -c -I ../include test_runner.cpp -o test_runner.o
    g++ -o test_runner test_factorial.o test_runner.o -L ../lib -ldemolib

    $ make run
    /Applications/Xcode.app/Contents/Developer/usr/bin/make -C src run
    ./example
    Example Project
    	 the factorial of 3 is 6
 
    $ make test
    /Applications/Xcode.app/Contents/Developer/usr/bin/make -C tests run
    ./test_runner
    ===============================================================================
    All tests passed (4 assertions in 1 test case)

Looks like we have something we can work with

Closing Notes
*************

There is one remaining ugliness in this ``Makefile `` system. We had to
explicitly list the header dependencies, which means that adding new
files to our project will require updating the ``Makefiles``. We would
like to avoid that, but doing so is a bit more complex (really? This was
complex enough!)

Well, I tried to present this to you "Baby Step" fashion, so you could
see how it all comes together. Each step was fairly simple, and ``Make``
rules are not so bad once you practice with them.

But dealing with the dependencies is something we need help with, and
the tool to use is the compiler. We will cover that in a future note.

..  vim:filetype=rst spell:

