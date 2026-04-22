// function pointer
// member function pointer
// lambdas
// std::function
// repeat_it with templates, with std::function
// duck typing? type erasure: std::function

// unique_ptr, shared_ptr, make_unique, make_shared
// CRTP: curiously recurring template pattern

#include <iostream>
#include <string>
#include <memory>
#include <functional>

using namespace std;

void foo(int i) { cout << i * 10 << endl; }
void bar(int i) { cout << i * 100 << endl; }

struct Zoo {
    string name;

    void foo(int i) { cout << (name + "___"s) << endl; } // this === pointing to zoo instance
    void bar(int i) { cout << ("___"s + name) << endl; }
};


template<int times, typename FUNC>
void repeat_it(FUNC func) {
    for(int i=0; i<times; i++) {
        func();
    }
}

// std::function<...> is type-erasure or duck-typing

template<int times>
void repeat_it_runtime(function<void()> func) {
    for(int i=0; i<times; i++) {
        func();
    }
}


void doit() {
    cout << "just do it" << endl;
}


int main()
{
    // auto times = 10; // I can read this value from a file
    // repeat_it<10>([] { cout << "Hello" << endl; });
    // repeat_it<5>([] { cout << "Hello1" << endl; });
    // repeat_it<3>([] { cout << "Hello2" << endl; });
    // repeat_it<30>([] { cout << "Hello2" << endl; });

    // repeat_it_runtime<10>(&doit);
    repeat_it_runtime<10>([]() { cout << "just do it" << endl; });


    // typedef int INT;
    // using INT = int;

    // typedef void (*FUNCPTR)(int);
    using FUNCPTR = void (*)(int);

    auto funcptr = FUNCPTR{}; // nullptr

    funcptr = &foo;
    (*funcptr)(11);
    // funcptr(11);
    funcptr = &bar;
    funcptr(22);

    auto zoo = Zoo{"Monkey"};
    zoo.foo(10); // zoo is passed after taken address of (&zoo  ----> passed as this)
    zoo.bar(11);


    // typedef void (Zoo::*MFP)(int i); // member function pointer
    using MFP = void (Zoo::*)(int i);

    auto mfp = MFP{};
    cout << sizeof(mfp) << endl;

    mfp = &Zoo::foo;
    (zoo.*mfp)(10);
    mfp = &Zoo::bar;
    (zoo.*mfp)(11);

    return 0;
}
