..  _carry-rules:

Determining Carry and Overflow FLags
####################################

When we do binary math,n a cmputer there are two basic situation where the
result we generate is not formally "correct". These two situations depend on
whether we consider the operands as signed or unsigned numbers. Remember that
the machine has no idea what kind of data it is working with, it just sees the
bits and does the operation.

In any ALU operation, the result of that operation is always the same size as
the operands. (And, in our machine both operands must be the same size - no
mixing of sizes is allowed!)

In unsigned math, if the result does not fit into the same container size,
either because we generated one more bit on **ADD**, or borrowed a bit from
beyond the far left bit on **SUB**, the **Carry** flag will be set to indicate
the problem. The actual value we will see is wrong, since that extra bit is
needed to get the complete answer.

Signed math is more tricky, since we need to watch the sign of the result in
addition to the size of the result. If the result of our operation generates an
incorrect sign, or does not fit in the container, we must flag the error, and
this is done using the **Overflow** flag.

Since the processor has no idea if the data is signed or unsigned, both flags
will be generated by an operation. It is up to the programmer to use the
correct flag to identify a problem with the result.

We need to figure out exactly how to determine these two flags.

Carry Flag
**********

The rules for turning on the carry flag are basically these:

1. If the addition of two unsigned numbers causes a carry out of the most
   significant (leftmost) bits added, the **Carry** flag will be set.
   Otherwise, it will be cleeared..

   As an example:

   11111111 + 00000001 = 00000000 (carry flag is set)

Detecting this in C++ for our simple machine is easily done by moving the
operands into larger containers, then checking that the final result does not
exceed the biggest number that can fit into the original container. (This can
be done by using hexadecimal literals like 0xff for an 8-bit container, or
0xffff for a 16-bit container to check the limits.


2. The carry (borrow) flag is also set if the subtraction of two numbers
   requires a borrow into the most significant (leftmost) bits subtracted.

   For example:

   000000 - 00000001 = 11111111 (carry flag is set)

How can we check this?

One way is to flip the second operand into a positive number (remember it is in
2's compliment form) and perform an addition instead. If the **Carry** gets
set, we had to borrow!

Overflow Flag
*************

There are two rules for detecting overflow in signed binary addition:

1. If adding two positive numbers generates a result that is
   negative, overflow occurred.
   
   For example:

   01000000 + 01000000 = 10000000 (**Overflow** is set)

2. If adding two negative numbers generates a result that is positive, overflow
   occurred.  ` For example: 

Testing for overflow
====================

Here are some code fragments that can be used to find out if overflow will
occur in signed addition and subtraction:

..  code-block:: c

    #include <limits.h>
    int a = ?;
    int b = ?;

    // addition
    if ((b > 0) && (a > INT_MAX - b)) /* `a + b` would overflow */;
    if ((b < 0) && (a < INT_MIN - b)) /* `a + b` would underflow */;

    // subtraction
    if ((b < 0) && (a > INT_MAX + b)) /* `a - b` would overflow */;
    if ((b > 0) && (a < INT_MIN + b)) /* `a - b` would underflow */;
