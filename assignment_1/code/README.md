To run the LISP interpreter:
```
dotnet fsi RunLISP.fsx
```
Now, inside the interpreter you can load functions from .le files:
```
(load ff)
```
This loads functions inside ff.le and listfunctions.le simultaneously.

To test ff and ff_ex functions you can try the following inside the interpreter:

```
(ff 'x)
(ff '(x . (y . ())))
(ff '(x . (y . (z . ()))))
```
and
```
(ff_ex 7)
(ff_ex '(2 4 z 3))
(ff_ex '(2 3 4))
```