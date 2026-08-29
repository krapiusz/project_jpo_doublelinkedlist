# Doubly Linked List

A doubly linked list implemented in C++, in two variants. University project (JPO course),
AGH University of Kraków.

Namespace: `pk::jpo`

## Variants

**`DLL_doxygen.hpp`** — basic version, stores `int` values. Fully documented with Doxygen
comments.

**`DLL_template.hpp`** — templated version, `DoublyLinkedList<T>` works with any type
(tested with `int`, `double` and `std::string`).

Both are header-only — just `#include` them, nothing to link.

## API

| Method | Description |
|---|---|
| `push_front(v)` | insert an element at the front |
| `push_back(v)` | insert an element at the back |
| `pop_front()` | remove the first element |
| `pop_back()` | remove the last element |
| `clear()` | remove all elements |
| `empty()` | returns `true` if the list holds no elements |
| `print_forward()` | print the list from head to tail |
| `print_backward()` | print the list from tail to head |

`pop_front()` and `pop_back()` do nothing on an empty list. The destructor frees all
allocated memory.

## Building

```bash
g++ -std=c++17 main.cpp -o dll
./dll
```

C++17 is required for the nested `pk::jpo` namespace.

## Structure

```
.
├── DLL_doxygen.hpp     int version with Doxygen documentation
├── DLL_template.hpp    templated version
├── main.cpp            tests for the int version
└── main_template.cpp   tests for the templated version (int, double, string)
```

## Documentation

Generate HTML documentation from the Doxygen comments:

```bash
doxygen -g
doxygen Doxyfile
```
