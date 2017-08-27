..  _shell-basics:

Linux Shell Basics
##################

If you have never worked on a :term:`command line`, you need a quick overview of
the basic commands you need to be able to use to get your work done. This quick
guide will get you started, and a better overview can be found here:

    * `Learning the Shell <http://linuxcommand.org/lc3_learning_the_shell.php>`_ 

The Prompt
**********

When you first open up a Terminal program, you are presented with a basic black
screen with white test. You see a line that looks something like this:

..  code-block:: text

    rblack@ubuntu:~$

That last character, "$", is the actual prompt. You will type in a command
after that character as you work. 

The first part of the line identifies the user ("rblack") and the machine name
("ubuntu") to help you figure out what machine you are working on at the
moment. Trust me, as you start working with servers on the Internet, it is easy
to lose track of what machine you are working on! 

I have a problem with this setup, especially in a classroom where I project the
screen. Seeing the text on that black background is difficult. You can change
the screen by doing this:

..  code-block:: text

    $ setterm -term linux -back white -fore black -clear

You can use other colors for the foreground and background colors:

    * black
    * blue
    * green
    * cyan
    * red
    * magenta
    * yellow
    * white
    * default

..  warning::

    If you change the colors using this command, be sure to modify your prompt
    so it displays with the same colors. There are additional command strings
    that do this (but you need to look them up for now).  
    
Navigation
**********

The first thing you need to be able to do is move around in your file system,
and understand what the current "working directory" you are in. Hopefully, you
already have a mental model of how your file system (disk drive) is organized.

The System Path
===============

Files are stored on your hard disk(s), we all know that. We use directories (or
folders as Microsoft want us to call them) to group files that logically belong
together for some reason. A directory can hold other directories (called
sub-directories), which lets us create a nested structure called a directory
tree that keeps things organized as we want. There are literally thousands of
files and directories on a typical system, most of which are used by the
operating system to keep its files properly controlled. 

We use a special string called a "path" to define where any file or directory
lives in this file system structure.

On a Windows machine, the path starts by naming the drive letter the file or
directory is stored on. The "C" drive is the default primary system drive, and
other devices, like DVD drives, or even USB Flash drives, will have other
letters. Linux does not use this scheme. Instead, a drive will be "mounted" in
some existing directory on the system, and all of the files on that drive will
become part of the one big file system directory tree. You do not need to worry
about what drive a file is on, as long as you can define the correct path to
that file.

..  note::

    Computer people are weird. They call this thing a directory tree, but it is
    upside down. The "root" of the tree is at the top, and branches work
    downward. You move around by dropping into sub-directories, or
    sub-sub-directories! 

We define the path to a file as the set of directories we must work through to
reach the particular directory where the file is located, followed by the name
of the file. Each time we need to move down from the "root of the tree, we use
a "separator" character to indicate we are starting a new directory or file
name in this string.

On Windows, the separator character is a backslash ("\"), and on every other
system it is a forward slash ("/"). 

Partial Paths
=============

If the path string starts with a separator character (or drive letter followed
by a colon and a separator) we are defining a full path to the file or
directory starting at the root of the file system (or drive on Windows). If we
leave off that leading separator, the system assumes you are describing a path
from your current working directory to the final place where a file or
directory can be found. This makes the path string much shorter.

There are two names for places that are special:

    * "." is an alias for "where I am now"
    
    * ".." is an alias for "the directory immediately above me!"

You can use these two shortcut names to shorten up a path string.

Let's look at a few example paths:

    * `/usr/bin/git` - the location of the `git` program on your system

    * `/home/rblack` - the home directory of a user named `rblack` (hmmm, that
      is me!)

The Working Directory
=====================

When you work on the :term:`command line`, the system assumes that you will want to
refer to files or directories located in some particular place in the file
system. That place is called the "working directory". When you first log onto
the system, you are placed in your "home directory", a directory set up for you
when the account was created. On Linux, the home directories are stored on the
system under "/home". The user name is used as a subdirectory under "/home" and
that will be your "home directory".

..  note::

    On Unix and Mac, there is an alias for your "home directory". That alias is
    the "~" character.

Changing directories
====================

The "change directory" command on all systems is `cd`. You specify where you
want to go by providing a string containing the path to the new location (which
must name a directory, not a file!)

Here are a few examples:

    * `cd` - on Linux/Mac go to your home directory. On Windows display the
      current directory.

    * `cd /usr/local` - move to this directory (full path specified)

    * `cd ..` - move to the directory above the current directory

    * `cd ../../dir1/dir2` - move up two levels, then go down into dir1
      followed by dir2

Creating Directories
********************

The command for building a new directory is this:

    * `mkdir <path>` - where <path> names the new directory

Here are some examples:

    * `mkdir temp` - create a new directory named `temp` in the current working
      directory

    * `mkdir ../temp` - create `temp` in the directory above the current
      working directory

    * `mkdir /home/rblack/COSC2425` - create the named directory

Permissions
===========

Every file and directory is "owned" by some user on the system, and has a set
of permission controls that define what any user can do with them. You must
have proper permission to read a file, create a file or directory, or run a
program file. On Linux/Mac these permissions are controlled by a set of
"permission bits" and there are bits defined for three sets of users:

    * Owner - the user who created this file or directory

    * Group - several users can be placed in a group to form a team
    
    * Others - all other users not in the other two groups

You can see the permissions on any file of directory on Linux/Mac by using this
command:

    * `ls -l` - display full info n things in this directory

Linux/Mac use several characters in this display:

    * `d` - this is a directory
    * `r` - read permission is set for this group
    * `w` - write permission is set for this group
    * `x` - execute permission is set for this group
    * `-` - this bit is not set

There will be three sets of three "bits" for the owner, group, and other set of
users.

Here is an example:

..  code-block:: text

    ls -l /usr/bin/git
    -rwxr-xr-x 1 root wheel 14160 Sep 29 00:38 /usr/bin/git

This is a simple file that contains the program. The owner is "root" and that
user can do anything with it ("rwx"). The group "wheel" can read and execute,
but not write the file, as can all other users.  We also see how big the file
is in bytes, and when it was created.  

Deleting Things 
***************

The command to delete a file or directory on Linux/Mac is this:

    * `rm file_name` - delete the named file
    * `rm -rf directory_name` - delete this directory and everything under it!

..  warning::

    Be careful with that last command, you can delete a lot of files with it by
    accident! And, there is no recovery from this.

..  note::

    There is one user, called the "super user" or "root" who can get around
    these permission controls.

Viewing Files
*************

If you want to see the contents of a text file, there are a few ways to do
that:

    * `cat file_name` - send the text file to the console

    * `more file_name` - show the file a "page" at a time 

Redirection
***********

The `Terminal` program displays text that simple programs output. Any required
input is provided by you typing on the keyboard. There two streams of
characters are called `standard output` and `standrd input`. You can "redirect"
both of these streams of text by using redirection characters on the command
line. Here is a common example:

..  code-block:: text

    * `prog_name < input_file > save_file`

This command runs the program `prog_name`. Any input needed by that program
will come from a text file named `input_file`, and any output generated by the
program ends up captured in `save_file`. If you leave off either, the
input/output go to the default `standard` devices (screen for output keyboard
for input).

You can send the output of one program to the input of another program as
follows:

    * `prog1 | prog2 > save_file`

This example runs `prog1` using `standard input` for any input needed. The
output from this program is fed to `prog1`, and the output from that program
ends up in `save_file`. This kind of control can be handy, and is the
foundation of the `Unix` way of doing things. There are tons of simple programs
that you can use to 'filter" text as it moves from program to program.


..  vim:filetype=rst spell:
