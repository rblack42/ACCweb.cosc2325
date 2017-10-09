Deconstruct the Problem Statement
*********************************

1.  Build a C++ class that models a memory module. 

2.  The actual memory is an array of bytes (unsigned 8-bit integers). 

3.  THe memory array must be allocated dynamically.

4.  The address we will use in this module is an unsigned integer used directly
    as the index into the memory array. 

5.  The module needs to support a **read** and **write** operation. 

6.  All data and address information needed in these operations must be passed
    through the parameter list for the methods created. 

7.  The *write* operation will provide a data item to store and an address
    where the data item is to be saved.  

8.  We will allow the following types of data to be stored in memory:

    * unsigned 8-bit integers
    
    * unsigned 16-bit integers
    
9. The *read* operation needs an address and an integer indicating how big an
    item to read from that address (see above). 

10. The **read** operation does not return the data directly. 

11. Instead, a separate method will  be used to return the value. 

12. Call that method **read_valid**. 

13. Its operation is defined next.

14. The memory module has an interesting feature. 

15. It takes time to complete the required operations.  

16. The user will define two constants to model this time: one for *read*
    operations, and one for *write* operations.  

17. These constants will be set when a memory object is created from this
    class. 

18. Both **read** and **write** return no value (void).

19. Following a call to either **read** or ** write** the user must call a
    boolean method named **ready** which indicates that the previous operation
    has finished. 

20. The user will need to call this method repeatedly until it returns
    **true**. 

21. Only then can another memory operation be attempted.
 
22. For the read** operation, the actual data can be retrieved (after **ready**
    returns **true**) by calling a function named **read_valid**. 

23. This method always returns a 64-bit unsigned integer, but the returned data
    will be the size indicated on the previous **read**. 

24. If **read_valid** is called before **ready** returns **true** the value
    returned is always zero (which is not really valid)

