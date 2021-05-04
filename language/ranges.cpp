#include <algorithm>

auto f()
{
  std::array arr{ 1, 3, 7, 9 };
  std::find(arr.begin(), arr.end(), 7);
  std::ranges::find(arr, 7);
}
