// C++11 changed the meaning of the auto keyword
void f() {
  auto a = some_func();
  decltype(auto) b = some_func();
  auto * c = some_func();
  auto & d = some_func();
  const auto & e = some_func();
}

// on function signatures can be used with trailing return types
auto f() -> void {}
// can be inferred from C++14 onwards
auto f() {}

// on C++20 can be used as a shorthand for templates
void f(auto a, auto b);
// equivalent to
template<class T, class U>
void f(T a, U b);

