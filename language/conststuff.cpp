// constexpr: introduced in c++11, becoming more and more powerful since then
// allows functions to be called at compile time if their arguments are known at compile time
// originally very restrictive environment, now most functions can be declared constexpr

// can be called at compile or run time
constexpr int f(int a, int b)
{
  return a + b;
}

// C++20 consteval functions can only be called at compile time
// advantages: won't spill into run time by accident, compiler errors in that case
// function won't be included in the binary, even at O0
consteval g(int a, int b)
{
  return a + b;
}

template<int size>
struct ByteArray
{
  char buffer[size];
};

auto func(int runtime_value)
{
  ByteArray<f(3, 4)> a;
  // C++20 feature, compiles on gcc, not supported by latest MSVC yet
  constinit static int b = g(4, 5);
  // also fine to call it at runtime
  f(runtime_value, 1);

  // g is consteval, calling with runtime arguments is a compiler error
  //g(runtime_value, 1);

  // ok?
  return g(4, 5);
  // Yes on gcc; g is called at compile time and reduced to  the constant '9'
  // No on MSVC; error C7595: 'f': call to immediate function is not a constant expression
}

template <class T>
auto copy(T & dest, T & source)
{
  // removes a lot of noise from compilation
  // replaces SFINAE in any contexts
  if constexpr(std::is_trivially_copyable_v<T>)
  {
    memcpy(dest, source, sizeof(T));
  }
  else if (true)
  {
    dest = source;
  }
  else
  {
    static_assert(std::is_same_v<T, T>, "error");
  }
} // see tab 3 for serious example

// C++20
constexpr auto new_available()
{
  auto a = new int[42];
  delete[] a;
  std::vector v{1, 2, 3, 4};
}
