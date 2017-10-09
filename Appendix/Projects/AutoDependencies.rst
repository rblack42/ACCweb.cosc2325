Make Auto Dependencies
######################

Once you start working on bigger project, where files are in several
directories, creating the ``Makefile`` system gets more involved. The
goal of such a system is to avoid work. We want ``make`` to track how
files are related and properly build the project code whenever we make
any change to any file in the project. For big projects this is a tough
job t do right, but it is pretty important, so thinking it through is
worth the time invested.

In the example project Makefile system we presented earlier, we had one
glaring problem. We had to identify how header files were being used.
This is not something we want to worry about as we add files to the
project. Ideally, we should be able to just drop new files into the
appropriate directory, and everything will "just work". How do we deal
with header file dependencies?

A bit of searching turned up this reference:

    * `Auto-Dependency Generation <http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/>`_

This is just what we need, but it requires a bit more work on our project
setup.

First step
**********

A simple move toward a better setup is to move those dependency lines we
added earlier into a file we maintain just to list additional
dependencies. Let's try that and make sure it works.

At the end of the Makefile in all of our code subdirectories, we will
get rid of the dependency lines and add an include line:

:src/Makefile:

..  literalinclude:: code7/src/Makefile
    :linenos:

:lib/Makefile:

..  literalinclude:: code7/lib/Makefile
    :linenos:

:tests/Makefile:

..  literalinclude:: code7/tests/Makefile
    :linenos:



