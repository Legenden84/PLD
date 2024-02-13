(load listfunctions)

// ff function
(
  fun ff
    (head) (if (symbol? head) head (ff (#L head)))
    ((head . tail) (if (symbol? head) head (ff tail)))
)

(load listfunctions)

(
  fun xx (x) (if (symbol? x) x (throw x))
)

(
  catch (xx 2) (\ (e) ())
)

// test cases
(ff 'x)
(ff '(2 4 z 3))
(ff 7)
