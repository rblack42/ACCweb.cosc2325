Building Blocks of Computing
############################

The mere thought of putting together a single system with over a billion parts
is scary, to say the least. But the actual design of a computer is not that
scary once you see the pattern that leads to a simpler system.

Basic Blocks
************

You might think that we need a fundamental component that knows math, so we can
add two numbers together. But do we really need to start with something like
that, or can we get an adding component another way.

Let's start with our four fundamental logical operations:

    * **AND**
    * **OR**
    * **XOR**
    * **NOT**

Although that **XOR** is not so common in your programming, it is useful, as we
shall see.

Digital Designers know how to wire up these "gates" as they are called, and we
can ignore the internal details. Here are the simple symbols we use to
represent these components in digital design. The "truth tables" after each
symbol shows how the component works:

AND
===

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (3,-0.5) {$C$};

    \node[and gate] at ($(a)+(1.5,-0.5)$)(and1) {};

    \draw (a.east) -- ++(right:3mm) |- (and1.input 1);
    \draw (b.east) -- ++(right:3mm) |- (and1.input 2); 
    \draw (and1.output) -- (out.west);

The **AND** truth table:


    +----------------+----------------+-----------------+
    | :math:`A_{in}` | :math:`B_{in}` | :math:`C_{out}` |
    +================+================+=================+
    | 0              | 0              | 0               |
    +----------------+----------------+-----------------+
    | 0              | 1              | 0               |
    +----------------+----------------+-----------------+
    | 1              | 0              | 0               |
    +----------------+----------------+-----------------+
    | 1              | 1              | 1               |
    +----------------+----------------+-----------------+

OR
==

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (3,-0.5) {$C$};

    \node[or gate] at ($(a)+(1.5,-0.5)$)(or1) {};

    \draw (a.east) -- ++(right:3mm) |- (or1.input 1);
    \draw (b.east) -- ++(right:3mm) |- (or1.input 2); 
    \draw (or1.output) -- (out.west);

The **OR** truth table:

    +----------------+----------------+-----------------+
    | :math:`A_{in}` | :math:`B_{in}` | :math:`C_{out}` |
    +================+================+=================+
    | 0              | 0              | 0               |
    +----------------+----------------+-----------------+
    | 0              | 1              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 0              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 1              | 1               |
    +----------------+----------------+-----------------+


XOR
===

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (3,-0.5) {$C$};

    \node[xor gate] at ($(a)+(1.5,-0.5)$)(xor1) {};

    \draw (a.east) -- ++(right:3mm) |- (xor1.input 1);
    \draw (b.east) -- ++(right:3mm) |- (xor1.input 2); 
    \draw (xor1.output) -- (out.west);

The **XOR** truth table:

    +----------------+----------------+-----------------+
    | :math:`A_{in}` | :math:`B_{in}` | :math:`C_{out}` |
    +================+================+=================+
    | 0              | 0              | 0               |
    +----------------+----------------+-----------------+
    | 0              | 1              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 0              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 1              | 0               |
    +----------------+----------------+-----------------+

NOT
===

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (a) at (0,0) {$A$};
    \node (out) at (3,-0) {$B$};

    \node[not gate] at ($(a)+(1.5,0)$)(not1) {};

    \draw (a.east) -- ++(right:3mm) |- (not1.input);
    \draw (not1.output) -- (out.west);

The **NOT** truth table:

    +----------------+-----------------+
    | :math:`A_{in}` | :math:`B_{out}` |
    +================+=================+
    | 0              | 1               |
    +----------------+-----------------+
    | 1              | 0               |
    +----------------+-----------------+

Remember, only one input here!

Too Many Gates!
***************

Well, each one of those gates is needed, but are they really the basic
components we need?

Let's do something simple. Take one **AND** gate and one **NOT** gate and wire
them up this way:

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (3.5,-0.5) {$C$};

    \node[and gate] at ($(a)+(1,-0.5)$)(and1) {};
    \node[not gate] at (2,-0.5)(not1) {};

    \draw (a.east) -- ++(right:2mm) |- (and1.input 1);
    \draw (b.east) -- ++(right:2mm) |- (and1.input 2); 
    \draw (and1.output) -- (not1.input);
    \draw (not1.output) -- (out.west);


All we are doing is flipping the output on the AND. We will call this a
"not-and", or NAND Gate. This one is pretty useful. Here is the symol we use
for this magic gate:

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (3,-0.5) {$C$};

    \node[nand gate] at ($(a)+(1.5,-0.5)$)(nand1) {};

    \draw (a.east) -- ++(right:3mm) |- (nand1.input 1);
    \draw (b.east) -- ++(right:3mm) |- (nand1.input 2); 
    \draw (nand1.output) -- (out.west);
    
