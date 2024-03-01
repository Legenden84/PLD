To run the garbage collector defined in gc1.c follow these steps:

step 1) compile the c program using gcc:

    gcc -o gc1 gc1.c

step 2) - run the program in the terminal:

    ./gc1

or run the following command, in order to only see the number of garbage collections done before allocation fails:

    ./gc1 | grep sweep


NOTE: program when compiled produces 3 warnings, these are also in the original program gc.c.
