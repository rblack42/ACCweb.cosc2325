..  _advanced-makefiles:

Advanced Makefile
#################

..  include::   /references.inc

I use Make_ to build many programs from the command line. There are more
advanced tools around, but I feel that beginning programming students need to
be exposed to Make_ so they can see how powerful such build tools are, and be
able to use them in their programming projects. Make_ has been around so long,
and it is part of so many projects, you just have to learn a bit about it.

I usually start students off in exploring Make_ with very simple patterns, but
eventually they need to see the real power of such a tool.

So, in developing a Graphics library for students to use in my programming
class, I decided to add a few more powerful features of Make_ to the project
``Makefile``.

In this note, I will develop a Makefile suitable to use in a :term:`test driven
development` based C++ project. As part of this development, we will design a
project directory structure suitable for building a library, intended to be
used in other C++ projects. The ``Makefile`` will build, test, and install that
library code on all major development systems: Windows, Linux, and Mac.

Project Layout
**************

The first thing you need to do when starting a project, is decide on a
directory layout. Some directories you will need are obvious, like ``docs``and
``src``, but it gets complicated right away. 

I reserve ``src`` for the "human interface" part of a program. That is where
the ``main.cpp`` file will live. I also put any code that supports the user
interface in here, since that code is probably unique to the project, and not
usable in other projects.

On the other hand, some project components might be candidates for use in other
projects. For that reason, I build them as part of a ``library`` of code
components that can be linked into other projects. All programming tools support
the idea of merging compiled files into a single file what the linker can
search as needed for a particular project.

In my project folder, I create a ``libe`` directory that will hold these
program components. I might further subdivide this folder if there are several
major components in my program, each of which deserve to be treated
individually.

If we are building a multi-file project, and we certainly are most of the time,
the header files are an important part of our code. Those header files
represent a contract between the creator of a module and the user of a module.
The user has no real reason to see the implementation of a module, and probably
should not see it anyway. We do not want then using knowledge of how the module
works to create their program, that would ``couple`` the code too tightly to
the module, which we might change later.

I place all header files in a separate place, not with the modules. These files
will be read by both users and creators, and are important enough to place in
their own place. The ``include`` directory holds these files.

Finally, I need a place to store all tests I will write. I do not lie littering
my source code directories with anything not related to the code, and test are
not part of the code, they stand alongside the code and are used (potentially by
other folks) to test the code. Tests belong in a separate directory named
something obvious like ``testts``!

That gives us a basic structure to work with.

Since our first major project will be to write a simulator for a simple
machine, lets set up the directory structure like so. 

..  note:: 

    These commands all work on Linux/Mac. They show the power of the simple
    ``mkdir`` command on these systems. Remember that you will have the top
    level folder for this project set up when you clone the project repo from
    GitHub.

If needed, create the top-level project folder first:

..  code-block:: bash

    $ mkdir CPUsim
    $ cd CPUsim

..  note::

    For lab projects this will be the assignment repo directory, not CPUsim.
    
Next create the required folders.

..  code-block:: bash

    mkdir -p {docs,src,iinclude,tests,lib/{memory,alu,controller,io}}

Wow! That saves a lot of work. The one command created the whole project
structure. You can see the layout using the 11tree`` command:

..  code-block:: bash

    $ tree
    .
    ├── docs
    ├── include
    ├── lib
    │   ├── alu
    │   ├── controller
    │   ├── io
    │   └── memory
    ├── src
    └── tests

Wow! That sure saves a lot of typing! One command set up my whole project.
Pretty cool!

Writing a Project Makefile
**************************

We are now ready to set up the ``Makefile`` for this project. 

..  warning:: 

    What I am going to show here is not the true professional way to set this
    up, but it is reasonably easy to figure out, and works for moderate
    projects. When you get to projects with hundreds of files, other schemes
    work better!

What We Want to Build
=====================

The point of any build system is to build stuff. What stuff? Well in the
``srcss folder, we have the basic makings of a application we want to build.
That is the primary product of our work. However, we cannot build that program
until we built the library of components in ``lib``. SO, we have to build that
library (or libraries) first. Then we can build our application and link in the
library components.

The tests in ``tests`` also need the library files to exit before we ca build
the test application. (Using ``catch.hpp``, we will end up with one program
that tests all the components in the library. For this example, we will not
test the main application code, but you could do that if needed.

Let's set up a single folder to hold everything we build from our source code.
That will make cleaning up the project directory easy, we just delete the build
directory. You do not want to put any file that can be constructed from source
files in the repository. 

Finding Source Files 
====================

A simple ``Makefile`` begins with a list of the source files needed to compile
the project code. In our project there are going to be source files in several
directories,. Here is one way to get a list of everything we need.

..  code-block:: text

    SRCSRCS = $(wildcard src/*.cpp)
    MEMSRCS = $(wildcard lib/memory/*.cpp)
    ALUSRCS = $(wildcard lib/alu/*.cpp)
    IOSRCS  = $(wildcard lib/io/*.cpp)
    CTLSRCS = $(wildcard lib/controller/*.cpp)
    TSTSRCS = $(wildcard tests/*.cpp)

All of these lines use a pattern designed to locate only the files ending in
``.cpp`` in each directory. I created one line for each directory containing
code. 

Create a List of Object Files
*****************************

We will want to compile each file in the lists above, and create an object file
from that. Later, we will link in the object files to create our final
program(s) (We will build the application, and a test program in this example).

Here is how we get a list of object file names. Each file is simply the same
name as the source file, but we change the extension from ``.cpp`` to ``.o``.
This will do that:

..  code-block:: bash

    SRCOBJS = $(SRCSRCS:.cpp=.o)
    MEMOBJS = $(MEMSRCS:.cpp=.o)
    IOOBJS = $(IOSRCS:.cpp=.o)
    ALUOBJS = $(ALUSRCS:.cpp-.o)
    CTLOBJS = $(CTLSRCS:.cpp=.o)
    TSTOBJS = $(TSTSRCS:.cpp=.o)

This seems like a lot of work, but you can add new files without changing the
``Makefile`` in any way. In fact, this ``Makefile`` can work in other projects
with few changes.


Next, we name the major directories we use in this project. Creating names
makes it easy to modify this file for another project later:

..  literalinclude::    code/casm/Makefile
    :lines: 6-10

In the next section, we set up a few names that will hold options we use on
various commands later. Notice that "+=" operator. You can add things to a name
in a later step using this trick.

..  literalinclude::    code/casm/Makefile
    :lines: 12-14

This next section tries to deal with building the application on different
operating systems. This code will check the operating system and set a few
names differently depending on what system we are running on. The big
difference here is that programs on Windows need to be named ``something.exe`,
but on Mac/Linux, they are just named ``something``. We set up a name called
``EXT`` and set it to ``.exe`` on windows, and nothing on other systems. You
will see this at work later.

..  literalinclude::    code/casm/Makefile
    :lines: 16-34

Now, we can have Make_ search the project directories for any source files that
will need to be processed:

..  literalinclude::    code/casm/Makefile
    :lines: 36-44

In this section we have set up something that makes projects easier to manage.
The ``g++`` compiler can be told to read all the source files and figure out
what each one depends on. It does this by looking at the ``include`` lines. The
output of this step is a file called ``something.d`` (for depends). We will use
these files to make sure Make can build your code in the most efficient manner. 

The last part of the Makefile sets up the rules needed to build all the project
components. These rules are similar to those we went over earlier, and should be
easy enough to figure out. Exactly what options are used for each build tool is
something we can worry about later for this example.  

..  literalinclude:: code/casm/Makefile 
    :lines: 46-87

Learning More
*************

This gives you a sense of what Make can do. You can learn a lot by scanning
projects on Github_  and looking to see how they use Makefiles to build their
programs. 
