#include <iostream>
#include <string>
#include <vector>

// reference collapsing
// perfect forwarding
// is_lvalue_ref<T>
// auto always strips references, decltype(auto)

using namespace std;

// for introduction of refref (not logical and T&&)
// T&& tells T is an r-value or ??
// int&& -> definitely and r-value binding ref for integers

void foo(int&& i) {
    i = 10;
}

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


int main(int argc, char* argv[])
{
    auto w = Widget();
    create(w); // l-value case
    create(Widget()); // r-value case

    foo(5);

    // typedef int INT;

    using INT = int;
    using INT_REF = int&;
    using INT_REFREF = int&&;

    int i = 5;

    // int* a = &i;
    // *a = 10;
    // cout << *a << endl;

    INT_REF a = i;
    a = 10;
    cout << i << endl;

    // auto t = TypeDisplay<INT_REF>();
    // invalid use of incomplete type 'struct TypeDisplay<int&>'
    // auto t = TypeDisplay<INT_REF&>();
    // invalid use of incomplete type 'struct TypeDisplay<int&>'

    // auto t = TypeDisplay<INT_REF&&>(); // & + && ---> &
    // // invalid use of incomplete type 'struct TypeDisplay<int&>'
    // auto t = TypeDisplay<INT_REFREF&>(); // && + & ---> &
    // invalid use of incomplete type 'struct TypeDisplay<int&>'
    // auto t = TypeDisplay<INT_REFREF&&>(); // && + && ---> &&
    // invalid use of incomplete type 'struct TypeDisplay<int&&>'

    // only two scenarios that after the collapse you get a && is
    // 1) pure_type + &&
    // 2) pure_type&& + &&



    // left side is &, right side is & ----> collapses to &

    // INT_REF&


    // auto t = TypeDisplay<int>();


    return 0;
}