The **NAND** truth table:


    +----------------+----------------+-----------------+
    | :math:`A_{in}` | :math:`B_{in}` | :math:`C_{out}` |
    +================+================+=================+
    | 0              | 0              | 1               |
    +----------------+----------------+-----------------+
    | 0              | 1              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 0              | 1               |
    +----------------+----------------+-----------------+
    | 1              | 1              | 0               |
    +----------------+----------------+-----------------+


WHy introduce this new gate? Well it turns out to be very useful, as we will see next. Le't revisit our fundamental gates, this time using the **nand** gate in interesting ways:

NOT
===

Watch this, it is pretty neat!

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (a) at (0,0) {$A$};
    \node (out) at (3,0) {$B$};

    \node[nand gate] at ($(a)+(1.5,0)$)(nand1) {};

    \draw (a.east) -- ++(right:4mm) |- (nand1.input 1);
    \draw (a.east) -- ++(right:4mm) |- (nand1.input 2); 
    \draw (nand1.output) -- (out.west);

Here, we wire up both inputs of the **NAND** gate to the same (single) input.
This turns the resulting circuit into a **NOT** gate. (Prove that to yourself
by examining the truth table.)

Now we can build our **AND** gate this way:

AND
===

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    \node (b) at (0,-1) {$B$};
    \node (a) at (0,0) {$A$};
    \node (out) at (4,-0.5) {$C$};

    \node[nand gate] at (1.5,-0.5) (nand1) {};
    \node [nand gate] at (3,-0.5) (nand2) {};

    \draw (a.east) -- ++(right:3mm) |- (nand1.input 1);
    \draw (b.east) -- ++(right:3mm) |- (nand1.input 2); 
    \draw (nand1.output) -- ++(right:2mm) |- (nand2.input 1);
    \draw (nand1.output) -- ++(right:2mm) |- (nand2.input 2);
    \draw (nand2.output) -- (out.west);

Yes, it took two **nand** gates to restore our original **and** gate.. However, we are just using one basic gate to build our needed standard gates.

OR
==

This one is a bit more comples. I will leave it to you to verify that this
circuit is equivalent to our original **or** gate:

..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc
 
    \node (a) at (0,-0.5) {$A$};
    \node (b) at (0,-1.5) {$B$};
    \node (out) at (4.5,-1) {$C$};

    \node [nand gate] at (1.5,-0.5) (nand1) {};
    \node [nand gate] at (1.5,-1.5) (nand2) {};
    \node [nand gate] at (3,-1) (nand3) {};

    \draw (a.east) -- ++(right:3.5mm) |- (nand1.input 1);
    \draw (a.east) -- ++(right:3.5mm) |- (nand1.input 2);
    \draw (b.east) -- ++(right:3.5mm) |- (nand2.input 1);
    \draw (b.east) -- ++(right:3.5mm) |- (nand2.input 2);
    \draw (nand1.output) -- ++(right:3mm) |- (nand3.input 1);
    \draw (nand2.output) -- ++(right:3mm) |- (nand3.input 2);
    \draw (nand3.output) -- (out.west);

XOR
===
..  circuits::
    :align: center
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc
 
    \node [nand gate] at (3,-0.5) (nand1) {};
    \node [nand gate] at (1.5,-1.5) (nand2) {};
    \node [nand gate] at (3,-2.5) (nand3) {};
    \node [nand gate] at (4.5,-1.5) (nand4) {};

    \node (a) at (0,-1) {$A$};
    \node (b) at (0,-2) {$B$};
    \node (out) at (5.5,-1.5) {$C$};

    \draw (a.east) -- ++(right:3.5mm) |- (nand2.input 1);
    \draw (b.east) -- ++(right:3.5mm) |- (nand2.input 2);
    \draw (nand2.output) -- ++(right:3.5mm) |- (nand1.input 2);
    \draw (nand2.output) -- ++(right:3.5mm) |- (nand3.input 1);
    \draw (nand1.output) -- ++(right:3.5mm) |- (nand4.input 1);
    \draw (nand3.output) -- ++(right:3.5mm) |- (nand4.input 2);
    \draw (a.east) -- ++(right:3.5mm) |- (nand1.input 1);
    \draw (b.east) -- ++(right:3.5mm) |- (nand3.input 2);
    \draw (nand4.output) -- (out.west);


OK, that last one is pretty complicated. The point is that we can build all the
other gates by using one basic building block. It turns out that we can build
just about any digital component we want using this one basic block. 

Now we have a basic component we can use!

..  vim:ft=rst spell:
