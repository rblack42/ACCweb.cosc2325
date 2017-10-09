..  _combinational-gates:

Combinational Gates
###################

..  include::   /references.inc

The connection between Boolean Algebra and Digital Circuits can be seen in the
fundamental building blocks of modern computer systems.

These components all act immediately when the inputs change. They do not
generate an output immediately, but they are pretty quick. In most cases, we
can ignore the delay between the input change and appearance of the output
result.

What is extremely intestesting is that we can derive some simple basic digital
circuits directly from a Boolean expression!

Circuit Math
************

Here is a fairly simple *boolean expression*

..  math::

    z = (\overline{x_0} \cdot x_1 \cdot \overline{x_2}) + (\overline{x_0} \cdot x_1 \cdot x_2) \\
        + (x_0 \cdot \overline{x_1} \cdot \overline{x_2}) + (x_0 \cdot x_1 \cdot \overline{x_2})

And here is the moderately complex circuit that implements that formula.:

..  circuits::
    :align: center
    :width: 600
    :tikzopts: circuit logic US
    :tikzlibs: circuits.logic.US,calc

    % nodes
    \node (x0) at (1,0) {$x_0$};
    \node (x1) at (2,0) {$x_1$};
    \node (x2) at (3,0) {$x_2$};

    \node[not gate, rotate=-90] at ($(x0)+(0.5,-1)$) (Not0) {};
    \node[not gate, rotate=-90] at ($(x1)+(0.5,-1)$) (Not1) {};
    \node[not gate, rotate=-90] at ($(x2)+(0.5,-1)$) (Not2) {};

    \node[and gate, logic gate inputs=nnn] at ($(x2)+(3,-2)$) (And0) {};
    \node[and gate, logic gate inputs=nnn] at ($(And0)+(0,-1)$) (And1) {};
    \node[and gate, logic gate inputs=nnn] at ($(And1)+(0,-1)$) (And2) {};
    \node[and gate, logic gate inputs=nnn] at ($(And2)+(0,-1)$) (And3) {};
    \node[or gate, logic gate inputs=nnnn, anchor=input 1] at ($(And1.output -| And2.output)+(3,-0.25)$) (Or0) {};

     % draw nodes
    \foreach \i in {2,1,0} {
        \path (x\i) -- coordinate (punt\i) (x\i |- Not\i.input);
        \draw (punt\i) node[branch] {} -| (Not\i.input);
    }

    % direct inputs
    \draw (x0 |- And2.input 1) node[branch] {} -- (And2.input 1);
    \draw (x0) |- (And3.input 1);
    \draw (Not0.output |- And0.input 1) node[branch] {} -- (And0.input 1);
    \draw (Not0.output) |- (And1.input 1);
    
    \draw (x1 |- And0.input 2) node[branch] {} -- (And0.input 2);
    \draw (x1 |- And1.input 2) node[branch] {} -- (And1.input 2);
    \draw (x1) |- (And3.input 2);
    \draw (Not1.output) |- (And2.input 2);
    
    \draw (x2) |- (And1.input 3);
    \draw (Not2.output |- And0.input 3) node[branch] {} -- (And0.input 3);
    \draw (Not2.output |- And2.input 3) node[branch] {} -- (And2.input 3);
    \draw (Not2.output) |- (And3.input 3);
    
    % AND
    \draw (And0.output) -- ([xshift=0.8cm]And0.output) |- (Or0.input 1);
    \draw (And1.output) -- ([xshift=0.5cm]And1.output) |- (Or0.input 2);
    \draw (And2.output) -- ([xshift=0.5cm]And2.output) |- (Or0.input 3);
    \draw (And3.output) -- ([xshift=0.8cm]And3.output) |- (Or0.input 4);
    \draw (Or0.output) -- ([xshift=0.5cm]Or0.output) node[above] {$z$};

Phew!

From this circuit, you should be able to see how we can wire up our basic
components to make something useful happen in a real system. Let's try this out
using a component we really need to build a computer:

Multiplexors
************

