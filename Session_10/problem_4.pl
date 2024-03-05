% Write a predicate squash that will eliminate consecutive duplicates of list elements.
% If a list contains repeated elements they should be replaced with a single copy of the element. The
% order of the elements should not be changed.

% ?- squash([a, a, a, a, b, c, c, a, a, d, e, e, e, e], X).
% X = [a, b, c, a, d, e]

% Base case: An empty list is squashed to an empty list.
squash([], []).

% Case for a single element or the end of a list: A list with a single element squashes to itself.
squash([X], [X]).

% Recursive case: If the head is the same as the next element, skip the head and continue squashing.
squash([X, X | Tail], Squashed) :- squash([X | Tail], Squashed).

% Recursive case: If the head is different from the next element, include the head in the squashed list.
squash([X, Y | Tail], [X | Squashed]) :- X \= Y, squash([Y | Tail], Squashed).
