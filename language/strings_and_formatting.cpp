#include <string_view>
#include <format>

auto f()
{
  std::string str = std::format("{}, {}!!!! feel the freedom from %s and %d\n in C++{}",
      "Hello",
      std::string_view{"world"},
      20
      )
}
