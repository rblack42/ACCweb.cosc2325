Decoding the Dance
##################

::
    Fetch, Decode, Execute, Store

That is the dance computers do, billions of times per second, times billions of
machines per planet! Let's watch one run, really slowly!

..  warning::

    The code shown in this lecture is not production ready. Instead this
    represents an exploration into the methods needed to implement the real
    simulator. Do not expect to use this code as presented. You should
    experiment with ideas outside of your real project, then use the schemes
    you work out in your actual project code.

Ready, set, dance!

Fetch!
******

Fetch what, from where?

Well, we need an instruction of some kind to know what to do, and
that instruction needs to be stored somewhere in the machine. Let's create a
simple array of 8-bit bytes to store the instructions, and make each
instruction a single 8-bit code of some sort. 

Here is a cool idea! Let's name this array the ``memory`` of the computer.

(No one ever thought of doing this, did they John? :cite:`VonNeumann:1945`)

..  literalinclude::    code/main.cpp
    :caption: main.cpp
    :lines: 4-7

.. note::

   The ``cstdlib`` header provides these fixed sized bit containers. We are
   using the unsigned integers of the specified size for our containers in this
   code.

Fetching one instruction is as simple as looking into that array and pulling
out a single byte of data.

Wait a minute, how did the instructions get into that array in the first place?

Well, we need to ``load`` our array with instructions to process. I know, let's
call that action ``booting the machine!``.

Since we have no idea what an instruction looks like at the moment, except that
it is a single 8-bit number, we will just use a sequence of numbers (limited to
values between 0-255, naturally!)

I am going to make ``booting`` easy, we will just load our array using a data
file we can create with our trusty text editor (you have one, right?).

Here is a sample code file:

..  code-block:: text
    :caption: instructions.txt

    1
    2
    3
    ...
    0

I know this is silly, but we are experimenting here. All we need at the moment
is a bunch of 8-bit numbers to read

We need a way to make the dance stop, so we will use a special instruction to
do that. I decided to make an instruction with a value of zero halt the
machine. (That explains the last line in the code file!)


..  note::

    Lots of machines cannot really halt, until you pull the power plug on them.
    Ours will cease dancing when told to process this special code.


Booting the Machine
===================

You should be able to get this file into your array:

..  literalinclude::    code/main.cpp
    :caption: boot
    :language: c
    :lines: 3,7,14-27 

..  note::

    I am using a ``define`` line at the top of this code to set the ``DEBUG``
    macro to ``true`` for testing. This way, I can set it to ``false`` and
    eliminate extraneous output needed only for (wiat for it) debugging!

Starting the dance
==================

One thing should be obvious, right from the start. We need to have some idea
where in that array to start fetching our instructions. We need a variable to
track where the next instruction is located in our ``memory`` array. 

This should be easy!

..  literalinclude::    code/main.cpp
    :caption: Program counter
    :lines: 4,8

We are using 16 bits for this variable, which limits possible indexes
to values between 0-65535. That was the amount of memory in my first home
computer, an Imsai 8080, built out of a kit in 1975 for $400.


We might as well get used to calling this index what it really is: an
``address``. In real memory all bytes of storage have a unique address,
beginning at zero and ending where you ran out of money. Most of my machines
have 16 GB of memory, and that last address is pretty big: 17179869184!

We have all the elements in place to start the dance. Here is some simple code
to do just that:

..  literalinclude::    code/main.cpp
    :caption: dance loop
    :lines: 12,40-58

UINT Maddness
=============

