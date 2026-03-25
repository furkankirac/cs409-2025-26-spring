#include <iostream>
#include <string>
#include <array>

// casting operator, OOP?
// array access operator []
// comma operator
// parameter packs, fold expressions
// const, constexpr, if constexpr
// concepts, requires clause/expression
// std::pair, tuple, optional
// union, std::variant,


using namespace std;

template<typename T>
struct TypeDisplay;


int main(int argc, char* argv[])
{
    // c array
    int A[5] = {1, 2, 3, 4, 5};

    cout << A << endl;
    cout << A[0] << endl;
    cout << *(A + 0) << endl;
    cout << *(0 + A) << endl;
    cout << 0[A] << endl;

    A[5] = 10;

    constexpr int k = 5;
    auto B = std::array<int, k>{1, 2, 3, 4, 5};
    // B.operator[](10) = 10;
    B[10] = 10;

    return 0;
}
