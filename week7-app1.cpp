#include <iostream>
#include <string>
#include <vector>

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

struct Parent {
    float f;

    operator float() const {
        return f;
    }

};

struct Foo : Parent {
    // this pointer is pointing to here
    // float f;
    int attr;
    // several attributes

    operator int() const {
        return attr;
    }

    // operator float() const {
    //     return f;
    // }

    // several c-tors
    Foo() : Parent() {} // default c-tor

    // copy c-tor
    Foo(const Foo& other) : Parent(other),  attr(other.attr) { }

    // move c-tor
    Foo(Foo&& other) : Parent(std::move(other)), attr(other.attr) { }

    // copy assignment
    auto operator=(const Foo& other) {
        static_cast<Parent&>(*this) = other;
        this->attr = other.attr;
    }

    // move assignment
    auto operator=(Foo&& other) {
        static_cast<Parent&>(*this) = std::move(other);
        this->attr = other.attr;
    }

    Foo(std::initializer_list<int> il) : Parent() { // il -> {1, 2, 3}
        auto* ptr = il.begin();
        attr = ptr[0]; // *ptr;
    }


};



// hey there is a function named foo2 that takes no input params
// and returns a Foo instance
// I'll fill in the content later
// this is just the signature/prototype of that function
// Foo foo2();


int main(int argc, char* argv[])
{
    int a = 10;
    int& a_ref = a;
    a_ref = 20;

    // auto b = a_ref;
    // // int& b = a_ref; // no
    // // int b = a_ref; // yes
    // decltype(auto) c = a_ref;

    auto foo = Foo();
    auto int_value = (int)foo;
    auto float_value = (float)foo;

    // auto foo2 = foo; // copy c-tor usage
    // auto foo2 = (Foo&&)foo; // move c-tor usage because we stampted it as r-value
    auto foo2 = std::move(foo);

    auto foo3 = Foo{1, 2, 3};


    return 0;
}
