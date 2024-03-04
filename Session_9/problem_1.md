# Question
Find a programming language that allows nested modules, and show an example of a
declaration of a nested module in this language.

## Answer
C# is such a language. The example below utilizes namespace, class, methods.
Note that the below is example is not nested modules (namespace) to do this we
must nest this namespace into another namespace.

```c#
namespace SampleNamespace {
    class SampleClass {
        public void SampleMethod() {
            System.Console.WriteLine(
                "SampleMethod inside SampleNamespace");
        }
    }
}
```
