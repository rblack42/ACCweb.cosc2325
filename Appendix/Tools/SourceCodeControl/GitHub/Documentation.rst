Documentation on GitHub
#######################

..  include::   /references.inc

Once you start hosting your project code on GitHUb_, you should consider making
sure your documentation is nicely formatted so those folks who look at your work
over will be able to easily see what you are up do. You can make your documentation
look nice if you use a simple :term:`markup language` to do your writing. If
you write your documentation in either reStructuredText_ or Markdown_, GitHub_
servers will automatically format them nicely when they are viewed in a web
browser. I have been doing this for years, writing all of my lecture notes,
blog articles, almost anything I write, using reStructuredText_, which is the
standard documentation tool for the Python project.

..  warning::

    GitHub_ formatting tools are not capable of displaying everything you can
    create using simple markup, so be warned that not everything you might
    write will display correctly. Keep things simple, and this automatic
    processing will work fairly well. If "you need more power" look into the
    real processing tools available for those :term:`markup languages`. I use
    Python Sphinx_ for my reStructuredText_ notes. See :ref:`installing-sphinx` for
    more information.

Project README File
===================

You should always place a `README` file at the top level of your project
directory. Since I use reStructuredText_ markup in this file, I name mine
``README.rst``. GitHub_ will format this file using the right tools, and
display it on your project's main page (at the bottom, after the list of files
in the project).

Here is an example of a ``README`` file you might use:

..  literalinclude:: code/README.txt
    :linenos:

..  note::

    GitHub_ will display the unformatted text of this file by clicking on the
    file name in your project directory and selecting the "Raw" menu item at the
    top of the page you see. You can use this trick to examine all of the notes
    on my GitHub_ pages, since I keep my lecture notes on my GitHub_ account.

Basic reStructuredText Markup
*****************************

Here is a link to a beginner's guide to documenting things using
reStructuredText_ markup:

    * `reStructuredText Primer
      <http://docutils.sourceforge.net/docs/user/rst/quickstart.html>`_

If you want GitHub_ to format things for you, you should limit your markup to
only simple constructs, and not try to build a book style page. 

..  note::

    Sphinx_ can do an amazing job of documenting a real project, and
    automatically generate nice looking details about the functions in your
    code using a feature called ``autodoc``. We will not look at that here, it
    will be in a later note.

Getting Started
***************

I recommend looking at the raw source code on my lecture notes to see how I set
things up in my documentation. Do not get carried away at first, use simple
things like:

    * headings

    * code blocks

    * code blocks

    * inline markup

        * bold

        * italics

All of these basic markups will format on GitHub_ just fine, and will be
sufficient to document your first projects. See :ref:`installing-sphinx` for
information on using Sphinx's for more advanced documentation.

    ..  vim:filetype=rst spell:
    
