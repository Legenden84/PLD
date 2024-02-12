(load listfunctions)

// ff function
(
  fun ff
    (head) (if (symbol? head) head (ff (#L head))) 
    ((head . tail) (if (symbol? head) head (ff tail)))
)

// test cases
(ff 'x)
(ff (2 . (3 . ())))
(ff '(x . (y . (z . ()))))

(
  fun raiseException (x) (throw 'exception)
)

(
  catch
    (raiseException)
    (\ (e) 'ExceptionCaught)
)

(
  catch
    (xx
      (x) (if (symbol? x)) x (throw 'error)
    )
)

(
  fun xx (x) ((if (symbol? x)) x (throw 'error))
)

(
  catch
    (xx 2)
)
