open System

let concatenate ([<ParamArray>] args: string[]) =
    String.Concat(args)

let result = concatenate [| "Programming"; " "; "Language"; " "; "Design"; "!"; |]
printfn "%s" result