Much of the design of a computer system involves routing signals, traveling
over wires between gates, to the right place at the right time. How do we
control where a signal goes?

A wire is a pathway for electrons to move along. Single wires are simple to
understand, but what if we want to control the destination?

The smallest routing component would have a two input lines and one output
lines. We want to control (select) which input line will pass on to the output
signal line. To do that, we need at least one addition input line. We will call
this a *control line*. 

If we need to select the signal from more than two different input lines, we will
need more control lines. If we use three control lines, we can select among
eight different input lines. Here is a diagram showhing an 8-way
*multiplexor*:

..  circuits::
    :align: center
    :width: 300
    :tikzlibs:  calc

    \draw (0,0)coordinate (O)--++(30:1)coordinate (A)--++(90:4)coordinate (B)--++(150:1)coordinate (C)--cycle;
    \draw ($(A)!0.5!(B)$)--++(0:1)node[right]{$F$};
    \draw ($(O)!0.5!(A)$)--++(-90:1)--++(180:2)node[left]{$b$};
    \draw ($(O)!0.25!(A)$)--++(-90:0.5)--++(180:1.75)node[left]{$a$};
    \draw ($(O)!0.75!(A)$)--++(-90:1.5)--++(180:2.25)node[left]{$c$};
    \foreach \y/\t in {0.1/1,0.2/2,0.3/3,0.4/4,0.5/5,0.6/6,0.7/7,0.8/8} {
    \draw ($(C)! \y*1.1 !(O)$)--++(180:1) node[left] {$X \t$};}

We will use these gadgets a lot in our simple system design work!

How do we construct such a gadget?

Boolean Expression
==================

Let's create a Boolean expression that describes how this component needs to
work. We have a set of eight input lines available that we need to route to the
output. Which line we select is defined by the three input lines. (I hope you
see why we need three control lines!)

Let's build a truth table for the component, just to see how it should work:


    +-----------+-----------+-----------+-------------+
    | :math:`a` | :math:`b` | :math:`c` | :math:`F`   |
    +===========+===========+===========+=============+
    | 0         | 0         | 0         | :math:`X_1` |
    +-----------+-----------+-----------+-------------+
    | 0         | 0         | 1         | :math:`X_2` |
    +-----------+-----------+-----------+-------------+
    | 0         | 1         | 0         | :math:`X_3` |
    +-----------+-----------+-----------+-------------+
    | 0         | 1         | 1         | :math:`X_4` |
    +-----------+-----------+-----------+-------------+
    | 1         | 0         | 0         | :math:`X_5` |
    +-----------+-----------+-----------+-------------+
    | 1         | 0         | 1         | :math:`X_6` |
    +-----------+-----------+-----------+-------------+
    | 1         | 1         | 0         | :math:`X_7` |
    +-----------+-----------+-----------+-------------+
    | 1         | 1         | 1         | :math:`X_8` |
    +-------------+---------+-----------+-------------+


From this table, we can see the expression we need:

..  math::

    F = (\overline{a} \cdot \overline{b} \cdot \overline{c} \cdot X_1) + \
        (\overline{a} \cdot \overline{b} \cdot c \cdot X_2) \\
        + (\overline{a} \cdot b \cdot \overline{c} \cdot x_3) + \
        (\overline{a} \cdot b \cdot c \cdot X_4) \\
        + ( a \cdot \overline{b} \cdot \overline{c} \cdot X_5) + \
        ( a \cdot \overline{b} \cdot c \cdot X_6) \\
        + ( a \cdot b \cdot \overline{c} \cdot x_7) + \
        ( a \cdot b \cdot c \cdot X_8)

From here, the circuit is fairly simple to construct. The previous example
should show you basically how to build this component. 

You should examine this expression and figure out how many **AND** gates and
**OR** gates you would need. Even better, how many **NAND** gates would be
needed?


Let's try something a bit more complicated.

Designing a Binary Adder
************************

Let's consider how we create a circuit that can add two binary digits. The
circuit we want to design needs two input bits and produces one output bit.
However, to be a general device we need to consider what to do if the result is
more than one bit big (does two come to mind?). In this case, we generate a
zero for the output, and let that extra bit be another output bit that will go
to the next stage in a higher level adder. We call this the *carry-out* bit.

Of course, as soon as we admit *carry-out*, we need to consider including that
in our addition as well. Now, we call this signal *carry-in*. 

So, in summary, we have a component that has three inputs and two outputs. We
need to define how it is to work, and a simple way to do that is to build a
simple truth table:

    +-------------+-------------+----------------+-----------+-----------------+
    | :math:`A`   | :math:`B`   | :math:`C_{in}` | :math:`R` | :math:`C_{out}` |
    +=============+=============+================+===========+=================+
    | 0           | 0           | 0              | 0         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 0           | 1              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 1           | 0              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 0           | 1           | 1              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 0           | 0              | 1         | 0               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 0           | 1              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 1           | 0              | 0         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+
    | 1           | 1           | 1              | 1         | 1               |
    +-------------+-------------+----------------+-----------+-----------------+

Generating the Expression
=========================

One scheme for generating the *Boolean Expression* for this table is called
*Sum of Products*. 

In this simple scheme, we look at each output column and generate an expression
for each result. We only look at those rows where the output is a "1". For
those rows, we form a "product" representing the entries in that row, then we
"sum" all such products for every row where there is a "1". Phew!

Let's make typing in these rules a bit easier by using simple names like A and
B for the inputs, C for :math:`C_{in}`, and O for :math:`C_{out}`. 

Our product term will use the column name directly if we see a "1" in the row,
and an inverted name (like :math:`\overline{A}`) if we see a "0". For the above
table, we end up with these two expressions:

..  math::

    R = \overline{A}*\overline{B}*C + \overline{A}*B*\overline{C} + A*\overline{B}*\overline{C} + A*B*C

Make sure you see how this was formed. It is pretty easy, once you get the hang
of the process!

..  math::

    O = \overline{A}B*C + A*\overline{B}*C + A*B*\overline{C} + A*B*C

Since this gives us two separate expressions, the final circuit is actually
two independent circuits joined together. The signals will flow into each
chunk, through the gates needed to generate the final output. The trick is to
see how this circuit comes together.

Obviously, we could generate the circuit directly from this pair of
expressions, We would have a TON of "AND" and "OR" gates to do this. Can we
simplify this expression before we shop for parts?

More XOR Rules
**************

Let's use this scheme to produce new rules involving the **XOR** operator. Here
is our *truth table* again:

..  csv-table::
    :widths: 10,10,10,10
    :header:  Op, A, B, Out

    **XOR**, 0, 0, 0
    , 0, 1, 1
    , 1, 0, 1
    , 1, 1, 0

According to our new technique, here is the *Boolean Expression* needed to
implement this table using only **AND** and **OR**:

..  math::

    Out = \overline{A}*B + A*\overline{B}

Or, put another way:

..  math::

    A - B = \overline{A}*B + A*\overline{B}

Let's generate one more rule: :math:`\overline{X - Y}`

Here is the truth table:

..  csv-table::
    :widths: 10,10,10,10
    :header:  Op, A, B, Out

    **NXOR**, 0, 0, 1
    , 0, 1, 0
    , 1, 0, 0
    , 1, 1, 1

Which gives this expression:

..  math::

    Out = \overline{X}*\overline{Y} + X*Y

Or:

..  math::

    \overline{X - Y} = \overline{X}*\overline{Y} + X*Y

Before we use these new rules to simplify the expressions we currently have,
let's summarize all of our Boolean rules:

Boolean Math Summary
********************

Here is a summary of all the rules of *Boolean Algebra* we need to do
simplification:

Identity Laws
=============

..  csv-table::

    X,:math:`\equiv`,X,(1)
    :math:`\overline{X}`,:math:`\equiv`,:math:`\overline{X}`,(2)

Commutative Laws
================

..  csv-table::

    X * Y, :math:`\equiv`,Y * X,(3)
    X + Y, :math:`\equiv`,Y + X,(4)

