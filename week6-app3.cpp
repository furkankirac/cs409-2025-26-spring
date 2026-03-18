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
    int size;
    float f;

    Widget(int size, float f): size(size), f(f) {}

    int& getSize() {
        return this->size;
    }
};

int main(int argc, char* argv[])
{
    auto w = Widget(10, 3.14f);

    decltype(auto) sz = w.getSize();
    sz = 100;
    cout << w.size << endl;

    return 0;
}
