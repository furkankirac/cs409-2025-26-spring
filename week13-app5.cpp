#include <iostream>

using namespace std;

// tag-dispatching

// [[nodiscard]]
// [[deprecated("reason")]]
// [[maybe_unused]]: Suppresses compiler warnings about unused entities
// [[fallthrough]]: fallthrough to the next case statement is okay
// [[likely]]: Hint to the compiler that a statement is likely to be taken
// [[unlikely]]

// SFINAE = Substitution Failure Is Not An Error


struct WITH_ENDL { };
struct NO_ENDL { };

void print(int i, NO_ENDL) {
    cout << i;
}

void print(int i, WITH_ENDL) {
    cout << i << endl;
}

[[nodiscard]] int foo() {
    cout << "FOO" << endl;
    return 10;
}

int main()
{
    foo();

    print(10, WITH_ENDL{});

    print(10, NO_ENDL{});
    print(10, NO_ENDL{});
    print(10, NO_ENDL{});

    return 0;
}
