# Question
Write a predicate squash that will eliminate consecutive duplicates of list elements.
If a list contains repeated elements they should be replaced with a single copy of the element. The
order of the elements should not be changed.
```
?− squash([a, a, a, a, b, c, c, a, a, d, e, e, e, e], X).
X = [a, b, c, a, d, e]
```
