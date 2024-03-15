To run the prolog code in A3_3 make sure to have prolog installed.

Then run the following command in terminal:

    swipl A3_3.pl

You can do some tests to check if a structure is e.g. a binary tree by running the following in the console:

    isBinaryTree(node(tobias, leaf(elsker), leaf(pld))).

or:

    isBinaryTree(leaf(pld)).

You can search through a tree to see if a given input label is in the tree:

    isLabelInTree(node(tobias, leaf(elsker), leaf(pld)), pld).

or:

    isLabelInTree(node(tobias, leaf(elsker), leaf(pld)), xxx).

To quit prolog console write:

    halt .