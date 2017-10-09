Designing an Assembler
######################


Normally, we would build a tool to process our assembly code into the simple
numbers we need to load into the machine. I am going to make our simulator a
bit easier to run. We will process assembly language files directly, and
convert them into the needed data as we load things into memory. This turns our
simulator into a kind of ``interpreter``, and gives us a chance to look briefly
at how you process a simple language. We will be using those ```railroad
diagrams`` we saw earlier in this work.

Parsing
*******

Formally, we will ``parse`` our assembly code file.

Each line of this assembly language file is self contained. That makes reading
the file simple. It also means we only need to build a parser that can process
a single line. 

Here is a start at reding the file, line by line:

..  literalinclude::    code/src/main.cpp
    :language: c
    :caption: Test assembler code

Here, we are defining a parser object that will process our code lines. Each
line is passed to the `run`` method for processing.

The parser is going to break up a single line into chunks we call ``tokens``.
We provide a method to fetch each ``token`` in the line, and return a string
showing that token in printable form. This example code just reads the entire
file and show the sequence of tokens found in each line.

The ``Parser`` class has a ``set_debug`` method that will make it tell you what
it is doing in excruciating detail!

Here is the header file for the parser:

..  literalinclude:: code/include/Parser.h
    :language: c
    :caption: Parser.h

And the implementation file (comments will be dded later)

..  literalinclude:: code/lib/Parser.cpp
    :language: c
    :caption: Parser.cpp

Finally, here are two test files that check things.

..  literalinclude:: code/tests/test_scanner.cpp
    :language: c
    :caption: test_scanner.cpp


..  literalinclude:: code/tests/test_parser.cpp
    :language: c
    :caption: test_parser.cpp


..  vim:ft=rst spell:
