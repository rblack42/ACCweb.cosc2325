Configuring Your Editor
#######################

..  include::   /references.inc

We pick a programmer's editor for one reason, to get editing done efficiently.
The problem we face is that editing is very dependent of exactly what we are
editing. So, we need some aspects of how our editor works to change as we move
from context to context.

Traditionally, Vim_ users craft a custom ``.vimrc`` file with the settings they
want for their work. These configuration files can get complex, and what you
set up for Vim_ will not help much if you decide to try a different editor.

The EditorConfig Project
************************

A nice project on Github_ tries to capture this problem and give you  simple
way to mnage your configuration, and use that same setup on different editors.
This might be worth your time trying out!

Installing EditorConfig
=======================

Assuming you have Git_ installed (you do, of course), install EditorConfig as follows:

..  code-block:: bash

    $ git clone https://github.com/editorconfig/editorconfig-core-c.git


