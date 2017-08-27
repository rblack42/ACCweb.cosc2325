..  _starting-a-project:

Starting a Project
##################

..  include::   /references.inc

Always begin any project by creating a single directory (folder) under
which everything about the project and nothing else will be stored.
Place a ``README`` file in that folder with a brief description of the
project.

..  note::

    I will show command line sessions where I set up an example project.
    If you are working on one of the lab projects for this course, this
    structure is already in place and you will see it when you clone the lab
    repositories for future labs.

..  code-block:: bash

    $ mkdir cpp_template
    $ cd cpp_template
    $ vim README.rst

..  note::

    I always use reStructuredText_ to write my documentation, so my README
    file ends in ``.rst`` and GitHub_ will format it for me on their server.

Connect to GitHub
*****************

Any project worth investing time in should end up under Git_ control.
You do not have to host it on GitHub_ if it is a private project, but
gaining experience building projects that are :term:`open-source` is a
good resume builder.

..  note::

    This next step is not necessary if you clone a lab project repository. If
    you are starting a new project on your own, follow these steps:

Log onto GitHub_, and create a new repository with this project name. I
am going to assume the project is named ``cpp_template`` on  that
system. Once that repo is there, back on your workstation, do this:

..  code-block:: bash

    $ git init
    $ got add .
    $ git commit -m "initial commit"
    $ git remote add origin https://github.com/rblack42/cpp_template.git
    $ git push -u origin master

..  warning::

    Use your own GitHub_ user name n the remote command, and you never
    use that ``-u`` option on a "push" command except the very first time
    you push your new project to GitHub_. If you cloned an existing
    repository, do not use the ``-u`` option at all.

With this step complete, you have a project directory ready to do
development work!

Create Directories
******************

The top level project directory never holds program code. Instead, it is
the management layer and we organize that level by building a few
standard subdirectories:

    * ``src`` - All code files (except header files) live in this directory.

    *  ``incude`` - all header files will end up here.

    * ``docs`` - project documentation is here

    * ``tests`` - Real programmers test their code!

    * ``lib`` - compiled object files collected into library files go here.

Now that we know where to put things, it it time to figure out how we
will build (and test) this project. We need to look at the ``make``
system for more help with that.

..  vim:filetype=rst spell:
