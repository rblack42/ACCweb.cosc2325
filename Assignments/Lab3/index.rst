..  _lab3:

Lab3: Simulator Setup
#####################

This week, we will create the basic simulator machine. The example **CPUsim**
project now has the required header files, and tests to make this basic machine
work. (There are a lot of tests!)

We will build two more C++ classes to create the machine:

    * Machuine - a wrapper around the entire simulator

    * Controller - the main control component


The **Machine** class is where the individual components of our machine are created. The constructor for this class needs to create an object from each component class, and save those in instance variables. 

For our simple machine, we will need these parts initially:

    * Controller object

    * Instruction Memory object

    * Data Memory object

    * Register object (32 internal registers, each 16 bytes wide)

    * ALU object

We will pass the address of any of these component objects to another component
as needed. (For instance, the *fetch* method in the Controller class will need
access to the instruction memory so it can *fetch* an instruction from that
memory).

Here is an example of the machine accessing instruction memory, using the
address:

..  code-block:: c

    iMem->write(addr, 1, data);


This assumes that *imem* holds the address of the memory object created with
the C++ **new** operator.

The **Controller** class sets up methods to do the 4-step dance: fetch, decode,
execute, and retire. It does none of these things directly. Instead, the
Machine class will set up that loop. For each Controller method you invoke, you
will need to pass in the address of the Machine parts needed to handle that
step.

Obviously, **fetch** needs only access to the instruction memory. **Decode**
will also need access to the instruction memory to retrieve dditional bytes for
the instruction. The **Execute** unit will need access to the data memory and
internal registers we will also need ot set up. It will also need access to the
**ALU**.Finally, the **Retire** method may also need access to those same two
data and register memories.

Basic Machine Operation
***********************

For this lab, I have set up the **main.cpp** file so it runs as needed for this project. The program accepts a simple command line that looks like this:

..  code-block:: text

    pgmname [-d] [0s num] codefile

Here the **-d** flag enables debugging, which can be used to the simulator
displays text to indicate what it is up to at any point in time. The **-s num**
flag tells the machine how many *cycles* (instructiobs) to process before it
stops. If you nead this option off, the machine will run until it executes a
**HLT** instruction.  

..  note::

    The square brackets on that line indicate that that option is optional. If
    not provided, the machine should set debugging off, and not stop until
    something else causes it to stop, like running into a **HLT** instruction.

Starting Instruction Set
========================

We need some simple instructions for the machine to "dance" through. I have
included a starter set in the **mnemonic.h** file in the **CPUsim** example
repo.

Basically, these instructions handle moving data from place to place, and doing
simple (unsigned) math.

MOVXX Instructions
------------------

The machine needs ot be able to move data from place to place. The actual
movement will be between *data memory* and some internal place in the machine
were we can store thatdata. Internal memory is called **Registers**, and most
machines provide a small set of these. Register memory is fast, so we set the
delay times to zero here.  Our **Registers** memory should be sized to hold up
to 32 16-bt data items. We will always store data in this memory in the form of
full 16-bit values, just to simplify the access logic a bit.

In most modern machines we do not provide a way to move data around directly in
memory. Instead, we move data between internal registers, of from memory to and
from registers. The "address" of an internal register is just a single byte
number (more than enough to select one of 32 possible registers).  

We need different instructions for each kind of movement we will support:

    * MOVRR - move data from one register to another register

    * MOVRM - move from memory to a register

    * MOVMR - move from memory to a register.

There is one additional wrinkle to this idea. We need to say how big our data
is. Since we support both 8 and 16 bit data, we really need ot say which we are
using in the instruction. We will address this on our next lab, for now,
concentrate on moving 8-bit data only.

(The solution is to add a character to the instruction so we can distinguish
the data size: MOVBRR would move 8-bits between registers.)


Code File
=========

Obviously, we need to provide some code for this machine to run.

Since we do not have am *assembler** yet for this machine, we will provide a
simple test file containing the byte data the machines meeds in the instruction
memory to operate. Each line in this file is a simple integer number (unsigned)
that will be used as the instruction code and any additional data needed by
that instruction to fully define tha action.

The instructions are actually defined in a **mnemonic.h** header file. They
are in the form of a C++ enumeration, which is a simple way to use a series of
simple names as values. (If you have not used enumerations, the names are
aliases for integer numbers. Those numbers are assigned starting with zero and
incrementing by one for each name in the list.) The provided file lists a
starter set of instructions.

When the machine starts up, the first thing we need to do it *bioot* the
machine. This will involve reading this code file and storing the data in
successive bytes of instruction memory. Note that if you need to put 16 bit
data into the instruction memory, you need to manually break that into two
bytes and list each byte on successive lines (low byte first, then high byte
next).

Once the instructions are loaded, the dance will start. The address of the next
instruction to load will be managed in the **PC** variable defined in the
**Controller** class. The **fetch** method retrieves the instruction code byte
and saves it internally in the **IR** variable (Instruction Register). The
**Decode** method then runs and checks the instruction byte to see if it is
valid. This is done using a C++ *switch* statement, with one *case* for each
mnemonic defined. If the instruction needs to pull in more bytes (register
numbers or memory addresses) it will need to do that and save the results in
variables for later use.

For now, we do not need to worry about **execute** and **retire**, that will
come in the next lab.

If the code does not match one of the defined instructions, we need to signal
that the machine is being asked to perform an illegal instructuction. How you
deal with ts up to you.

..  note::

    Remember to update the **PC** after the **decode** is done, so the machine
    will move to the next instruction.

Basic Machine Operation
=======================

The **Machine** class provides a **run** method. After loading the code, we need to start the dance. Here is the basic idea:

..  code-block:: c

    int cycles = 0;     // tracks the number of instructions processed
    int ticks = 0;      // number of clock ticks used
    while(true) {
        ticks += ctrl.fetch(&iMem); 
        ticks += ctrl.decode(&iMem);
        ticks += ctrl.execute(&rMem, &dMem, &alu);
        ticks += ctrl.fetch(&rMem, &dMem);
        cycles++
        if(cycles == stop_cycle) break;
    }

IN this code, we have each dance step track the number of clock ticks needed to
complete the work. Since we are using memory objects created using the classes
you set up for Lab1, we can count the number of times we needed to check the
**ready** method to see what the delay was.

Here is what the **fetch** method might look like:

..  code-block:: c

    int ticks = 0;
    ...
    IR = iMem->read(PC,1);
    while(!iMem->ready()) ticks++;
    ...
    return ticks;

Here, we are using a local variable to count how many simulated clock ticks
pass before we get our data back. We return that count to the caller, where it
is added in the **ticks** variable in the **Controller** class. Using this
scheme, we can see how "fast" our code was, as a measure of the clock ticks we
consumed. Adding in some fake clock frequency would let us predict the human
time that program would have taken to complete.

Example Code
************

The **CPUsim** example code has all of this set up now, complete with a
reasonable set of tests you can use to see how your implementation is going.
For this lab, concentrate on getting the code file set up, then adding code to
the Controller class implementation necessary to get the machine to process
each instruction. 

The test set provided runs 76 individual tests at this point, in 26 different
**TEST_CASE** blocks. Feel free to add tests if you feel part of this machine
is not tested adequately.



