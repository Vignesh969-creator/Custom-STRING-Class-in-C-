# Custom STRING Class in C++

## Project Description

This project implements a custom `STRING` class in C++ using a **dynamically allocated character array**.

All class implementations, friend functions, and the test program are contained in a **single `main.cpp` file**.

The project does not use `std::string` or the corresponding standard string functions for implementing the required operations.

## Features

The `STRING` class supports:

* Default constructor
* Parameterized constructor
* Copy constructor
* Assignment operator
* Addition operator `+`
* Subscript operator `[]`
* Stream insertion operator `<<`
* Stream extraction operator `>>`
* Comparison operators: `==`, `!=`, `>`, `<`, `>=`, `<=`

### Friend String Functions

* `strcpy()`
* `strncpy()`
* `strcmp()`
* `strncmp()`
* `strcat()`
* `strncat()`
* `strrev()`
* `strupr()`
* `strlwr()`
* `strchr()`
* `strrchr()`
* `strstr()`
* `strlen()`

## Memory Management

The string data is stored in a dynamically allocated character array.

Deep copying is implemented using:

* Copy constructor
* Assignment operator

A destructor is implemented to release dynamically allocated memory.

## File Structure

```text
Custom-STRING/
│
├── main.cpp
└── README.md
```

## Example

```cpp
STRING s1("Hello");
STRING s2("World");

STRING s3 = s1 + s2;

cout << s3;
```

Output:

```text
HelloWorld
```

## Purpose

This project demonstrates:

* Dynamic memory allocation
* Constructors and destructors
* Deep copying
* Operator overloading
* Friend functions
* Character array manipulation
* Stream operator overloading
