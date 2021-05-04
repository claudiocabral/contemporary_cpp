#include <algorithm>

// lambdas
static void f() {

  auto a = []() -> void {};

  a();

  []      // capture block
  ()      // arguments
  -> void // trailing return type
  {}      // body
  ;       // finish lambda expression

  // most of this can be omited
  auto b = [] {};
  b();

  // they can be immediately invoked
  const auto six = ([](auto a, auto b) { return a + b; })(2, 4);

  ([](){})(); // valid C++ expression
  ([](){([](){})();})(); // can be nested for added fun

  // Lambdas are anonymous structs that overload operator () under the hood
  // They're great ways of encapsulating behaviour or letting a user specialize behaviour
  // in other words, together with templates and std::function
  // they are a replacement for virtual functions
  auto data = std::array { 1, 2, 3, 4, 5, 6, 7 ,8 };
  auto result = std::ranges::count_if(data, [](auto a) { return a < 5; });
}

template <class OnConnect, class OnDisconnect>
struct TcpServer
{
  OnConnect connectCallback;
  OnDisconnect disconnectCallback;
  [[noreturn]] void serve(std::string_view address, uint16_t port)
  {
    while (true)
    {
      connectCallback(1);
      disconnectCallback("some other type");
    }
  }
};

static void m()
{
  int some_important_state = 42;
  TcpServer server
  {
    [some_important_state](auto client) {}, // infered connect callback
    [&some_important_state](auto client) {}, // infered disconnect callback
  };
  server.serve("localhost", 8080);
}

// this code doesn't do anything
// because this is transparent at compile time, the compiler just deletes everything
