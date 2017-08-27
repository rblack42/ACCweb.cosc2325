..  _make:

Make - the programmer's best friend
###################################

After building a few programs by hand, you quickly long for the days when all
you had to do was push a button to build a project. Actually, when you pushed
that button in a typical :term:`IDE`, you were invoking one of the oldest and
most powerful tools used to construct real programs, ``make``.

What is Make?
*************

Simply stated, ``make`` is a program used to "make" programs. It is a tool
that issues a set of commands for you when you build a program involving
multiple steps, so you do not have to type those commands in manually.

If that was all ``make`` did, it might be handy, but hardly "powerful". What
makes ``make`` unique is that you describe how programs are constructed out
of the component parts, then ``make`` figures out what to do automatically.
How it does this is interesting.

..  toctree::
    :maxdepth: 1

    MakeIntro
    Makefiles
    AdvancedMake


