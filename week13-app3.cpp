#include <iostream>
#include <string>
#include <optional>
#include <memory>

using namespace std;

// std::declval<T>
// ADL: argument dependent lookup
// friend functions
// tag-dispatching
// SFINAE

// [[nodiscard]]
// [[deprecated("reason")]]
// [[maybe_unused]]: Suppresses compiler warnings about unused entities
// [[fallthrough]]: fallthrough to the next case statement is okay
// [[likely]]: Hint to the compiler that a statement is likely to be taken
// [[unlikely]]

struct MyStruct {
    MyStruct() = delete;
    // MyStruct(int) { };
    // ...
    int print() const { return -1; }
};

template<typename T>
auto func() {

    using ret_type = decltype(declval<T>().print());

    if constexpr(is_same_v<ret_type, int>) {

    } else {

    }
}



int main()
{
    func<MyStruct>();

    return 0;
}
