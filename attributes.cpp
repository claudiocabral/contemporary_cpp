// attributes are a standard replacement for __attribute__, __declspec and so forth
// the give the compiler additional information about your code
// helps produce/silence compiler errors
// potentially improves performance
// not that many standard attributes available
// implementation specific attributes encouraged 
// if an implementation does not recognize an attribute it is ignored

// all C++ std attributes and exmaple usage

[[noreturn]] void function_has_infinte_loop()
{
  while (true)
  {
    // game loop, embedded device loop,  server loop
  }
}

[[deprecated]] bool old_api([[maybe_unused]] void *data) { return false; }

[[deprecated("this was a horrible ideia to begin with")]]
bool we_regret_this_api([[maybe_unused]] void *data, [[maybe_unused]] int type)
{
  return false;
}

auto get_message(int message_index)
{
  switch(message_index)
  {
    case 0: [[fallthrough]];
    case 1: [[fallthrough]];
    case 2: [[fallthrough]];
    case 3: return "same message for first 4 indices";
    case 4: return "some other message";
    default:
      return "unknown index";
  }
}

[[nodiscard]] bool check_if_successful_please() { return false; }

std::optional<float> safe_division(float dividend, float quotient)
{
  if (quotient != 0) [[likely]] 
  {
    return dividend / quotient;
  }
  return {};
}

std::optional<float> safe_division(float dividend, float quotient)
{
  if (quotient == 0) [[unlikely]] 
  {
    return {};
  }
  return dividend / quotient;
}

struct Empty{};
struct A {
  int a;
  [[no_unique_address]] Empty e;
// sizeof A can potentially optimize member e out, aka sizef(A) == sizeof(int)
};


/*
[[carries_dependency]] : from (cppreference)[https://en.cppreference.com/w/cpp/language/attributes]
indicates that dependency chain in release-consume std::memory_order propagates in and out of the function
haven't used it, need to look into how it applies
*/
