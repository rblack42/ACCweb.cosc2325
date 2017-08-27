..  _course-tools:

COSC2325 Course Tools Overview
##############################

..  include::   /references.inc

The ACC_ labs where we will be working have all the tools needed to complete
this course properly set up for your use. This section is an overview of the
tools we will use for those of you who wish to set up a personal system so you
can work on lab projects. Specific details on installing these tools can be found in the links on the Assignments page for the first week.

..  warning::

    Some of the tools we will be using are a bit complex to install. The notes
    should help you through the process, but if you get stuck, see me for help.
    You can bring in your system during office hours, or on Saturday in my RGC
    office. Check with me for times.
    

Checking your System
********************

he notes that follow are to help you set up a personal
system. You can use any platform you own, as long as it meets minimum
requirements (basically, a 64-bit processor that can run a :term:`virtual
machine`.)


..  note::

    If you are using the course :term:`VM`, you will be installing these tools
    inside that machine. A summary of the steps you need to follow is at
    :ref:`ubuntu-tool-install`. The notes that follow are general background on
    each tool, and instructions for installing each tool on other systems.

Since we will be studying 64-bit systems in this course, you need a 64-bit
system to do your lab work. Most modern systems will work fine, but if you have
an older system, or are not sure if your system can run a :term:`virtual
machine`, here is a Windows program you can use to check your machine out:

    * :download:`VMware-guest64check.exe`

On some systems, you need to activate ``virtual extensions`` using the BIOS
control panel. If your system has problems starting the VM after it passes this
check, see me for help before you give up on a system.

..  note::

    If you do not own a machine that can run the course :term:`virtual
    machine`, I will set up an account for you on a Rackspace_ server I use for
    students in this course. You will be able to access this server from any
    machine you own. Note that the interface to this server will not be
    graphical, it is a simple :term:`command line` interface.

A Good Programmer's Editor
**************************

..  note::

    I am not going to require you to use any particular editor, but you should
    pick one and learn it well if you expect to continue with programming as
    part of your chosen profession.  

A programmer's editor understands that you are writing code, and works with you
to make that code look right. Ideally, your editor will be available on any
platform you happen to be working with. In my case, I have programmed on small
desktop machines and supercomputers. The editor I have used for almost 40 years
is a variant of Vim_, which comes installed on many machines, and can be added
to others.

If you already have a favorite editor that can be installed in Ubuntu Linux, or
on the host machine, you are free to use that instead.

Ubuntu Linux VM
***************

Since most of you own machines running Windows, or Mac OS-X, I have been
teaching this course for many years using a :term:`virtual machine` with
Ubuntu_ Linux installed. Learning how all this works is good for you! Many
employers expect you to be familiar with :term:`VM` systems, since they are a
big part of the server world, and becoming a big part of the desktop world as
well. A good :term:`VM` lets you create an isolated environment where you can
work on a project, and easily move the entire project to a backup device, or
another machine. 

The system we will be using is Ubuntu_ v14.04 (Desktop version), although you
can use with the server version as well. Except for the graphical debugger we
will use, using a :term:`shell` (:term:`command line`) interface is fine.

All of the tools needed for the course are installed in the :term:`VM` image
available in the labs. You should plan on copying this image to a flash drive
(8GB minimum) for installation on your PC. Mac users have to install from
scratch.

The Nasm Assembler
******************

For most of the course, we will write assembly language code for the Intel
Pentium processor. The assembler tool we need to process our code is Nasm_. 

..  note::

    We may use the term :term:`compile`, but formally, we :term:`assemble` our
    code using an :term:`assembler`.


Installing C/C++
****************

We will cheat a bit in this course, and let C/C++ do the hard work of
interfacing with the operating system. We need to do that to put text on the
screen, and to get input from the keyboard. So, you need a 64-bit compiler. The
Gnu_ tools are best. 

Source Code Control tools
*************************

We will be using a very important tool in this class. As a software developer,
it is important that you become familiar with :term:`Source Code Control
System` used to manage changes in project assets. 

In this class, we will be using Git_, one of the most popular :term:`SCCS`
tools on the market. Git_ was written by Linus Torvalds to help him manage the
thousands of programmers who work on the Linux Kernel. We will also be using a
server to host your lab work. This server is set up very much like GitHub_ but
is private, something we need in an academic setting!

..  warning::

    Never post lab work used in an academic setting on a public system like
    GitHub_. Do you really want others to get jobs based on work you did in
    school!  
    
A Build Tool
************

Typing in commands to process your code on the :term:`command line` is a pain.
Whenever that happens, you can be sure some programmer built a tool to avoid
all that work. In the programming world, that tool was build over 40 years ago.
The name of the tool is `make`.

We will use this tool in several of my classes, and you really do not need to
know much about it to use it effectively. But, like anything else in this
world, the more you know about something, the better you will be able to see
ways to use it to make your professional life easier and more successful. 

We will go over using Make in class, but you should get started setting up a
machine you can use at home. I highly recommend setting up a laptop for your
coursework (not just my course) and using is to do all of your work. If you do
not own a laptop, the Computer Studies labs have machines set up for your use.

..  vim:filetype=rst spell:
