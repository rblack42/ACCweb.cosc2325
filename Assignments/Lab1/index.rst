..  _lab1:

Lab1-4: Simple CPU Simulator
############################

..  include::   /references.inc

Here are the invitation links for this assignment:

    * `cosc2325-001 (HLC) <https://classroom.github.com/a/p0iYypYO>`_
    * `cosc2325-002 (SAC) <https://classroom.github.com/a/C9Ljhf9h>`_

..  note::

    This project repository will be used to several lab projects. For each lab,
    you will add a folder for a new component, and extend this project. You
    only need to accept this invitation once, on the next abs, just add code as
    needed.

Based on our overview of the Von Neumann Machine, and the dance steps the
processor takes to control the action inside the machine, we can build a
primitive simulator of a very simple computer.

..  note::

    As discussed in class, emulation involves producing the same results that
    the system being emulated produces. Simulation does the same thing, and
    works as close to the way the simulated system works as possible.

To get started with this project, we will build a simple memory class that will
be used to construct several memory units in our machine. Even though you might
be thinking that a memory object is just a simple array of bytes, it is not so
simple. Here is the header you will be using for this class:

..  literalinclude::    code/Memory/include/Memory.h
    :linenos:
    :caption: Memory Unit

Your Job
********

Look over the :ref:`diary-of-a-mad-black-programmer` for words of wisdom to
get started. You will be practicing the ``Test Driven Development`` scheme we
went over in class for all of your lab projects, so make sure you follow the
guidance on that part.

Once you are ready, begin to set up your project folder. Set up your project as
shown in the above lecture.

    * src - the human interface part of the simulator will live here

    * lib - the Memory class files live here

    * tests - all test code lives here

    * docs - make Guido happy!

You can start working on your project as soon as you like. We will discuss
managing this project in class this week.

The actual assignment for Lab1 is at :ref:`lab1-memory-unit`

Documenting your code
=====================

In the **docs** directory, place a single documentation file written using
|RST|_. (see :ref:`hw3` for information and a link to a quick guide, It is
pretty simple.)

These notes should briefly describe any design decisions you make to create
your code. You should also think about how you might test each class to verify
that it works properly. Identify test cases you might like to run by
identifying the parameters you would provide to any methods, and what you
expect each method to return as a result. This does not need to be extensive,
but we will be adding code to test things in our next lab.

..  vim:ft=rst spell:





