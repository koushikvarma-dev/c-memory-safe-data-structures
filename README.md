# C Memory-Safe Data Structures

A portfolio project demonstrating defensive C programming, dynamic memory management, pointers, ownership, cleanup, and reusable data-structure APIs.

> Portfolio project — created to demonstrate C programming and systems-level engineering skills.

## What is included

- Dynamic array with automatic growth
- Singly linked list
- Stack built on the dynamic array
- Queue built on a linked list
- Explicit allocation and cleanup paths
- Defensive checks for invalid arguments and allocation failures
- Unit-style tests
- AddressSanitizer and UndefinedBehaviorSanitizer build support

## Project structure

```text
.
├── include/
│   └── data_structures.h
├── src/
│   └── data_structures.c
├── tests/
│   └── test_data_structures.c
├── CMakeLists.txt
├── Makefile
├── .gitignore
└── README.md
```

## Build with Make

```bash
make
make test
```

Run the example/test executable:

```bash
./build/test_data_structures
```

Sanitizer build:

```bash
make sanitize
./build/test_data_structures
```

## Build with CMake

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Engineering focus

The implementation emphasizes clear ownership rules, predictable cleanup, capacity validation, integer-overflow-aware growth checks, and failure handling. C does not provide language-level memory safety, so this project demonstrates practical defensive techniques rather than claiming formal memory safety.

## Technologies

- C11
- GCC/Clang
- Make
- CMake
- AddressSanitizer
- UndefinedBehaviorSanitizer

## License

MIT
