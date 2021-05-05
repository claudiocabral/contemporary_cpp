# Modern C++ Practices: part 0 of N-1

Welcome! We'll dive into the most recent developments in C++.
It has been al ong decade filled with innovation, questionable decisions
and enough confusion to keep consultatns employed for the next century.

This contains a list of what I consider good to know things about C++
as it exists in 2021. I plan to add more entries as time passes

## [Tooling](tools.md)
* Compiler explorer
* CMake
- ninja
- clang-tidy
- package managers

## Language features

* auto
- ranged for loop
* lambdas
* constexpr, consteval, constinit, if constexpr
* move semantics
* [[attributes]]
- class template deduction guide lines (C++17)
- user defined literals
- template magic
- coroutines (not covered, waiting for better compiler support)
- modules (not covered, waiting for better compiler support)
- concepts (not covered)

## Standard Template Library

### Containers
- `std::vector`
- `std::array`
- `std::[unordered_]map`
- `std::[unordered_]set`
don't use lists.

### View types
- `std::string_view`
- `std::span`

### Algebraic types
- std::optional
- std::variant

### (Smart Pointers)[stdlib/smart_ptr.cpp]
* `std::unique_ptr`
* `std::shared_ptr`

### Algorithms library
- a whole world of wonders

### Multithreading & data sharing

- `std::atomic`
- `std::mutex` & co
- `std::lock` & co
- `std::thread` & `std::jthread`

### Formatting
* `std::format`

## Resources

* [cppreference](https://en.cppreference.com/w/)
* [Compiler Explorer](https://godbolt.org)
* [CppCon talks](https://www.youtube.com/channel/UCMlGfpWw-RUdWX_JbLCukXg)
  - I think these talks thought me C++
  - personal favorite speakers:
  - Andrei Alexandrescu (formerly on Facebook, now teaching)
  - Sean Parent (Adobe)
  - Kate Gregory (Consultant)
  - Chandler Carruth (Google, LLVM)
  - Titus Winter (Google, responsible for their C++ codebase)
  - Fedor Pikus (Mentor, great talks about concurrency)
  - Jason Turner (Consultant)
  - Herb Sutter (Microsoft)
  - Many more, including many people who only spoke once but gave amazing talks
  - can provide a "best off" playlist if there's interest
