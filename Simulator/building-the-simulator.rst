Implementing the Simulator
##########################

So far, we have developed a simple model of a Memory module, and a simple ALU.
We need additional parts to complete the simulation of a computer.

We will add two more basic classes for this next step.

Controller
**********

The **Control** unit of our machine is responsible or the over action of the
machine. This unit muct provide the four fundamental actions ndded to make this
machine "dance:

    * Fetch - a single byte from instruction memory

    * Decode - retrieve any additional data needed from instruction memory

    * Execute (we will implement this later)

    * Retire (we will implement this later)

This class also needs to provide two private attributes:

    * PC _ the address of the next instruction to be fetched

    * IR - a place to store the retrieved instruction (for decode)

Obviously, as we work through this cycle, we will be update the **PC** variable
so the machine works its way through whatever code w elaod into instruction
memory.

We will also provide an additional method:

    * reset - return the PC to zero to restart fetching from this address (this
      is useful in testing).

Since memory is allocated outside of the **Control** unit, we will pass in the
address of the memory unit each step needs. For instance, both **Fetch** and
**Decode** need access to the instruction memory. Inside those instructions,
you use the address to access the memory object.

We will need to pass in the data memory address and probably the register
memory address for the **Execute** and **Retire** methods. Exactly how these
are used depends on the instructions.

Machine
*******

The **Machine** class acts as a wrapper around our entire machine. Inside this
class, we will construct a control unit, an ALU, and several memory modules:

    * iMem - instruction memory

    * dMem  - data memory 

    * rMem - models internal (zero delay) "registers" in the machine. We will
      allow at most 32 16-bit registers.

Since we are using dynamic memory to create memory objects, we need a
*Destructor* for this class, which will free any dynamically allocated memory
objects as the machine object is destroyed (goes out of scope).

Before we can get very far with this machine, we need to define the
instructions to be processed by the machine. Tht is our next topic

..  vim:ft=rst spell:
