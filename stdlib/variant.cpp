#include <variant>

// variant is a tagged union type
// sizeof(variant) ~= sizeof biggest type + sizeof tag

struct A {};
struct B {};


auto simple()
{
  std::variant<A, B> v;
  v = A{};
  if (std::holds_alternative<A>(v))
  {
    v = B{};
  }
  if(auto ptr = std::get_if<B>(&v); ptr != nullptr)
  {
    /* use ptr */
  }
}

using state_machine = std::variant<std::monostate, A, B>;

auto f(A &a) {return state_machine{B{}};}
auto f(B &b) {return state_machine{A{}};}
auto f(std::monostate &b) {return state_machine{std::monostate{}};}

template<class... Ts> struct overload_set : Ts... { using Ts::operator()...; };
// C++17 class template argument deduction guideline
template<class... Ts> overload_set(Ts...) -> overload_set<Ts...>;

auto func(state_machine &sm)
{
  while (!std::holds_alternative<std::monostate>(sm))
  {
    sm = std::visit([](auto & var){ return f(var); }, sm);
    sm = std::visit(
        overload_set{
        [](A &a) -> state_machine { return B{}; },
        [](B &a) -> state_machine { return A{}; },
        [](auto &&a) -> state_machine { return std::monostate{}; },
        },
        sm);
  }
  sm = std::visit([](auto & var) -> state_machine {
      using T = std::decay_t<decltype(var)>;
      if constexpr (std::is_same_v<T, A>) return B{};
      else if constexpr (std::is_same_v<T, A>) return A{};
      else return std::monostate{};
      },
      sm);
}
