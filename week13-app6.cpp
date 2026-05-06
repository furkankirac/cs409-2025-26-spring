#include <iostream>
#include <string>

using namespace std;

// SFINAE = Substitution Failure Is Not An Error

template<typename T>
concept IsIntegralType = std::is_integral_v<T>;


template <bool B, typename T = void> struct EnableIf { };

template <typename T>
struct EnableIf<true, T> {
    using type = T;
};


// template<typename T>
// EnableIf<std::is_integral_v<T>, void>::type print(const string& s) {
//     cout << sizeof(T) << endl;
//     cout << s << endl;
// }

template<typename T>
// requires (IsIntegralType<T>)
// requires (std::is_integral_v<T>)
void print(const string& s, typename EnableIf<std::is_integral_v<T>, void>::type* not_necessary = nullptr) {
    cout << sizeof(T) << endl;
    cout << s << endl;
}


int main()
{
    // print<float>("Hi there");

    return 0;
}
