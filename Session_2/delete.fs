| Cons (Symbol "let", Cons (e1, Nil)) -> eval e1 localEnv
| Cons (Symbol "let", Cons (p, Cons (e1, rest))) ->
  let v = eval e1 localEnv
  (match matchPattern p v with
    | None -> raise (Lerror ("The pattern "
                              + showSexpIndent p 12 12
                              + " did not match the value "
                              + showSexpIndent v 30 30))
    | Some env -> eval (Cons (Symbol "let", rest)) (env @ localEnv)