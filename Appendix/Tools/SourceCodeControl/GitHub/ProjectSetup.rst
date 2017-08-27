Structuring Your Project
########################

..  include::   /references.inc

A Git_ :term:`repository` is just a single directory that holds all of your
project's important assets. Those assets should include only those things
needed to build the final project products, usually (but not always) a runnable
program of some kind. It should not include things like executable files,
object files, or editor temp file. Those files can be regenerated from what you
do track in your :term:`repo`. 

What changes a simple directory into a :term:`repository` is the presence of
the hidden ``.git`` directory. This subdirectory holds everything needed by
Git_ to trick the history of your project. You hould never modify things in
this subdirectory yourself, let Git_ do that.

..  note::

    If you want to turn your :term:`repository` back into a simple directory,
    just delete the ``.git`` subdirectory! You might do this if you want to
    delete the history of an old project for some reason.

Project README File
*******************

You should always place a `README` file at the top level of your project
directory. Folks looking at your project will check this file to see what the
project is all about.

Since I use reStructuredText_ markup in this file, I name mine ``README.rst``.
GitHub_ will automatically format this file using the right tools, and display
it on your project's main page (at the bottom, after the list of files in the
project).

..  note::

    Currently, GitHub_ will format pages written using reStructuredText_ or
    Markdown_.

Here is an example of a ``README`` file you might use:

..  literalinclude:: code/README.txt
    :linenos:

..  note::

    GitHub_ will display the unformatted text of this file by clicking on the
    file name in your project directory and selecting the "Raw" menu item at
    the top of the page you see. You can use this trick to examine all of the
    notes on my GitHub_ pages, since I keep my lecture notes on my GitHub_
    account.

License File
************

If your project is open to other developers or users, you should include a
```LICENSE`` file at the top level as well. There are several commonly used
licenses you can include. Currently, I use the `BSD 3-Clause`` license. Here is
the ``LICENSE.rst`` file I usually place in my projects:

..  literalinclude::    code/LICENSE.txt
    :linenos:

Top Level Directories
*********************

The top level of your project directory should contain at least three other
subdirectories:

..  code-block:: text

    projectname/ 
        | 
        +- docs/ 
        | 
        +- src/ 
        |   | 
        |   +- Makefile 
        |   | 
        |   +- project source code ..
        |
        +- tests/

Obviously, your real project code goes in the ``src`` directory, which is
sometimes named something similar to the project name, especially if you are
building a Python application.

The ``docs`` directory should hold your primary project documentation. In my
projects, this is a complete Sphinx_ setup that can produce pages suitable for
posting to a web server, or for producing PDF files, or even ePub files that
can be viewed by tablets of smart-phones. There is usually a Makefile in this
directory that builds my documentation, and even uploads it to my public web
server.

The ``tests`` directory commonly holds test files that exercise the actual
project code. Some developers do not provide the test code, but more and more,
this code is used by folks to make sure your project works properly when they
install it on their systems. A well designed project is fully tested, and you
want to know if others have problems using your code so you can address that
issue!

..  note::

    People use mobile devices all the time to explore the Internet. You never
    know if someone is searching for a project to help them with something, and
    may find your project on one of these things! I am working on making all of
    my documentation and lecture materials "mobile friendly".

Study Other Projects
********************

Since you are probably using GitHub_ to host your projects, look around and see
how others lay out their projects. There are not hard and fast rules here, just
"best practices". You should strive to make your project as "clean" as
possible, since it is on public display!

    vim:filetype=rst spell:

