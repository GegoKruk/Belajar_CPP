# 📚 KURIKULUM LENGKAP C++ - BEGINNER TO EXPERT

## 🎯 Struktur Folder Project
```
lat-full/
├── lat-dasar.cpp          # Fundamental C++
├── lat-intermediate.cpp   # Intermediate Topics
├── lat-oop.cpp           # Object-Oriented Programming
├── lat-advanced.cpp      # Advanced C++ Features
├── lat-stl.cpp           # Standard Template Library
├── lat-expert.cpp        # Expert Level & Modern C++
└── projects/             # Mini Projects per Level
```

---

## 📘 MODUL 1: FUNDAMENTAL C++ (`lat-dasar.cpp`)
**Target**: Menguasai dasar-dasar pemrograman C++ dan logika fundamental

### **Chapter 1: Getting Started**
#### 1.1 Program Pertama ✅
- Pengertian program C++
- Struktur dasar program (main function)
- Header files (`#include`)
- Namespace (`using namespace std`)
- Compile dan run program
- **Contoh**: Hello World program

#### 1.2 Komentar
- Single-line comments (`//`)
- Multi-line comments (`/* */`)
- Best practices untuk komentar
- Documentation comments

---

### **Chapter 2: Variabel & Tipe Data**
#### 2.1 Variabel ✅
- Pengertian variabel
- Deklarasi dan inisialisasi
- Aturan penamaan variabel
- Naming conventions (camelCase, snake_case)
- Scope variabel (local, global)

#### 2.2 Tipe Data Primitif ✅
- `int` - Bilangan bulat
- `float` - Bilangan desimal
- `double` - Desimal presisi tinggi
- `char` - Karakter tunggal
- `bool` - Boolean (true/false)
- `string` - Teks (butuh `#include <string>`)

#### 2.3 Tipe Data Modifier ✅
- `short`, `long`, `long long`
- `unsigned` (tanpa negatif)
- `signed` (dengan negatif)
- Size of data types (`sizeof()`)

#### 2.4 Const & Constexpr ✅
- Konstanta dengan `const`
- Compile-time constants dengan `constexpr`
- `#define` preprocessor (old style)
- Kapan pakai const vs constexpr

#### 2.5 Type Conversion ✅
- Implicit conversion (automatic)
- Explicit conversion (casting)
  - C style cast: `(int)x`
  - C++ style cast: `static_cast<int>(x)`
- Narrowing conversion warning

---

### **Chapter 3: Input & Output**
#### 3.1 Output (`cout`) ✅
- Menggunakan `cout` dan `<<`
- Multiple output dengan chaining
- `endl` vs `\n`
- Output formatting

#### 3.2 Input (`cin`) ✅
- Menggunakan `cin` dan `>>`
- Multiple input dengan chaining
- Masalah dengan input yang ada spasi
- Buffer clearing dengan `cin.ignore()`

#### 3.3 String Input ✅
- `getline()` untuk input kalimat lengkap
- Kapan pakai `cin` vs `getline()`
- Kombinasi `cin` dan `getline()` dengan `cin.ignore()`

#### 3.4 Escape Sequences ✅
- `\n` - Newline
- `\t` - Tab
- `\\` - Backslash
- `\"` - Quote ganda
- `\'` - Quote tunggal
- `\a` - Alert/Bell
- Dan lainnya

---

### **Chapter 4: Operator**
#### 4.1 Operator Aritmatika ✅
- `+` Penjumlahan
- `-` Pengurangan
- `*` Perkalian
- `/` Pembagian (integer vs float division)
- `%` Modulus (sisa bagi)
- Order of operations (PEMDAS)

#### 4.2 Operator Penugasan ✅
- `=` Assignment
- `+=`, `-=`, `*=`, `/=`, `%=`
- Compound assignment operators

#### 4.3 Operator Increment & Decrement ✅
- `++` Increment (pre dan post)
- `--` Decrement (pre dan post)
- Perbedaan `i++` vs `++i`
- Common mistakes dan debugging

#### 4.4 Operator Perbandingan ✅
- `==` Sama dengan
- `!=` Tidak sama dengan
- `>` Lebih besar
- `<` Lebih kecil
- `>=` Lebih besar atau sama dengan
- `<=` Lebih kecil atau sama dengan

#### 4.5 Operator Logika ✅
- `&&` AND
- `||` OR
- `!` NOT
- Truth tables
- Short-circuit evaluation

#### 4.6 Operator Ternary ✅
- Syntax: `condition ? true_value : false_value`
- Kapan pakai ternary vs if-else
- Nested ternary (hati-hati!)

#### 4.7 Operator Bitwise
- `&` AND bitwise
- `|` OR bitwise
- `^` XOR bitwise
- `~` NOT bitwise
- `<<` Left shift
- `>>` Right shift
- Penggunaan praktis

---

### **Chapter 5: Control Flow - Percabangan**
#### 5.1 If Statement ✅
- Basic if
- if-else
- else-if ladder
- Best practices

#### 5.2 Nested If ✅
- If di dalam if
- Multiple conditions
- Avoiding deep nesting

#### 5.3 Switch-Case ✅
- Syntax switch-case
- Break statement
- Default case
- Fall-through behavior
- Kapan pakai switch vs if-else

#### 5.4 Conditional Operator Review
- Kombinasi dengan logical operators
- Complex conditions
- De Morgan's Law

---

### **Chapter 6: Control Flow - Perulangan**
#### 6.1 For Loop ✅
- Basic for loop
- Multiple initialization & update
- Infinite loop dengan for
- Nested for loops

#### 6.2 While Loop ✅
- Basic while loop
- Kondisi di awal
- Infinite loop dengan while
- Loop counter pattern

#### 6.3 Do-While Loop ✅
- Eksekusi minimal sekali
- Perbedaan dengan while
- Use cases (menu, input validation)

#### 6.4 Loop Control
- `break` - Keluar dari loop
- `continue` - Skip ke iterasi berikutnya
- `goto` (AVOID!)
- Best practices

#### 6.5 Nested Loops
- Loop di dalam loop
- Pattern printing (segitiga, diamond, dll)
- Performance considerations

---

### **Chapter 7: Functions (Basic)**
#### 7.1 Pengenalan Function
- Apa itu function
- Kenapa pakai function (reusability, modularity)
- Function declaration vs definition
- Function call

#### 7.2 Function Parameters
- Pass by value
- Multiple parameters
- Default parameters
- Parameter order

#### 7.3 Return Values
- Return statement
- Return types
- Void functions
- Multiple returns dalam satu function

#### 7.4 Function Overloading
- Same name, different parameters
- Compiler resolution
- Ambiguous calls

#### 7.5 Inline Functions
- `inline` keyword
- Kapan pakai inline
- Pros and cons

---

### **Chapter 8: Arrays (C-Style)**
#### 8.1 Array Dasar
- Deklarasi dan inisialisasi
- Indexing (mulai dari 0)
- Size array
- Accessing elements

#### 8.2 Array Operations
- Traversing dengan loop
- Finding min/max
- Sum dan average
- Searching (linear search)

#### 8.3 Multidimensional Arrays
- 2D arrays (matrix)
- Declaration dan initialization
- Nested loops untuk akses
- 3D arrays (optional)

#### 8.4 Array dan Function
- Passing array ke function
- Array decay to pointer
- Size information loss

#### 8.5 Common Array Problems
- Out of bounds access
- Array copy issues
- String as character array (`char[]`)

---

### **Chapter 9: Strings**
#### 9.1 C-Style Strings
- Character arrays
- Null terminator `\0`
- String functions (`strlen`, `strcpy`, dll)
- Problems dengan C-strings

#### 9.2 C++ String Class
- `#include <string>`
- String operations
  - Concatenation (`+`)
  - Comparison (`==`, `<`, dll)
  - Length (`length()`, `size()`)
  - Accessing characters (`[]`, `at()`)
- String methods
  - `substr()`
  - `find()`
  - `replace()`
  - `insert()`
  - `erase()`

#### 9.3 String Input/Output
- `cin` vs `getline()`
- String formatting
- String to number conversion
  - `stoi()`, `stof()`, `stod()`
- Number to string
  - `to_string()`

---

### **Chapter 10: Pointers (Introduction)**
#### 10.1 Memory & Addresses
- Computer memory basics
- Stack vs Heap
- Memory addresses
- `&` address-of operator

#### 10.2 Pointer Basics
- Pointer declaration
- Pointer initialization
- Dereferencing (`*`)
- Null pointers (`nullptr`)

#### 10.3 Pointer Arithmetic
- Increment/decrement
- Adding/subtracting integers
- Pointer comparison

#### 10.4 Pointers & Arrays
- Array name as pointer
- Pointer indexing
- Pointer vs array notation

---

### **Chapter 11: References**
#### 11.1 Reference Basics
- Apa itu reference
- Declaration syntax
- Difference: pointer vs reference
- Reference must be initialized

#### 11.2 Pass by Reference
- Modifying arguments
- Avoiding copy overhead
- `const` references

#### 11.3 Reference vs Pointer
- Kapan pakai reference
- Kapan pakai pointer
- Best practices

---

### **Chapter 12: Structs**
#### 12.1 Struct Basics
- Pengertian struct
- Member variables
- Accessing members (`.` operator)
- Initialization

#### 12.2 Struct Operations
- Passing to functions
- Returning structs
- Array of structs
- Nested structs

#### 12.3 Struct vs Class (Preview)
- Default access (public vs private)
- When to use struct

---

### **Chapter 13: Enumerations**
#### 13.1 Enum (Unscoped)
- Basic enum
- Enum values
- Implicit conversion to int

#### 13.2 Enum Class (Scoped)
- `enum class`
- Strongly typed
- No implicit conversion
- Best practices

---

### **Chapter 14: File I/O (Basic)**
#### 14.1 Reading Files
- `#include <fstream>`
- `ifstream`
- Opening dan closing files
- Reading line by line
- Checking file open success

#### 14.2 Writing Files
- `ofstream`
- Writing text
- Append mode
- Overwrite mode

#### 14.3 File Streams
- `fstream` (read & write)
- File positions
- Binary files (intro)

---

### **Chapter 15: Exception Handling (Basic)**
#### 15.1 Try-Catch
- `try` block
- `catch` block
- Exception types

#### 15.2 Throw
- `throw` keyword
- Custom error messages
- When to throw exceptions

---

### **Chapter 16: Preprocessor**
#### 16.1 Preprocessor Directives
- `#include`
- `#define` (macros)
- `#ifdef`, `#ifndef`
- `#pragma once`
- Include guards

#### 16.2 Conditional Compilation
- Debug vs Release
- Platform-specific code

---

### **📝 LATIHAN MODUL 1**
1. **Calculator Program**: Buat kalkulator dengan menu (tambah, kurang, kali, bagi)
2. **Grade Calculator**: Input nilai, hitung rata-rata, tentukan grade
3. **ATM Simulation**: Menu withdrawal, deposit, check balance
4. **Pattern Printing**: Buat berbagai pattern dengan nested loops
5. **Array Statistics**: Min, max, average, sorting sederhana
6. **Text Processor**: Count words, characters, reverse string
7. **Simple Database**: Array of structs untuk menyimpan data mahasiswa
8. **File Reader**: Baca file dan tampilkan isinya
9. **Number Guessing Game**: Dengan validasi input
10. **Mini Project**: Sistem perpustakaan sederhana (array + struct + file)

---

## 📗 MODUL 2: INTERMEDIATE C++ (`lat-intermediate.cpp`)
**Target**: Menguasai konsep menengah dan best practices

### **Chapter 17: Advanced Functions**
#### 17.1 Function Templates
- Template basics
- Type parameters
- Template instantiation
- Constraints (C++20 concepts preview)

#### 17.2 Lambda Functions
- Lambda syntax
- Capture clauses `[]`
- Use cases
- Lambda vs regular functions

#### 17.3 Function Pointers
- Pointer to function
- Callback functions
- Function pointers vs lambdas

#### 17.4 Recursion
- Base case & recursive case
- Stack overflow
- Tail recursion
- Recursion vs iteration

---

### **Chapter 18: Dynamic Memory**
#### 18.1 New & Delete
- `new` operator
- `delete` operator
- Memory leaks
- Dangling pointers

#### 18.2 Dynamic Arrays
- `new[]` dan `delete[]`
- 2D dynamic arrays
- Resizing arrays

#### 18.3 Memory Management Best Practices
- RAII principle
- Avoiding leaks
- Valgrind/memory checkers

---

### **Chapter 19: Advanced Pointers**
#### 19.1 Pointer to Pointer
- Double pointers `**`
- Use cases
- Complex data structures

#### 19.2 Function Pointers (Advanced)
- Arrays of function pointers
- Typedef for clarity
- Modern alternatives

#### 19.3 This Pointer (Preview)
- Introduction untuk OOP

---

### **Chapter 20: Namespace**
#### 20.1 Creating Namespaces
- Namespace declaration
- Nested namespaces
- `using` directive

#### 20.2 Namespace Best Practices
- Avoiding `using namespace std` in headers
- Anonymous namespaces
- Namespace aliases

---

### **Chapter 21: Header Files & Multiple Files**
#### 21.1 Header Files
- `.h` vs `.cpp`
- Header guards
- `#pragma once`
- Forward declarations

#### 21.2 Separate Compilation
- Multiple source files
- Linking
- Compilation units
- Build systems (Make, CMake intro)

---

### **Chapter 22: Advanced Data Structures**
#### 22.1 Linked Lists
- Singly linked list
- Doubly linked list
- Implementation from scratch
- Operations (insert, delete, search)

#### 22.2 Stacks
- LIFO principle
- Array-based vs linked-list-based
- Operations (push, pop, peek)
- Applications

#### 22.3 Queues
- FIFO principle
- Array-based vs linked-list-based
- Circular queue
- Priority queue (intro)

#### 22.4 Trees (Basic)
- Binary trees
- Binary search trees
- Tree traversals (inorder, preorder, postorder)

---

### **Chapter 23: Algorithms**
#### 23.1 Sorting Algorithms
- Bubble sort
- Selection sort
- Insertion sort
- Quick sort
- Merge sort
- Time complexity basics

#### 23.2 Searching Algorithms
- Linear search
- Binary search
- Interpolation search

#### 23.3 Common Algorithms
- Find min/max
- Reverse array
- Rotate array
- Palindrome check

---

### **Chapter 24: String Algorithms**
#### 24.1 String Manipulation
- Pattern matching
- String parsing
- Tokenization
- Regular expressions (basic intro)

---

### **📝 LATIHAN MODUL 2**
1. **Recursive Functions**: Factorial, Fibonacci, Tower of Hanoi
2. **Dynamic Array Manager**: Create, resize, delete arrays
3. **Linked List Implementation**: Complete CRUD operations
4. **Custom Stack & Queue**: Implement from scratch
5. **Sorting Visualizer**: Implement dan compare sorting algorithms
6. **Binary Search Tree**: Implementation dengan semua operations
7. **Text Editor**: Simple text editor dengan undo/redo (stack)
8. **Expression Evaluator**: Evaluate mathematical expressions
9. **Memory Manager**: Track allocations dan deallocations
10. **Mini Project**: Student Management System (multi-file, dynamic memory)

---

## 📙 MODUL 3: OBJECT-ORIENTED PROGRAMMING (`lat-oop.cpp`)
**Target**: Menguasai paradigma OOP secara mendalam

### **Chapter 25: Classes & Objects**
#### 25.1 Introduction to OOP
- Apa itu OOP
- OOP vs Procedural
- Advantages of OOP
- OOP Principles overview

#### 25.2 Classes & Objects
- Class definition
- Object creation
- Member variables (attributes)
- Member functions (methods)
- `this` pointer

#### 25.3 Access Specifiers
- `private`
- `public`
- `protected`
- Encapsulation principle

#### 25.4 Constructors
- Default constructor
- Parameterized constructor
- Constructor overloading
- Member initializer list
- Delegating constructors

#### 25.5 Destructors
- Destructor syntax
- When destructors are called
- Resource cleanup
- RAII pattern

---

### **Chapter 26: Encapsulation**
#### 26.1 Getters & Setters
- Accessor methods
- Mutator methods
- Validation in setters
- Read-only properties

#### 26.2 Friend Functions & Classes
- `friend` keyword
- When to use friends
- Pros and cons

#### 26.3 Static Members
- Static variables
- Static functions
- Class-level data
- Singleton pattern (intro)

#### 26.4 Const Members
- Const member functions
- Const objects
- Mutable keyword

---

### **Chapter 27: Inheritance**
#### 27.1 Basic Inheritance
- Parent-child relationship
- `class Derived : public Base`
- Access control in inheritance
- Constructor chaining

#### 27.2 Types of Inheritance
- Single inheritance
- Multiple inheritance
- Multilevel inheritance
- Hierarchical inheritance
- Hybrid inheritance

#### 27.3 Protected Access
- When to use protected
- vs private and public

#### 27.4 Inheritance & Constructors
- Base class constructor calls
- Initialization order
- Copy constructors in inheritance

---

### **Chapter 28: Polymorphism**
#### 28.1 Function Overloading (Review)
- Compile-time polymorphism
- Operator overloading preview

#### 28.2 Virtual Functions
- `virtual` keyword
- Dynamic dispatch
- Virtual table (vtable)
- Pure virtual functions

#### 28.3 Abstract Classes
- Abstract base classes
- Interface pattern
- When to use abstract classes

#### 28.4 Override & Final
- `override` keyword (C++11)
- `final` keyword
- Best practices

---

### **Chapter 29: Operator Overloading**
#### 29.1 Overloading Basics
- Why overload operators
- Syntax
- Member vs non-member

#### 29.2 Common Operators
- Arithmetic operators (`+`, `-`, `*`, `/`)
- Comparison operators (`==`, `<`, etc)
- Assignment operator (`=`)
- Compound assignment (`+=`, etc)

#### 29.3 Stream Operators
- `<<` untuk output
- `>>` untuk input
- Friend functions untuk streaming

#### 29.4 Subscript & Function Call
- `operator[]`
- `operator()`

#### 29.5 Increment & Decrement
- Pre-increment (`++x`)
- Post-increment (`x++`)
- Return types

---

### **Chapter 30: Composition & Aggregation**
#### 30.1 Composition (Has-A)
- Strong ownership
- Object lifetime
- Example: Car has Engine

#### 30.2 Aggregation (Has-A)
- Weak ownership
- Shared objects
- Example: Department has Teachers

#### 30.3 Composition vs Inheritance
- When to use which
- Favor composition over inheritance

---

### **Chapter 31: Copy Control**
#### 31.1 Copy Constructor
- Deep copy vs shallow copy
- Rule of Three
- Copy constructor syntax

#### 31.2 Copy Assignment Operator
- `operator=`
- Self-assignment check
- Return reference to `*this`

#### 31.3 Rule of Five (C++11)
- Move constructor
- Move assignment
- When needed

---

### **Chapter 32: Advanced OOP**
#### 32.1 Multiple Inheritance
- Diamond problem
- Virtual inheritance
- When to avoid

#### 32.2 Virtual Destructors
- Why needed
- Memory leaks without virtual destructor

#### 32.3 Object Slicing
- What is it
- How to avoid

---

### **📝 LATIHAN MODUL 3**
1. **Bank Account System**: Class hierarchy (Account, Savings, Checking)
2. **Shape Calculator**: Polymorphism dengan shapes (Circle, Rectangle, Triangle)
3. **Employee Management**: Inheritance hierarchy dengan virtual functions
4. **Complex Number Class**: Operator overloading lengkap
5. **Vector Class**: Implementasi vector sendiri dengan operator overloading
6. **String Class**: Custom string class dengan copy control
7. **Library System**: Books, Members, Transactions (composition & aggregation)
8. **Game Character System**: RPG characters dengan inheritance & polymorphism
9. **Matrix Class**: 2D matrix dengan operator overloading
10. **Mini Project**: University Management System (complete OOP)

---

## 📕 MODUL 4: STANDARD TEMPLATE LIBRARY (`lat-stl.cpp`)
**Target**: Menguasai STL dan containers modern

### **Chapter 33: STL Introduction**
#### 33.1 STL Overview
- Containers
- Iterators
- Algorithms
- Function objects

#### 33.2 Why STL
- Reusable components
- Type safety
- Performance
- Standard library guarantee

---

### **Chapter 34: Sequence Containers**
#### 34.1 Vector
- Dynamic array
- Methods: `push_back`, `pop_back`, `size`, `at`, `[]`
- Capacity vs size
- Reserve & shrink_to_fit
- Iterators

#### 34.2 List
- Doubly linked list
- When to use vs vector
- Methods: `push_front`, `push_back`, `insert`, `erase`
- Splice operations

#### 34.3 Deque
- Double-ended queue
- Methods: `push_front`, `push_back`
- vs vector and list

#### 34.4 Array (C++11)
- Fixed-size container
- vs C-style array
- Safety benefits

#### 34.5 Forward_list
- Singly linked list
- Memory efficient
- Limited operations

---

### **Chapter 35: Container Adapters**
#### 35.1 Stack
- LIFO adapter
- Methods: `push`, `pop`, `top`
- Underlying container

#### 35.2 Queue
- FIFO adapter
- Methods: `push`, `pop`, `front`, `back`

#### 35.3 Priority_queue
- Heap-based
- Max-heap by default
- Custom comparators

---

### **Chapter 36: Associative Containers**
#### 36.1 Set
- Unique elements
- Sorted order
- Methods: `insert`, `find`, `erase`
- Binary search tree implementation

#### 36.2 Multiset
- Allows duplicates
- Use cases

#### 36.3 Map
- Key-value pairs
- Unique keys
- Methods: `insert`, `find`, `erase`, `[]`, `at`
- Ordered by key

#### 36.4 Multimap
- Multiple values per key
- Use cases

---

### **Chapter 37: Unordered Containers (C++11)**
#### 37.1 Unordered_set
- Hash table
- O(1) average operations
- vs set (sorted vs unsorted)

#### 37.2 Unordered_map
- Hash map
- O(1) average lookup
- vs map performance

#### 37.3 Hash Functions
- Default hash
- Custom hash functions
- Collision handling

---

### **Chapter 38: Iterators**
#### 38.1 Iterator Basics
- `begin()` dan `end()`
- Iterator categories
- Iterator operations

#### 38.2 Iterator Types
- Input iterator
- Output iterator
- Forward iterator
- Bidirectional iterator
- Random access iterator

#### 38.3 Reverse Iterators
- `rbegin()` dan `rend()`
- Traversing backwards

#### 38.4 Const Iterators
- `const_iterator`
- `cbegin()` dan `cend()`

---

### **Chapter 39: Algorithms**
#### 39.1 Non-modifying Algorithms
- `find`, `find_if`
- `count`, `count_if`
- `all_of`, `any_of`, `none_of`
- `for_each`

#### 39.2 Modifying Algorithms
- `copy`, `move`
- `transform`
- `replace`, `replace_if`
- `remove`, `remove_if`
- `unique`

#### 39.3 Sorting & Related
- `sort`
- `stable_sort`
- `partial_sort`
- `nth_element`

#### 39.4 Binary Search Algorithms
- `binary_search`
- `lower_bound`, `upper_bound`
- `equal_range`

#### 39.5 Set Operations
- `set_union`
- `set_intersection`
- `set_difference`

#### 39.6 Heap Operations
- `make_heap`
- `push_heap`, `pop_heap`
- `sort_heap`

#### 39.7 Min/Max
- `min`, `max`
- `min_element`, `max_element`
- `minmax_element`

---

### **Chapter 40: Function Objects (Functors)**
#### 40.1 Functors Basics
- Overloading `operator()`
- State in functors
- vs regular functions

#### 40.2 Standard Functors
- `less`, `greater`
- `plus`, `minus`
- `logical_and`, `logical_or`

#### 40.3 Lambda Expressions (Deep Dive)
- Capture modes
- Mutable lambdas
- Return type deduction
- Generic lambdas (C++14)

---

### **Chapter 41: Utility Classes**
#### 41.1 Pair
- `std::pair`
- `make_pair`
- Accessing: `first`, `second`

#### 41.2 Tuple (C++11)
- `std::tuple`
- `make_tuple`
- `std::get`
- Structured bindings (C++17)

#### 41.3 Optional (C++17)
- Representing optional values
- vs pointers/nulls
- Methods: `has_value`, `value`, `value_or`

#### 41.4 Variant (C++17)
- Type-safe union
- `std::visit`
- Use cases

#### 41.5 Any (C++17)
- Type-erased storage
- When to use

---

### **📝 LATIHAN MODUL 4**
1. **Phone Book**: Gunakan map untuk contact management
2. **Word Frequency**: Count word occurrences dengan unordered_map
3. **Task Scheduler**: Priority queue untuk task management
4. **Graph Algorithms**: Adjacency list dengan STL containers
5. **Set Operations**: Implement set calculator (union, intersection, etc)
6. **Custom Comparators**: Sort structures dengan berbagai criteria
7. **Range Algorithms**: Process data dengan STL algorithms
8. **Iterator Practice**: Implement custom iterator
9. **Lambda Workshop**: Solve problems dengan lambdas
10. **Mini Project**: E-commerce system (products, cart, orders dengan STL)

---

## 📔 MODUL 5: ADVANCED C++ (`lat-advanced.cpp`)
**Target**: Modern C++ features dan advanced techniques

### **Chapter 42: Move Semantics (C++11)**
#### 42.1 Rvalue References
- Lvalue vs Rvalue
- `&&` syntax
- When rvalues occur

#### 42.2 Move Constructor
- Moving vs copying
- `std::move`
- Performance benefits

#### 42.3 Move Assignment
- Move assign operator
- Leaving moved-from object in valid state

#### 42.4 Rule of Five/Zero
- When to implement
- Default implementations
- `= default` dan `= delete`

---

### **Chapter 43: Smart Pointers (C++11)**
#### 43.1 Unique_ptr
- Exclusive ownership
- Cannot be copied
- `std::make_unique`
- Custom deleters

#### 43.2 Shared_ptr
- Shared ownership
- Reference counting
- `std::make_shared`
- Circular reference problem

#### 43.3 Weak_ptr
- Breaking circular references
- Observing without owning
- `lock()` method

#### 43.4 Smart Pointers Best Practices
- When to use which
- Performance considerations
- Legacy code integration

---

### **Chapter 44: Templates (Advanced)**
#### 44.1 Function Templates Deep Dive
- Template specialization
- Template parameters deduction
- SFINAE (Substitution Failure Is Not An Error)

#### 44.2 Class Templates
- Template classes
- Member templates
- Template template parameters

#### 44.3 Variadic Templates
- Parameter packs
- Fold expressions (C++17)
- Perfect forwarding

#### 44.4 Type Traits
- `std::is_same`
- `std::enable_if`
- `std::conditional`
- Compile-time programming

---

### **Chapter 45: Metaprogramming**
#### 45.1 Constexpr
- `constexpr` functions
- `constexpr` variables
- Compile-time computation
- `constexpr if` (C++17)

#### 45.2 Template Metaprogramming
- Compile-time calculations
- Type computations
- Template recursion
- Use cases dan limitations

---

### **Chapter 46: Exception Handling (Advanced)**
#### 46.1 Exception Safety
- Basic guarantee
- Strong guarantee
- No-throw guarantee
- Exception safety levels

#### 46.2 Custom Exceptions
- Inheriting from `std::exception`
- Exception hierarchies
- `what()` method
- Best practices

#### 46.3 RAII & Exceptions
- Resource management
- Stack unwinding
- Destructor exceptions (why to avoid)

#### 46.4 Noexcept
- `noexcept` specifier
- `noexcept` operator
- Move constructors & noexcept
- Performance implications

---

### **Chapter 47: Multithreading (C++11)**
#### 47.1 Thread Basics
- `std::thread`
- Creating threads
- `join()` dan `detach()`
- Thread lifecycle

#### 47.2 Synchronization
- Race conditions
- `std::mutex`
- `std::lock_guard`
- `std::unique_lock`
- Deadlocks dan prevention

#### 47.3 Condition Variables
- `std::condition_variable`
- Producer-consumer pattern
- Spurious wakeups

#### 47.4 Atomic Operations
- `std::atomic`
- Lock-free programming
- Memory ordering
- Atomic operations types

#### 47.5 Async & Future
- `std::async`
- `std::future` dan `std::promise`
- `std::packaged_task`
- Exception propagation

#### 47.6 Thread-Safe Containers
- Concurrent access patterns
- Custom thread-safe wrappers
- Lock striping

---

### **Chapter 48: Memory Management (Advanced)**
#### 48.1 Custom Allocators
- Allocator concept
- Custom memory pools
- Arena allocators
- Performance optimization

#### 48.2 Placement New
- Manual memory management
- Constructor invocation
- Use cases

#### 48.3 Memory Alignment
- `alignof` dan `alignas`
- Cache-friendly code
- SIMD considerations

---

### **Chapter 49: Type Manipulation**
#### 49.1 Type Deduction
- `auto` keyword
- `decltype`
- Trailing return types
- `decltype(auto)` (C++14)

#### 49.2 Type Aliases
- `typedef` (traditional)
- `using` (modern C++11)
- Template aliases

#### 49.3 Type Casting (Advanced)
- `static_cast`
- `dynamic_cast`
- `const_cast`
- `reinterpret_cast`
- When to use each

---

### **Chapter 50: Standard Library Utilities**
#### 50.1 Chrono Library
- `std::chrono::duration`
- `std::chrono::time_point`
- Clocks (system, steady, high_resolution)
- Timing code execution

#### 50.2 Random Number Generation
- `<random>` header
- Random engines
- Distributions (uniform, normal, etc)
- vs old `rand()`

#### 50.3 Regular Expressions
- `<regex>` library
- Pattern matching
- Regex operations
- Performance considerations

#### 50.4 Filesystem (C++17)
- `std::filesystem::path`
- Directory operations
- File information
- Portable file handling

---

### **Chapter 51: Modern C++ Features**
#### 51.1 Range-based For Loop (C++11)
- Syntax
- vs traditional loops
- Structured bindings in loops

#### 51.2 Auto & Decltype
- Type inference
- When to use auto
- AAA (Almost Always Auto) debate

#### 51.3 Uniform Initialization (C++11)
- Brace initialization `{}`
- Initializer lists
- Most vexing parse solution

#### 51.4 Nullptr (C++11)
- vs `NULL` dan `0`
- Type safety
- Overload resolution

#### 51.5 Strongly-typed Enums (C++11)
- `enum class`
- Scoping benefits
- Type safety

#### 51.6 Delegating Constructors (C++11)
- Constructor chaining
- Reducing code duplication

#### 51.7 Deleted & Defaulted Functions (C++11)
- `= default`
- `= delete`
- Preventing copies

---

### **Chapter 52: C++14/17/20 Features**
#### 52.1 C++14
- Binary literals
- Digit separators
- Generic lambdas
- Return type deduction
- Variable templates

#### 52.2 C++17
- Structured bindings
- `if` dengan initializer
- Fold expressions
- `std::optional`, `std::variant`, `std::any`
- `std::string_view`
- Inline variables

#### 52.3 C++20 (Preview)
- Concepts
- Ranges
- Coroutines
- Modules
- Three-way comparison (`<=>`)
- Designated initializers

---

### **📝 LATIHAN MODUL 5**
1. **Smart Pointer Manager**: Implement custom smart pointer
2. **Thread Pool**: Create thread pool untuk parallel tasks
3. **Memory Pool Allocator**: Custom allocator implementation
4. **Producer-Consumer**: Thread-safe queue implementation
5. **Template Meta Calculator**: Compile-time computations
6. **Custom String View**: Implement string_view-like class
7. **Async File Processor**: Process files asynchronously
8. **Type-Safe Registry**: Use templates dan type traits
9. **Performance Timer**: Precise timing dengan chrono
10. **Mini Project**: Multi-threaded web server simulation

---

## 📓 MODUL 6: EXPERT LEVEL & BEST PRACTICES (`lat-expert.cpp`)
**Target**: Design patterns, optimization, dan production-ready code

### **Chapter 53: Design Patterns - Creational**
#### 53.1 Singleton Pattern
- Implementation variations
- Thread-safe singleton
- Destruction issues
- When to avoid

#### 53.2 Factory Pattern
- Simple Factory
- Factory Method
- Abstract Factory
- Real-world examples

#### 53.3 Builder Pattern
- Step-by-step construction
- Fluent interface
- Complex object creation

#### 53.4 Prototype Pattern
- Cloning objects
- Deep vs shallow copy
- Use cases

#### 53.5 Object Pool
- Reusing expensive objects
- Implementation
- Thread-safe pools

---

### **Chapter 54: Design Patterns - Structural**
#### 54.1 Adapter Pattern
- Interface compatibility
- Class vs Object adapter
- Real examples

#### 54.2 Bridge Pattern
- Decoupling abstraction from implementation
- Use cases

#### 54.3 Composite Pattern
- Tree structures
- Uniform treatment
- File system example

#### 54.4 Decorator Pattern
- Adding functionality dynamically
- vs inheritance
- Stream decorators example

#### 54.5 Facade Pattern
- Simplified interface
- Subsystem hiding
- API design

#### 54.6 Flyweight Pattern
- Sharing common data
- Memory optimization
- Intrinsic vs extrinsic state

#### 54.7 Proxy Pattern
- Virtual proxy
- Remote proxy
- Protection proxy
- Smart reference

---

### **Chapter 55: Design Patterns - Behavioral**
#### 55.1 Observer Pattern
- Event handling
- Publisher-subscriber
- Implementation options

#### 55.2 Strategy Pattern
- Algorithm interchangeability
- vs function pointers
- Policy-based design

#### 55.3 Command Pattern
- Encapsulating requests
- Undo/redo functionality
- Macro commands

#### 55.4 State Pattern
- State-dependent behavior
- Finite state machines
- vs switch statements

#### 55.5 Template Method Pattern
- Algorithm skeleton
- Hook methods
- NVI (Non-Virtual Interface)

#### 55.6 Iterator Pattern
- Traversing collections
- STL iterators review
- Custom iterators

#### 55.7 Visitor Pattern
- Double dispatch
- Adding operations
- Type-safe alternatives

#### 55.8 Chain of Responsibility
- Request handling chain
- Decoupling sender-receiver

#### 55.9 Mediator Pattern
- Object interaction management
- Reducing coupling

#### 55.10 Memento Pattern
- State capture
- Undo functionality

---

### **Chapter 56: SOLID Principles**
#### 56.1 Single Responsibility Principle
- One reason to change
- Cohesion
- Examples

#### 56.2 Open/Closed Principle
- Open for extension
- Closed for modification
- Techniques

#### 56.3 Liskov Substitution Principle
- Substitutability
- Contract preservation
- Common violations

#### 56.4 Interface Segregation Principle
- Client-specific interfaces
- Fat interfaces problem
- Refactoring techniques

#### 56.5 Dependency Inversion Principle
- Depend on abstractions
- Dependency injection
- IoC containers

---

### **Chapter 57: Performance Optimization**
#### 57.1 Profiling
- Measuring performance
- Profiling tools (gprof, Valgrind, perf)
- Hotspot identification
- Don't optimize prematurely

#### 57.2 Algorithm Optimization
- Big O notation review
- Choosing right data structures
- Space-time tradeoffs
- Cache-friendly algorithms

#### 57.3 Memory Optimization
- Memory layout
- Struct packing
- Pool allocators
- Memory access patterns

#### 57.4 Compiler Optimizations
- Optimization flags (-O2, -O3)
- Link-time optimization (LTO)
- Profile-guided optimization (PGO)
- Understanding assembly output

#### 57.5 Loop Optimization
- Loop unrolling
- Loop fusion
- Loop invariant code motion
- Vectorization

#### 57.6 Cache Optimization
- CPU cache hierarchy
- Cache lines
- Prefetching
- False sharing

---

### **Chapter 58: Debugging Techniques**
#### 58.1 Debugging Tools
- GDB basics
- Visual Studio debugger
- Breakpoints & watchpoints
- Core dumps

#### 58.2 Debugging Strategies
- Print debugging
- Binary search method
- Rubber duck debugging
- Systematic approach

#### 58.3 Sanitizers
- Address Sanitizer (ASan)
- Thread Sanitizer (TSan)
- Undefined Behavior Sanitizer (UBSan)
- Memory Sanitizer (MSan)

#### 58.4 Static Analysis
- Compiler warnings
- Clang-Tidy
- Cppcheck
- PVS-Studio

---

### **Chapter 59: Testing**
#### 59.1 Unit Testing
- Test frameworks (Google Test, Catch2)
- Writing testable code
- Test structure (Arrange-Act-Assert)
- Code coverage

#### 59.2 Test-Driven Development (TDD)
- Red-Green-Refactor cycle
- Benefits dan challenges
- When to use TDD

#### 59.3 Mocking & Stubbing
- Google Mock
- Dependency injection for testing
- Test doubles

#### 59.4 Integration Testing
- Testing components together
- Test environments
- Continuous integration

---

### **Chapter 60: Code Quality**
#### 60.1 Code Style & Conventions
- Naming conventions
- Code formatting (clang-format)
- Consistency importance
- Style guides (Google, LLVM)

#### 60.2 Code Reviews
- Review best practices
- What to look for
- Giving/receiving feedback
- Automated reviews

#### 60.3 Documentation
- Comments vs documentation
- Doxygen
- README files
- API documentation

#### 60.4 Refactoring
- When to refactor
- Refactoring techniques
- Extract method/class
- Rename safely

---

### **Chapter 61: Build Systems**
#### 61.1 Make & Makefile
- Basic Makefile syntax
- Rules dan dependencies
- Variables dan functions
- Automatic variables

#### 61.2 CMake
- CMakeLists.txt
- Modern CMake practices
- Find packages
- Cross-platform builds

#### 61.3 Package Managers
- Conan
- Vcpkg
- Dependency management

---

### **Chapter 62: Version Control**
#### 62.1 Git Basics
- Commits, branches, merges
- Remote repositories
- Git workflow
- Best practices

#### 62.2 Collaboration
- Pull requests
- Code review workflow
- Branching strategies
- Semantic versioning

---

### **Chapter 63: Cross-Platform Development**
#### 63.1 Platform Differences
- Compilers (GCC, Clang, MSVC)
- Operating systems
- Endianness
- Integer sizes

#### 63.2 Portable Code
- Preprocessor macros
- Abstraction layers
- Standard library usage
- Third-party libraries

---

### **Chapter 64: API Design**
#### 64.1 Library Design
- Header-only libraries
- ABI stability
- Versioning
- Backward compatibility

#### 64.2 Interface Design
- Minimal interfaces
- Consistency
- Error handling strategies
- Resource management

---

### **Chapter 65: Advanced Topics**
#### 65.1 Compiler Internals (Overview)
- Compilation stages
- Linking process
- Symbol tables
- Name mangling

#### 65.2 Undefined Behavior
- What is UB
- Common UB examples
- Why UB exists
- How to avoid

#### 65.3 Low-Level Programming
- Bit manipulation
- Binary protocols
- Hardware interaction
- Embedded considerations

#### 65.4 Interoperability
- C/C++ interoperability
- Foreign function interface
- DLL/Shared libraries
- `extern "C"`

---

### **📝 LATIHAN MODUL 6**
1. **Design Patterns Catalog**: Implement all 23 GoF patterns
2. **Logger Library**: Thread-safe, configurable logging system
3. **JSON Parser**: From scratch dengan proper error handling
4. **Object Pool**: Generic thread-safe object pool
5. **Plugin System**: Dynamic loading dengan DLL/SO
6. **Memory Profiler**: Track allocations dan leaks
7. **Expression Evaluator**: Full calculator dengan parser
8. **State Machine Framework**: Generic FSM implementation
9. **Network Protocol**: Design dan implement simple protocol
10. **Mini Project**: Complete production-ready library dengan tests, docs, CI/CD

---

## 🎓 CAPSTONE PROJECTS

### **Project 1: Text Editor**
- Multiple file support
- Syntax highlighting
- Undo/redo system
- Search & replace
- Command palette
- Plugin system

**Concepts Used**: OOP, Design Patterns (Command, Observer), File I/O, Data Structures, Threading

---

### **Project 2: Database System**
- SQL-like query language
- B-tree indexing
- Transaction support (ACID)
- Query optimization
- Concurrent access
- File persistence

**Concepts Used**: Advanced Data Structures, Algorithms, Multithreading, Parser, Memory Management

---

### **Project 3: Game Engine**
- Entity-Component System
- Rendering pipeline
- Physics engine
- Collision detection
- Resource management
- Scripting support

**Concepts Used**: OOP, Design Patterns (Factory, Observer, Strategy), Memory Management, Performance Optimization

---

### **Project 4: HTTP Server**
- TCP socket handling
- HTTP protocol implementation
- Thread pool
- Static file serving
- Routing system
- Middleware support

**Concepts Used**: Networking, Multithreading, Design Patterns, Performance Optimization, Error Handling

---

### **Project 5: Compiler/Interpreter**
- Lexical analysis
- Parsing (recursive descent)
- AST generation
- Type checking
- Code generation/interpretation
- Error reporting

**Concepts Used**: Advanced Algorithms, Data Structures, Recursion, OOP, Design Patterns

---

## 📚 RESOURCES & REFERENCES

### **Books**
1. **Beginner**
   - "C++ Primer" - Stanley Lippman
   - "Programming: Principles and Practice Using C++" - Bjarne Stroustrup

2. **Intermediate**
   - "Effective C++" - Scott Meyers
   - "More Effective C++" - Scott Meyers

3. **Advanced**
   - "Effective Modern C++" - Scott Meyers
   - "C++ Concurrency in Action" - Anthony Williams
   - "C++ Templates: The Complete Guide" - Vandevoorde, Josuttis

4. **Expert**
   - "Design Patterns" - Gang of Four
   - "Modern C++ Design" - Andrei Alexandrescu
   - "The C++ Programming Language" - Bjarne Stroustrup

### **Online Resources**
- LearnCPP.com (https://www.learncpp.com)
- CppReference (https://en.cppreference.com)
- Compiler Explorer (https://godbolt.org)
- C++ Core Guidelines (https://isocpp.github.io/CppCoreGuidelines)
- CppCon Videos (YouTube)

### **Practice Platforms**
- LeetCode (algorithms)
- HackerRank (C++ challenges)
- Codeforces (competitive programming)
- Project Euler (mathematical problems)
- Exercism (mentored practice)

---

## 🗓️ LEARNING PATH TIMELINE

### **Phase 1: Foundation (2-3 Bulan)**
- Modul 1: Fundamental C++
- Focus: Syntax, logic, basic problem solving
- Practice: 30-50 problems

### **Phase 2: Intermediate (2-3 Bulan)**
- Modul 2: Intermediate C++
- Focus: Data structures, algorithms, memory
- Practice: 50-100 problems

### **Phase 3: OOP Mastery (2 Bulan)**
- Modul 3: Object-Oriented Programming
- Focus: Design, abstraction, polymorphism
- Practice: Mini projects (5-10)

### **Phase 4: Modern C++ (1-2 Bulan)**
- Modul 4: STL
- Focus: Library usage, efficiency
- Practice: Refactor previous code dengan STL

### **Phase 5: Advanced (2-3 Bulan)**
- Modul 5: Advanced C++
- Focus: Move semantics, templates, threading
- Practice: Complex projects

### **Phase 6: Expert (Ongoing)**
- Modul 6: Expert Level
- Focus: Design patterns, optimization, production code
- Practice: Capstone projects, open source contribution

**Total Estimated Time**: 11-15 bulan untuk expert level

---

## ✅ PROGRESS TRACKING

### **Checklist Format**
```
[ ] Chapter XX: Title
    [ ] Subpoint 1
    [ ] Subpoint 2
    [ ] Exercise 1
    [ ] Exercise 2
    [ ] Mini Project
```

### **Milestone Markers**
- 🟢 **Beginner**: Selesai Modul 1
- 🔵 **Intermediate**: Selesai Modul 1-2
- 🟡 **OOP Practitioner**: Selesai Modul 1-3
- 🟠 **Advanced Developer**: Selesai Modul 1-4
- 🔴 **Expert**: Selesai Semua Modul + Capstone

---

## 💡 TIPS BELAJAR

1. **Consistency > Intensity**
   - Better 1 jam setiap hari vs 7 jam sekali seminggu

2. **Practice Makes Perfect**
   - Minimal 30% waktu untuk coding practice
   - Jangan cuma baca teori

3. **Read Others' Code**
   - Study open source projects
   - Learn from experienced programmers

4. **Teach What You Learn**
   - Explain concepts ke orang lain
   - Write blog posts atau dokumentasi

5. **Build Real Projects**
   - Apply knowledge to real problems
   - Portfolio projects

6. **Debug Everything**
   - Understand errors deeply
   - Learn from mistakes

7. **Stay Updated**
   - Follow C++ news
   - Learn new standards (C++20, C++23)

8. **Join Communities**
   - Stack Overflow
   - Reddit r/cpp
   - Discord C++ servers
   - Local C++ meetups

---

## 🎯 FINAL NOTES

Kurikulum ini dirancang untuk:
- ✅ Modular dan terstruktur
- ✅ Dari dasar hingga expert
- ✅ Sesuai dengan industry standards
- ✅ Hands-on dengan banyak latihan
- ✅ Adaptif sesuai kecepatan belajar

**Remember**: Programming adalah skill yang butuh **praktik konsisten**. Jangan cepat menyerah kalau stuck, debugging adalah bagian dari belajar!

Selamat belajar dan semangat! 🚀💻