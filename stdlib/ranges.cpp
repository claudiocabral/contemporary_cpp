#include <algorithm>
#include <numeric>
#include <ranges>

using namespace std::views;

auto f()
{
  std::array arr{ 1, 3, 7, 9 };
  std::find(arr.begin(), arr.end(), 7);
  std::ranges::find(arr, 7);
  std::ranges::find(counted(arr.begin(), 2), 7);

  auto v = iota(0)
    | filter([](auto val) { return !(val & 2); })
    | transform([](auto val) { return val * val; })
    | take(5)
    | common
    ;
  return std::reduce(v.begin(), v.end(), 0);
}
