..  _building-components:

Building Components
###################

In most classes, you build a complete application for your projects. This one
is a bit different, and actually is more like what you will run into in "real
life" programming.

Seldom, if ever, will you be creating a complete application. You will be part
of a large team, with many programmers contributing to the final product. You
will be handed some part of that project to work on. Perhaps it will be a
simple function, or a class. You never quite know what you will be asked to
create. 

..  note::

    As a matter of fact, you might not get to work on your part alone. Today,
    working inpairs is very common. The theory is that two sets of eyes will
    spot problems faster than one!


In this class your first few lab tasks will be to create a single class that
implements a simulation of some part of a real computer. There is no
application to plug this class into at present, so you need to deal with how to
make sure that your class functions properly. That is where testing comes into
play.

In order to make sure your class works properly, you need to create test cases
where you create an object from your class, then run it through its paces. You
need to exercise every method set up for that class, and check all the results
delivered by the class as you do this. A proper set of tests will wring out
every line in your class implementation. In fact, there are tools to verify
that every line has been exercised. A simple saying explains this:

If you have not tested it, it does not work!

(Prove me wrong by writing a test!)

The First Lab
*************

The Memory Unit is nothing more than a simple array of bytes, but it acts
differently from other arrays you have used. It can be busy when you try to
access it, and it will not respond until it is darned good and ready. In fact,
as a user of this module, it is up to you to see if it is ready by testing that
"ready" function before you try to access it. If you just go ahead and try to
access the memory object while it is busy, something should happen. We have not
defined that yet, but it might involve raising an exception. Since that may
involve features of C++ you have not seen yet, we will avoid that idea for now.
Instead, just return. If you combine the concept of taking small steps toward
a solution and add to that the idea that you should know exactly how your code
will act , both with good behavior (parameters) and bad, then you can set out
to write a few tests to verify that your code does just that.

Don't get carried away with this, the tests can be simple. In fact, they can be
stupidly simple as you get into this. Start off by just creating an object from
your class. Add a test that verifies that it actually exist. If you initialized
data in that object, does it show those values. Add methods to check if needed,
then run tests to confirm that things are working. As you move to more complex
actions (your real methods) add tests that check for good behavior, then see
what happens when you add bad data. 

..  note::

    Hmmm, can the data you hand to the memory unit ever be "bad". Perhaps not.
    The memory unit only works with simple data. The header specifies that all
    data gets sent to the memory as 16-bit values, and the size parameter tells
    the memory unit if it needs to store a byte or all 16 bits. It is hard to
    see that can fail.
    

I am working on a set of tests for the memory unit, and will post them in the
example project before our next class. Look them over and see how they line up
with your own thinking about this. 
