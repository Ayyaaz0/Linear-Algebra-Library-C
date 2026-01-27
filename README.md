# Linear Algebra Utilities in C

A small C-based numerical tool implementing basic linear algebra routines.
The project is structured to separate numerical computation, input handling,
and program control flow.

## Build Instructions

The project uses an out-of-source CMake build.

```bash
cmake -S . -B build
cmake --build build
./build/smt
