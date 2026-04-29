// get free function overloads
// tuples: how to design our own new dialect tuple structure? A case-study

#include <iostream>
#include <variant>
#include <tuple>

using namespace std;

// int hello() { return 5; }
// float hello() { return 5.5f; };

struct Foo {
    // struct iterator {
    // };

    // auto begin() const { return ... };
    // auto end() const { ...}
    // auto size() const { return 3; };
    int i;
    float f;
    double d;
    float ff;
};

template<size_t index>
auto get(const Foo& foo) {
    if constexpr(index == 0) { return foo.i; }
    if constexpr(index == 1) { return foo.f; }
    if constexpr(index == 2) { return foo.d; }
}

// auto get_0(const Foo& foo) -> int       { return foo.i; }
// auto get_1(const Foo& foo) -> float     { return foo.f; }
// auto get_2(const Foo& foo) -> double    { return foo.d; }

template<typename T1, typename T2>  struct IsSame        { static constexpr bool value = false; };
template<typename T>                struct IsSame<T, T>  { static constexpr bool value = true; };

template<typename T1, typename T2>
concept IsSameValue = IsSame<T1, T2>::value;




template<typename T>
auto get(const Foo& foo) {
    // static_assert(!IsSameValue<T, float>, "AMBIGIOUS");

    if constexpr(std::is_same_v<T, int>) { return foo.i; }
    if constexpr(IsSameValue<T, float>) { return foo.f; }
    if constexpr(std::is_same<T, double>::value) { return foo.d; }
}

int main()
{
    auto foo = Foo{10, 11.11f, 22.2};
    // get<0>(foo);

    cout << get<float>(foo) << endl;

    // auto t = tuple<int, float, double>{1, 2.2f, 3.3};
    // get<0>(t); // --> 1 (int)
    // get<1>(t); // --> 2.2f (float)
    // get<2>(t); // --> 3.3 (double)

    return 0;
}
