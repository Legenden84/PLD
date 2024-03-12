%is the structure a binary tree?
isBinaryTree(leaf(_)).
isBinaryTree(node(_, leaf(_), leaf(_))).
isBinaryTree(node(_, L , R)) :- isBinaryTree(L),  isBinaryTree(R).

%IsLabel in tree?
isLabelInTree(leaf(LABEL), LABEL).
isLabelInTree(node(LABEL, _, _), LABEL).
isLabelInTree(node(LABEL, L, R), KEY) :- LABEL\=KEY, isLabelInTree(L, KEY); isLabelInTree(R, KEY).
