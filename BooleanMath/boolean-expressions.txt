Boolean Functions
#################

Suppose you want to create a simple function that accepts Boolean parameters,
and returns a Boolean result. How might you do that?

Simple!

..  code-block::    c

    bool func(bool A, bool B) {
        return A & B;
    }

OK, so we can write a number of such functions and name then something other
than "func" so Guido does not get annoyed.

..  note::

    Why do that when you can simply use the Boolena operator & directly? Well,
    it turns out that the boolean operator actually invokes a Bloolean
    function, and you can write such functions yourself to overload the "&"
    opertor so it works with your own data types.


