# bigint
Arbitrary precision integers for dynamic language runtimes

## Motivation
As a dynamic language implementer, what I want from an integer type is:
- Clearly gets the numerical operations right
- Fits with the rest of the language implementation
- Doesn't pick up quirks of floating point when numbers get large
- Larger than machine word size. Ideally could fill the address space
- Easy to add to an existing language implementation

There are excellent libraries available for arbitrary precision integers. Some are assembly implementations with correctness proofs. Others are portable C that has been hammered on for years. Some have books describing their implementation details. The interfaces can be large and flexible.

This constitutes something of an impedance mismatch. I suspect there are multiple language implementations out there using int64_t with errors on overflow as an "unbounded" integer type, with a todo in the code to work out how to use one of the real numerical libraries later.


## How to use
Define a type to hold an integer. This can be very simple or intricately woven into a garbage collector. Define a small number of functions describing how to allocate memory for it and similar.

This library then instantiates:
- A header listing all the functions now available for use on that type
- Implementations of those functions in terms of one of the underlying libraries
- Unit tests running through those same declarations to check the plumbing works
- Also unit tests that check the arithmetic is correct

The details of that are slightly unclear while writing this initial readme. It's largely a code generation problem which are prone to horrendous user interfaces.

## Layout
Source layout as of current alpha / experimental state.
Just enough code in place to create a arbitrary precision integer calculator, reads stdin.

proto* at the top level is the work in progress hack iterating on this idea
fetch/ is created by `make fetch` and contains some third party code, notably libtommath
vendor/ is derived from fetch/
replacements/ is part of how vendor/ is put together

Two subdirectories supporting the calculator, largely derived from code generators similar to those under github.com/jonchesterfield/xml
demolang/* is a lexer and parser for a prefix calculator
tools/* is some ad hoc C used by demolang
