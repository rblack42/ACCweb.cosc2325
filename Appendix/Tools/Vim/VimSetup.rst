Configuring Vim
###############

..  include::   /references.inc

When you start using Vim_ to create your programs (and documentation), you will
want to tune it so it behaves the way you want. There are an almost unlimited
number of "tweaks" you can do to this tool. In fact, most good programmer's
editors let you do similar things as well.

..  note::

    GitHub_ is a good place to explore Vim_ configurations. Many programmers
    have a "dotfiles" repository they save there, so all of their system
    settings can be easily downloaded to a new machine. Of course, most of
    these settings are for Linux/Mac. The PC world has not caught up with this
    idea yet!

In Vim_ your customizations are stored in a control file named ``.vimrc`` (on
Linux/Mac) and ``_vimrc`` (on Windows systems). This file may not exist on your
system, depending on how you install Vim_ (or one of its variants). You can
create it, using Vim_, naturally!

There are actually two control files. One lives in the directory where Vim_ is
installed on your system, and is used for basic settings that apply to all
users of the editor. The second file is stored in the user's "home" directory
so each user can tune things to their particular liking.

Vim_ will look into the current user's "home" directory, which is the location
seen in the above paths. Windows systems are a bit different, so it is best to
let Vim_ tell you where to put this file. Do this: In general you should look
in these locations for the user configuration file:

    * ``/home/username/.vimrc``	(on Linux)

    * ``/Users/username/.vimrc`` (on Mac)

    * ``C:\program files\Vim\_vimrc``  (on PC. This is where Vim was installed,
      which may vary)
	
`* ``C:`Documents and Settings\username\_vimrc`` (on PC, this is
supposed to wor as well)



..  code-block:: bash

    :echo $HOME

On my Windows 10 system, this reported ``C:\Users\username``

Basic Settings
**************

The absolute minimal setup i use looks like this:

..  code-block:: text

    set tabstop=4       " set tab stops every 4 spaces
    set shiftwidth=4    " 
    set expandtab       " no tabs in code!
    set nobackup        " get rid of the ~ files (use Git)