Notice the ```outbin8`` call in the debug code. I need to set up a function
that will display the codes in binary. (Why? We will see why later).

C++ treats these ``uint8_t`` variables a bit weirdly. For one thing, if you try
to input them directly from standard input, you get the character codes for the
numbers in our code file. That is not what we want. So, the trick is to read
them in as integers, and let C++ handle converting them into proper ``uint8_t``
values when it stores them in the memory array.

We want to make the instructions very clear, so we output them as binary bits
(all eight of them). Here is the little routine that will do that. It uses the
C++ ``bitset`` data type to do the job:

..  literalinclude::    code/main.cpp
    :lines: 29-31
    :caption: outbin8

It is time to look at the entire program now, together with the output I got:

..  literalinclude::    code/main.cpp
    :linenos:
    :caption: main.cpp

And here is the data file I processed:

..  literalinclude::    code/instructions.txt
    :caption: instructions.txt

Finally, here is a simple Makefile to build and run the example code:

..  literalinclude::    code/Makefile
    :linenos:
    :caption: Makefile

And, here is the output from processing this code:

..  code-block:: bash

    $ make run
    Dancing v0.1
    Boot: 1010 instructions loaded
    0 00000001
    1 00000010
    2 00000011
    3 00000100
    4 00000101 
    5 00000110 
    6 00000111 
    7 00001000 
    8 00001001 
    HALT Machine halted:
    9 instructions processed

Before we leave this step, we need to make an observation. In the example code
above, the ``fetch`` function returned a value. In the real machine, there are
no functions, and there are no return values. Instead, internal storage places,
called ``rgisters`` are used to hang on to a piece of data, and wires are used
pass data from place to place. From this point on, we will set up these
``registers`` as global variables, and have our dance step routines simply
access those global variables. That will work as a substitute for real wires in
this example code.

..  note::

    Yes, Guido will be upset. Globals are frowned on in modern programming. We
    are building a simulator, and globals do the simulation job just fine. 

We will call the place where the fetched instruction code lands the ``IR``
register in our next code examples.

Decode!
*******

Now that we have a handle on ``fetch``, it is time to learn a new dance step.
The second step in our dance is ``decode``.

This one is more complicated, since we need to deal with the fact that each
real instruction may need additional data to completely define what to do.
During the ``decode`` step, we need to go back to the instruction memory and
get the additional data needed.

For example, if we want to add two numbers, we can surely create a code for
adding, but we need additional information to identify two numbers to
add, and where to put the result.

Without worrying about exactly what form this additional data takes quite yet,
let's just say that we may need anywhere from zero to as many as four
additional bytes of data after that instruction code. We will need to add every
one of those additional bytes to the code file. We can add these bytes (space
separated) on the same line as the instruction code.

The big problem we face now is figuring out how many additional bytes each code
needs.

Obviously, our simple code file with simple numbers is not going to help much.

Encoding Instructions
=====================

A common technique for dealing with this involves breaking the instruction
code up into ``fields`` each of which provides information needed to fully
define the instruction. 

We already have an eight bit instruction code, and that allows up to 255
instructions (leaving one for the **HALT** code). That is way more instructions
than we need. However, we will leave the instruction code in that first byte.

We do need to figure out where the data we need might live. So, let's introduce
a few places where that data might be.

Internal Registers
------------------

Our machine will provide a few special (fast) internal registers, named
``r0-r7``. Since dealing with these names directly will be hard (C++ is not
happy about indexing an array with strings, but Python could do it), we will
use the register numbers to refer to them in our code. That means we need
another 3 bits to specify one of these registers. For simplicity, we will use a
full 8-bits to store a register number in the code array.

We need to decide how big these registers are going to be as well. While most
memory is organized as bytes, it will be useful to make these registers 16-bits
wide, so they can hold addresses as well as numerical data. There is no problem
designing machines this way. The huge RAM devices we use in most computers are
just organized as byte storage for convenience, and hardware takes care of all
that data splitting work when more than one byte is needed to store something.

If we need to place a single byte in a register, we will just zero out the high
bits and store the byte in the entire register.

Data Memory
-----------

We also need some place to store data items that is not on the chip itself.
Obviously, this is the main memory of the machine. Another byte array will be
used for this (we are obviously building a ``Harvard Machine``).

Here is code to set up all of the required memory arrays:

..  literalinclude::    code1/main.cpp
    :lines: 9-12
    :caption: memory areas

The array names help us keep track of what each memory area is used for.

Data sizes
----------

We will allow both 8-bit and 16-bit data in our machine. Since the instruction
and data memory areas all only hold 8 bits in one container, we will need to
split a 16-bit data item up to store the two pieces in memory, and reassembly
those two chunks when we want to fetch a 16_bit data item from memory.

Each instruction will need to be able to work on either 8-bit data or 16-bit
data. We will not allow it to mix 8-bit and 16-bit operations in a single
instruction.

We can use another bit in our instruction code to indicate
what size data we are working with. We will use a bit value of zero to indicate
that we are working with 8-bit data, and a value of one to indicate we are
working with 16-bit data.

Endianess
.........

If a data item takes more than one byte to store, we need to deal with the
order of the bytes as we place the pieces into memory. The most common scheme
is called ``little-endian`` meaning the low order byte is stored in the byte
pointed to by the specified address.  Then the next byte  to the left is stored
at the next successive byte, and so on until all are stored. Note that the
address of this data item points to that first byte stored. The machine does
not keep track of how many bytes are stored in this data item, that is the
programmer's problem.

The other, less common, storage scheme places the left most byte in the first
memory slot, then the second from the left, and so on. This is called
``big-endian``. We will not use this scheme.
here is some code that deals with our 8 or 16-bit data items:

..  code-block:: c

    uint8 b1, b2;
    uint16 data;
    int size;       // 0 for 8-bit dta, 1 for 16-bit data

    // storing 16-bit data
    data = 592;
    b1 = data && 0xff;  // break ff the low byte
    memory[address] = b1;
    if(size == 1) {
        b2 = data >> 8;     // slide the bits to the left
        memory[address+1] = b2;
    }

    // fetch 16 bit data from memory
    data = memory[address];
    if( size == 1)
        data += memory[address + 1] << 8;

Just remember that the range of legal values are these;

    * uint8_t: 0-255
    * uint16_t - 0-65535


Operands
--------

The additional data needed to fully specify a single instruction will be called
``operands``. These will specify an internal register, a memory address, or a
literal number. We will need 8=bits to specify a register, and a full 16-bits
for addresses and literal numbers. 

We specify the additional data needed for any instruction in an ``operand``.
Instructions may need zero, one or two operands, depending on what we want them
to do.

..  note::

    Some machines allow more than two operands, but two will do for our example
    machine.

Operand Types
.............

Operands can refer to a register (by number), a memory location (by address),
or a literal value. 

When we refer to a register, or a memory address, usually we are interested in
the data contained in that spot. However, we need to address one other feature
most processors support. 

Indirection
...........

In some cases, we might cause an address to be loaded into a register.  We then
might want to use that address and go back to memory at that address and fetch
what we find there! This is called  an ``indirect`` access.

In many assemblers, we surround that register name in square
brackets, to remind you that something special is going on:

    * [R8] - R8 hold an address, but we want the data at that address

Those bracket are also used when you want the data at some address, not the
address itself. We might specify an address by using a name, not a number. This
isjust like what happens with variable names in your C++ code. Those names are
really ailiases for the address where that variable lives:

    * [addr] - the memory at this address holds the data you want

Operand sizes
.............

Most of our instructions need some way to tell the machine how big the operands
are. In our machine, we only allow two sizes: bytes, and words. We can use a
single bit to encode this information. It is common to let a programmer specify the size of an operand, if it is not obvious, by using a reserved word of some kind. We will use these in our assembly language:

    * ``BYTE`` - 8-bit data

    * ``WORD`` - 16-bit data

Operand names
.............

If we specify two operands, it is common to refer to the first operand as the
``destination`` and the second on as the ``source``. Back to our ``add``
example, we might present this instruction like this:

    * add BYTE r8, address

This is a common way to present an instruction. The instruction code is given a
human readable name, then the operands are presented with a comma between them
(if there are two). We never split one instruction across multiple lines, and
never place two instructions on the same line. This is more a style convention
rather than a rule, but we will follow this guidance.

The example instruction will add the contents of ``r8`` (which holds a byte in
this example) to the data stored at memory location pointed to by the address
and store the result back in ``r8``. THat ``BYTE`` tag tells us that the entire
instruction is working with bytes, both for the source and destination
operands.

Encoding Operands
-----------------
With all of this background, we are now in a position to look at how we will
encode these operands.  This looks pretty complex. We will take it slowly!

Let's start off by examining the possible operand types:

Operand Codes
.............

..  csv-table::
    :HEader: oCode Oper

    000, none
    001, register
    010, memory
    011, literal
    100, register indirect

Encoding the two operands can be done by as adding a second byte (after the
instruction code) and using four bits for each operand. We will use the low
four bits to identify the first operand, and the second four bits will define
the second operand type. In each part we will encode the operand size, and the
operand code to indicate what kind of operand we are using in this instruction.

..  note::

    It will be illegal to say that the first operand is missing, but we have a
    second operand!

Decoding these operands will be simple. After we identify the instruction, we will fetch another byte from the
instruction memory, and break that byte up into two 4-bit values. We will then
use a C++ ``switch`` statement to identify the operand type. That data will
tell us if we need to go back to the instruction memory to fetch additional
data to completely define the operands.

Here is some code that will do that job:

..  literalinclude::    code1/main.cpp
    :lines: 104-109
    :caption: decoding operands
    :language: c

With the operand type byte available, this code will break it apart:

..  literalinclude::    code1/main.cpp
    :lines: 70-93
    :caption: oCode splitting
    :language: c

Finally, here is some code that will fetch the required operands fro instruction memory:

..  literalinclude::    code1/main.cpp
    :lines: 95-101
    :caption: fetching operands
    :language: c

The Dance Code
**************

Here is the code used to control the dance so far:

..  literalinclude::    code1/main.cpp
    :lines: 112-144
    :caption: dance logic
    :language: c

We do not have enough code here yet to actually run the dance. To complete this
discussion, we need to set up some real instructions for our machine. That will
be the next topic we explore.

.. vim:ft=rst spell:
