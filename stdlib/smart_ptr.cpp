#include <memory>

auto f()
{

  // single owner, can transfer ownership via std::move
  // uses RAII: deletes underlying memory when it goes out of scope
  std::unique_ptr<int> a;

  // Reference counted
  // last one out deletes the memory
  std::shared_ptr<int> b;

  // doesn't allocate memory on construction
  // on default construction pointer == nullptr;


  // buggy naive construction
  // if unique_ptr constructor throws, we leak memory
  auto c = std::unique_ptr(new int(42));

  // solution: make_unique/shared helper function!
  // simple code at the call site, takes care of deallocating
  // in case of failure
  // also improves memory layout for shared_ptr:
  // allocates ref count and data in the same blob of memory
  auto d = std::make_unique<int>(42);

  //note: not thread safe:
  auto e = std::make_shared<int>(42);
  //thread 1
  auto copy = e;
  // thread 2
  e = std::make_shared<int>(1337);
  // C++20 adds real std::atomic<shared_ptr<T>>;
  // before that it looked atomic, but was implemented with locks
  // tricky to implement, requires 128 bit atomic instrucion
  // or some other type of sorcery
}

// g takes ownership of the memory
void g(std::unique_ptr<int> &&ptr);
auto h() 
{
  auto ptr = std::make_unique<int>(42);
  /* do somethings with ptr */
  g(std::move(ptr));
}

// side note on && and std::move:
// std::move is not magic, it works by overload resolution
// often used in "memcpy" style assignment and construction
//  && can mean 2 different things
// with concrete types, means an "right hand value" or rvalue
// auto left_value = rvalue;
// that is, a value that can't be modified typically because it has no name
//
// on templates, it means "any reference type" because of funky cast rules
//
void rvalue_func(int && a);

template <class T>
void templated_func(T && t) {}

void func()
{
  rvalue_func(42); // Ok
  int a = 42;
  // rvalue_func(a); // fails to compile, lvalue cannot be implicitly casted to rvalue
  rvalue_func(std::move(a)); // Ok, move casts a to int &&;
  // a is left in a "valid but unspecified sate"; don't use it until it's reassigned a value
  templated_func(42); // Ok T is (T &&) and T && && decays to T &&
  a = 42;
  templated_func(a); // Ok T is (T &) and T & && decays to T &
}
