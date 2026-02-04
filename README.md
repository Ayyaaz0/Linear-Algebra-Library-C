# Linear Algebra Utilities in C

A small C-based numerical tool implementing basic linear algebra routines.
The project contains a command line interface to demonstrate functionality. 

## Build Instructions

```bash
cmake -S . -B build
cmake --build build
./build/smt

## Features
-- Matrix operations --
Addition
Subtraction
Multiplication
Transpose
Determinant computation via Gaussian elimination with partial pivoting
Linear system solver for Ax=b
Inverse a matrix