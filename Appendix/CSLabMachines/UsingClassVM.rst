..  _using-class-vm:

Starting the Class VM
#####################

..	include::	/references.inc

Before we launch of class :term:`VM`, we need to do a bit of system tuning.

Making File Extensions Visible
******************************

I do not know why we keep doing this in the CS Program, but by default, the
machines do not show extensions for files, you are expected to figure things
out from the file icon Microsoft decides to display in |WE|. Here is how to fix that issue:

With |WE| open, click on :menuselection:`Organize --> Folder and search
options`.

In the panel that comes up, click on the :menuselection:`View` tab, then
uncheck the box labeled :menuselection:`Hide extensions for known file types`.
You might also want to check the box labeled :menuselection:`Show hidden files,
folders, and drives`. We are computer people, and like to see what is really on
the system.  Click your way out of this box, and you are done.

Starting up the VM
******************

All Programs --> VMware --> VMware Player`. 

Once the program starts, you will see `cosc2425vm` listed in the left panel.
Click on this item and you will see details about that :term:`virtual machine`
show up on the right.

Normally, you just :kbd:`double-click` on the :term:`VM` name to start it up.
However, the first time you start it, you need to change a few settings.

Initial Setup
=============

At the bottom of the right panel, you will see an icon labeled
:menuselection:`Edit virtual machine settings`. Click on that to bring up a
panel where you can configure the machine (or reconfigure as needed).

Click on the :menuselection:`Options` tab, then on :menuselection:`Shared
Folders`. 

Check :menuselection:`Always eabled`, then click on :menuselection:`OK`. You
should be back at the :term:`VM` info panel.

Fire up the Program
===================

Click on :menuselection:`Play virtual machine` to start the program and your
:term:`virtual machine`.

..  warning::

    The first time a :term:`VM` is started, the system will ask if you moved or
    copied it. Click on :menuselection:`I copied it`.


Logging in
===========

You should see an entry for me, and a user named `student`. Obviously, you are
a student. Select that entry and enter the password given out in class 

Moving to your work directory
=============================

..  warning::

    Do not save any files in this image. The image will be used by all students
    taking COSC2425 and using this machine. See below for how to avoid that
    problem.

The lab machines are designed so any student can use them. That means we want
to make sure we leave no personal files in this :term:`VM` image. You will do
all of your work in a directory that is mapped to your "H" drive. That drive
follows you to any machine you use on any ACC campus.

..  note::

    You may see an icon on the left panel showing a black window with a ">" in
    it. This is the icon for the terminal program. If it is there,
    :kbd:`double-click` on it to start the program, if not, open up the
    :program:`Terminal` program by clicking on the `Dashboard` icon at the
    top-left of the screen. In the :menuselection:`Search box` that appears,
    type in "terminal", then press :kbd:`Enter`. The :program:`Terminal`
    program should start up. I recommend :kbd:`right-clicking` on the program
    icon on the left side of the screen, and selecting :menuselection:`Lock to
    Launcher`. That way the icon will remain on the left side of the screen,
    even when the program is not running.

The command to move to your shared directory is this:

..  code-block:: text

    $ cd /mnt/hgfs/COSC2425
    
This directory is mapped to your host machine and your "H" drive. Anything you
save here will be available on any machine you log into with the credentials
you got in the lab period. That means we can do all of the work for this class
in this directory, or in directories we create below this one, and all of that
will be available whenever you log into a class :term:`VM` at either HLC or RGC
this term. Just remember to switch to this directory immediately after logging
in.

I suggest that you create a directory for this class immediately. Name it
COSC2425. We will create subdirectories for each lab assignment below this
directory as they get assigned. We will set things up so that any work you do
in these directories will be saved on the class GitLab server, where I can view
them for grading. Hopefully that will all be up and running next week!

Shutting Down
*************

..  note::

    Once you get going with the GitLab server, you should never shut down until
    you are certain your work is safely on the server. You can check that with
    a web browser. 

When you are done working in the :term:`VM`, you should shut down the machine.
This can be done as easily as clicking on the red "close" button on the window.
Or you can use the menu system to find the :menuselection:`Power` control and
shut down that way. Make sure any open edit windows are closed before you do
this, it is just like pulling the plug on a real machine. Any open files will
be lost.

..  vim:filetype=rst spell:
