// function pointer
// member function pointer
// lambdas
// std::function
// repeat_it with templates, with std::function
// duck typing? type erasure: std::function

// CRTP: curiously recurring template pattern

// virtual route --> dynamic polymorphism
// CRTP route    --> static polymorphism

#include <iostream>

using namespace std;

template<typename DERIVED>
struct Base {
    void dosmt() {
        ((DERIVED*)this)->jump();
    }
};


struct DERIVED : Base<DERIVED> {
    void jump() {
        cout << "I jumped" << endl;
    }
};

int main()
{
    auto derived = DERIVED{};
    derived.dosmt();


    return 0;
}
