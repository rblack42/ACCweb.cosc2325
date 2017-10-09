..  _lab2:

Lab2: The ALU Component
#######################

..  include::   /references.inc

..  note::

    Remember, there is no invitation for this lab. Add the code to your repo
    from Lab1.

Hopefully, your Memory Unit is functional now. We will not be using that code
yet, but we will be hooking up parts of out computer soon.

If you are having problems building these parts, read this:

    * :ref:`building-components`

This lab is about teaching the machine to do simple math

Adding more ALU Functions
*************************

In this lab, we will set up a basic ALU, but focus on the math part first. For
our simple machine, we will only provide addition and subtraction operations.
However, we still need to deal with bith 8 and 16 bit data. We will not
consider mixed operaations where one operand is 8 bits, and the other is 16
bits. Both operands are the same size. 

The interface to the ALU is pretty simple, as you can see by examining the
class header file:

..  literalinclude::    code/ALU.h
    :linenos:

Note that, as we did in the Memory module, the ALU does not return the value
of the operation in the basic call to perform an action. Instead, we will
provide a *read* function to retrieve the value produced. We will also provide
a *cary* function to see if we generated a carry, and an *overflow* operation
in case our operation overflowed.

Figuring out these two boolean "flags" is a bit involved, so I am providing
notes explaining the rules with this lab.

    * :ref:`carry-rules`

Testing Your ALU
****************

You shoud use the example tests provided in the CPUsim example code to test
your basic ALU. You can add any testsyou feel are necessary to more properly
test this unit.

..  vim:ft=rst spell:





