#include <iostream>
#include <string>
#include <vector>

// reference collapsing
// perfect forwarding
// is_lvalue_reference<T>::value (value trait, returns boolean)
// auto always strips references, decltype(auto)

using namespace std;

template<typename T>
struct TypeDisplay;

struct Widget {
};

void create(const Widget& t) { // works for l-value cases
    // ... this will not touch t
}

void create(Widget&& t) { // works for r-value cases
    // ... this will steal/move from t
}

auto foo(auto&& whatever) {

}

template<typename T>
void CREATE(T&& t) { // forwarding reference
    // in case of l-value call site binding
    // T&& must collapse to Widget&
    // T is deduced as Widget&
    // so that Widget& + && --> collapses to Widget&
    // and it fits with the call site l-value

    // in case of r-value call site binding (Widget&&)
    // T&& must collapse to Widget&&
    // T is deduced as Widget
    // so that Widget + && --> collapses to Widget&&
    // and it fits with the call site r-value

    // note that template type deduction engine is old,
    // and does not know about && anyway
    // it can only deduce pure type or type&

    // auto t = TypeDisplay<T>();

    // if constexpr (std::is_lvalue_reference<T>::value) {

    // }

    // .... do stuff ....

    // std::move(X) was something that casts X to X&&
    // foo(static_cast<T&&>(t));
    foo(std::forward<T>(t));


}



int main(int argc, char* argv[])
{
    auto w = Widget();
    // create(w); // l-value case
    // create(Widget()); // r-value case

    CREATE(w); // l-value case
    CREATE(Widget()); // r-value case



    using INT = int;
    using INT_REF = int&;
    using INT_REFREF = int&&;

    return 0;
}
