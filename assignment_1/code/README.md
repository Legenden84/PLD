To run the lISP interpreter:

    dotnet fsi RunLISP.fsx

Now, inside the interpreter you can load functions from .le files:

    (load ff)

This loads functions inside ff.le and listfunctions.le simultaneously.

To test ff and ff_ex functions you can try the following inside the interpreter:

    (ff '(a b c))
    (ff 'a)

and

    (ff_ex 1)
    (ff_ex '(1 2 3 4 F P 9))
