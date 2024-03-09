node(sophia, node(hannah, leaf(2), leaf(3)), node(høst, leaf(1), leaf(nil))).

%is the structure a binary tree?
isBinaryTree(node(LABEL, L , R)) :- isBinaryTree(L),  isBinaryTree(R).
isBinaryTree(node(LABEL, leaf(L), leaf(R))).
isBinaryTree(leaf(LABEL)).

%IsLabel in tree?
isLabel(leaf(LABEL), KEY) :- LABEL==KEY. %needs more work
isLabel(node(LABEL, L, R), KEY) :- LABEL==KEY.
isLabel(node(LABEL, L, R), KEY) :- LABEL\=KEY, isLabel(L, KEY), isLabel(R, KEY).