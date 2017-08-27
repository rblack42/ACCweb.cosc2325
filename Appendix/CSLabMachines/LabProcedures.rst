..  _cs-lab-procedures:

CS Lab Procedures
#################

..  include::   /references.inc

If you intend to do your coursework on a lab system, there are a few procedural
things you need to know

Student VM
**********

All lab machines have either VMware_ Workstation (NRG, HLC) or VMware_ Player (RGC)
installed on machines in the classroom and lab assigned for the class. These
:term:`VM` machines have a standard user account you will use to log into the
systems.

    * User Name: student
    * Password: Handed out in class

You can use any machine available to do your work in any of these rooms.

Waking up the Lab VM
********************

Before doing anything on the lab machine, get yourself logged in and start
either VMware_ Workstation, or Player, depending on which campus you are
working from. 

Make sure you see the ``cosc2325vm`` entry in the available machines list on the
left side of the screen. The actual :term:`VM` is stored in
``c:\VirtualMachines\cosc2325vm\cosc2325vm.vmx``. Double clicking on that file
name will open the :term:`VM` as well. 

Once the program is running you need to make sure that shared folders are set
up correctly.

Select :menuselection:`VM --> Settings`` to get to the control panel where the
machine settings are stored. Under :menuselection:`Options` tab, click on
:menuselection:`Shared Folders`. Make sure "Always enabled" is checked. The
folders window should show ``COSC2325 H:\``. If this is not visible on your
machine, ask a lab tech for help.

Waking up your VM
=================

You start the :term:`virtual machine` by clicking on the green arrow button on
the menu at the top of the window.  The first time you wake up the class
:term:`VM`, you will be asked if the virtual machine was moved or copied. You
need to answer "I copied it". Ignore any messages that pop up about devices
that may be connected to the host machine. (You can click on the "Do not show
this hint again" check-box if the device is normally attached to this machine.)

Logging In
==========

You should end up looking at a GUI login screen with three accounts listed:

    * ladmin - used by lab technicians
    * Roie Black - used by guess who
    * student: used by you!

Use the arrow keys (or mouse) to select the correct account and enter the password.

Once you are successfully logged in, you should see a normal Ubuntu :term:`GUI`
screen with several buttons along the left side. The one you will use the most
is the terminal window which shows a black button with ">_" displayed. This
will open up a console where you will type in commands. (We will go over the
basics in the lab sessions).

Home Directories
****************

Normally, you would store all of your personal files in your home directory,
which would be ``/home/student`` for the account you logged into on these
systems. Since we want you to be able to use any machine available, you cannot
store any personal files in this standard home directory! So, how are we going
to solve this problem?

Mapped "H" Drives
=================

All lab machines have been configured so they "share" a directory on the host
machine with the :term:`VM`. That shared directory is located at this directory
when you are working in the :term:`VM`:

    * ``/mnt/hgfs/COSC2325``

This particular directory is mapped to the root of your student "H" drive,
which will be available any time you log into a lab system with the credentials
provided when you started the class (to log in on the Windows host machine).

I recommend that you create a folder on your "H" drive named `COSC2425` and
place all of your work in that folder.

Once you are logged into the :term:`VM` and have a terminal session open, you
should change to this directory using this command:

..  code-block:: text

    $ cd /mnt/hgfs/COSC2325

Now you are ready to work on projects! All required tools are already installed
on these systems. If we need anything else, I will need to make those changes,
since the student account does not have administrator privileges.

..  warning::

    Remember that anything you leave in any directory on the Ubuntu system in
    the "normal places will be saved on that machine only, and any student who
    uses that same machine will have access to those files. Only files you save
    under ``/mnt/hgfs/COSC2325`` will be safe in your personal area, and will be
    available on another machine.

..  vim:filetype=rst spell:
