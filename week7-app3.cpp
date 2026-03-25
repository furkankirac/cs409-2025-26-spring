#include <iostream>
#include <string>
#include <array>
#include <tuple>

// comma operator
// parameter packs, fold expressions
// const, constexpr, if constexpr
// concepts, requires clause/expression
// std::pair, tuple, optional
// union, std::variant,


using namespace std;

template<typename ... Ts> // Ts = int|float|double|int (compile time p.p)
struct TypeDisplay {

    auto demo(Ts ... ts) { // ts = 4|3.14f|8.8|1 (run-time parameter pack)
        // parameter pack expansion
        auto tpl = std::tuple<Ts...>(); // tuple<int, float, double, int>

        // (4|3.14f|8.8|1)...;
        // 4, 3.14f, 8.8, 1;
        // ts...;
        (ts + ...); // fold expression with operator +
        auto sum = (ts + ...);
        4 + 3.14f + 8.8 + 1;

        (ts , ...);
    }
};

int main(int argc, char* argv[])
{
    auto td = TypeDisplay<int, float, double, int>();
    td.demo(4, 3.14f, 8.8, 1);




    int j = 0;
    for(int i=0; i<10; i++, j++) {
        // ...
    }

    // 1;
    // 2;
    // 3;
    // 5;
    // 10, 20, 30; // outcome 30

    auto i = 10;
    auto b = 5;
    auto k = (i++, b++);

    cout << i << endl;
    cout << b << endl;
    cout << k << endl;


    return 0;
}