Associative Laws
================

..  csv-table::

    (X * Y) * Z, :math:`\equiv`,X * (Y * Z),(5)
    (X + Y) + Z, :math:`\equiv`,X + (Y + Z),(6)

Distributive Laws
=================

..  csv-table::

    (X + Y) * Z, :math:`\equiv`,(X * Z) + (Y * Z),(7)
    (X * Y) + Z, :math:`\equiv`,(X + Z) * (Y + Z),(8)


Idempotent Laws
===============

..  csv-table::

    X * X, :math:`\equiv`,X,(9)
    X + X, :math:`\equiv`,X,(10)

Double Negative Law
===================

..  csv-table::

    :math:`\overline{\overline{X}}`, :math:`\equiv`, X,(11)

Complementary Laws
==================

..  csv-table::

    :math:`X + \overline{X}`, :math:`\equiv`, 1, (12)
    :math:`X * \overline{X}`, :math:`\equiv`, 0, (13)

Intersection Laws
=================

..  csv-table::

    X * 0, :math:`\equiv`,0,(14)
    X * 1, :math:`\equiv`,X,(15)

Union Laws
==========

..  csv-table::

    X + 0, :math:`\equiv`,X,(16)
    X + 1, :math:`\equiv`,1,(17)

Demorgan's Theorem
==================

..  csv-table::

    :math:`\overline{X} * \overline{Y}`, :math:`\equiv`,:math:`\overline{X + Y}`,(18)
    :math:`\overline{X} + \overline{Y}`, :math:`\equiv`,:math:`\overline{X * Y}`,(19)


Absorption Laws
===============

..  csv-table::

    X * (X + Y), :math:`\equiv`, X, (20)
    X + (X*Y), :math:`\equiv`, X, (21)

XOR Laws
========

..  csv-table::

    (X - Y) - Z, :math:`\equiv`,X - (Y - Z),(22)
    X - 0, :math:`\equiv`,X,(6)
    X - 1, :math:`\equiv`,:math:`\overline{X}`,(23)
    X - X, :math:`\equiv`,0,(8)
    :math:`X - \overline{X}`, :math:`\equiv`,1,(24)
    X - Y, :math:`\equiv`,Y - X,(25)
    :math:`\overline{X - Y}`, :math:`\equiv`, :math:`\overline{X}\overline{Y} + XY`, (26)
    X - Y, :math:`\equiv`, :math:`\overline{X}Y + X\overline{Y}`,(27)

That is a fairly complete set of rules we can use to manipulate any *Boolean
expression* we run into something simpler. Learning how to do this takes
practice, the same way learning normal algebra took practice back when you did
that!

Simplifying the Adder Expressions
=================================

Let's work on the result part of the circuit and see what we get:

..  csv-table::

    :math:`R = \overline{A}*\overline{B}*C + \overline{A}*B*\overline{C} + A*\overline{B}*\overline{C} + A*B*C`,

    :math:`R = \overline{A}*(\overline{B}*C + B*\overline{C}) + A*(\overline{B}*\overline{C} + B*C)`,(7)

    :math:`R = \overline{A}*(B-C) + A * (\overline{B - C})`, (26-27)

    R = A - (B - C),(27)


The final expression for the carry out signal looks like this:

..  csv-table::

    :math:`O = \overline{A}B*C + A*\overline{B}*C + A*B*\overline{C} + A*B*C`,

    :math:`O = (\overline{A} + A)*B*C + A*(\overline{B}*C + B*\overline{C})`, (7)

    :math:`O = (\overline{A} + A)*B*C + (\overline{B} + B)*A*C + (\overline{C}+C)*A*B`,

    :math:`O = B*C + A*C + A*B`

Both of these expressions lead to a very simple circuit with far fewer
components than we would have used by just applying the original expressions!

To build a more complete adder, we need to chain together a number of these
simple adding circuits. There are tricks that can be used to speed up the
addition, but you see the basic idea here.

..  vim:ft=rst spell:

    
