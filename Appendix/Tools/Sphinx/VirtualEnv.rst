..  _installing-virtualenv:

Setting Up a Virtual Environment
################################

..  include::   /references.inc

If you work on a lot of Python projects, you will eventually run into a common
problem.

You have one version of some Python package installed on your system, but your
project needs a different version of that same package. If you install that new
version, you will break a different project! That is no fun!

The solution Python developers came up with some time back is to set up an
isolated Python environment where you install the exact packages you need for
the one project you are working on. You activate that environment when you want
to work on the project, and your system will use only tools in that isolated
environment. You can have several (many) such environments on your system. I
have automated setting this up so I can create a new environment very quickly
to work on a new project. 

..  warning::

    In this note, I will show how I set things up to do Python development on
    my Mac.The notes also apply if you use Linux. At the end of the note, I
    will show how to do the same thing on Windows.

Creating a Virtual Environment
******************************

If you use Python 2.7, you need to install a tool to create the virtualenv_.
That tool was developed by Ian Bicking, who was a huge contributor to Python,
but has moved on to work with other languages lately. No matter, he left us
with some nice development tools!

..  code-block:: text

    $ sudo pip install virtualenv

That `sudo` part is needed on Mac and Linux to install things in system
locations, normally controlled by the system administrator. If this is your own
personal machine, you are that administrator. On a PC, leave off the `sudo`
part and it should work fine.

Setting up a Project virtualenv
===============================

With the ``virtualenv`` tool installed on your system, you can create an
isolated work environment for a project by doing this:

..  code-block:: text

    $ mkdir myproject
    $ cd myproject
    $ virtualenv _venv

..  note::

    ``virtualenv`` creates a new directory will all the necessary Python tools
    needed in thta directory. I name all of my `virtualenv` directories
    ``_venv``, but you are free to change that if you like. Later I will show
    how I automate setting up a ``virtualenv`` and using it, based on this
    standard name.

What Happened?
==============

``virtualenv`` just created the directory named ``_venv`` in your project
directory, and copied a new Python interpreter program into that directory. It
also copied in the ``pip`` installer tool and standard Python libraries.
Everything needed to start work is in that directory. We need to tell our
system to use this new Python setup, and not the system-wide Python we
previously used.

Activating your virtualenv
==========================

I work at the :term:`command prompt` when I do Python development, so I open up
a new :term:`command prompt` window (also called a "shell") and do this:

..  code-block:: text

    $ cd myproject
    $ source _venv/bin/activate
    $ (_venv)

Notice that the prompt changes, adding the name of the ``virtualenv`` directory
to the line. This is  remind you that you are working in a ``virtualenv``.

This command runs a script that sets up this session (in just this shell) so it
will use the new Python environment. You can verify that you are using the
right Python by doing this:

..  code-block:: text

    $ (venv_) which python
    /Users/rblack/_acc/general/_venv/bin/python


I am currently working on the project I set up to manage these notes, and the
``_venv`` directory holds my ``virtualenv`` for that project. ``activate`` is a
script that does the setup work needed to make this all work. The
``virtualenv`` will be active until I deactivate it. I never do that, instead,
I just close the shell window and the system forgets this setup was being used!

Installing Packages in virtualenv
*********************************

To manage this Python project, we need to install packages from other
developers. The most common tool for this work is Pip_. Notes on using this
tool are available at :ref:`installing-pip`. We will focus on how to use
``pip`` in our ``virtualenv``.

Install a Package
=================

First, verify that you are using the right version of ``pip``:

..  code-block:: text

    $ (_venv) which pip
    /Users/rblack/_acc/general/_venv/bin/pip

Now, install a package:

..  code-block:: text

    $ (_venv) pip install sphinx

``pip`` will install this package, and other packages needed by Sphinx_ into
the virtualenv directory (not your system Python directory!)

After this completes, we can see what packages are currently installed in your ``virtualenv`` by doing this:

..  code-block:: text

    $ (_venv) pip freeze
    alabaster==0.7.6
    Babel==2.0
    docutils==0.12
    Jinja2==2.8
    MarkupSafe==0.23
    Pygments==2.0.2
    pytz==2015.4
    six==1.9.0
    snowballstemmer==1.2.0
    Sphinx==1.3.1
    sphinx-rtd-theme==0.1.8
    wheel==0.24.0

Phew, that is a lot of stuff! All of those other packages were needed by Sphinx_. 

Notice the version numbers after each entry. As these tools evolve, the numbers
will change. Those changes might break your project, so you either have to
update your code, or make sure users use the version of these tools you used in
your development. We can control that by adding a ``requirements.txt`` file.

Creating a Requirements File
============================

It is a common practice to list all major packages you need for users to
install if they want to try out your project. In this example, we are just
adding Sphinx_ to our project, so the requirements file looks like this:

..  code-block:: text

    Sphinx==1.3.1

You simple list the package name, ``Sphinx`` in this case, followed by the
version number you need, ``1.3.1`` in this case. You can leave this off, and
``pip`` will install the latest available version of that package You can also
use something like ``>=`` to get any version after the specified number.

Add as many other package names as your project needs, then do this:

..  code-block:: text

    $ (_venv) pip install -r requirements.txt

``pip`` will make sure all the packages in the file are installed, together
with any others needed so all of them will work. You can run this command as
many times as you like, it will only make sure things are installed, never
damaging your setup. 

Destroying your ``virtualenv``
==============================

You can wipe out this entire ``virtualenv`` by deleting the directory you created. 

..  code-block:: text

    $ rm -rf _venv

..  warning::

    It is probably not a good idea to try this while working in an activated ``virtualenv``!

Automating things
*****************

On my Mac and Linux systems, I add an ``alias`` to my system to make running
these commands easier. These lines are in my ``.bash_aliases`` file:

..  code-block:: text

    alias workon='source _venv/bin/activate
    alias mkvenv='virtualenv _venv:workon'

With these aliases in place, I can create a new ``virtualenv`` by doing this:

..  code-block:: text

    $ cd myproject
    $ mkvenv
    $ workon
    $ (_venv)

And the project is ready to go and active.

After that, I just do this:

..  code-block:: text

    $ cd myproject
    $ workon
    $ (_venv)

Working on a PC
***************

Getting this all working on a PC is not quite as simple, but still a good way to work.

Installing virtualenv
=====================


..  vim:filetype=rst spell:


