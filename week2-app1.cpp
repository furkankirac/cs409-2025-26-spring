// Brief intro. to C++ basics.

// C++: a VALUE SEMANTIC language.
//  we work with THE VALUE. we can get references to the values as well.
// Java/Python/Javascript/C#...:
//   everything is allocated in the heap memory (some exceptions of course)
//   everything is accessed via a reference (REFERENCE SEMANTIC language)

// variables and functions and scope
//   primitive types
//   local, global, static variables
//   free, member, static functions
//   function return types

// primitive types: char, int, bool, double, float, ... (because CPU knows about them in its native language)

// reflection
//   auto, sizeof, sizeof..., typeid (RTTI), decltype, ...
// almost always auto - aaa rule: move type to the right

// OOP: struct, class, ctor/dtor, inheritance
// this ptr, static functions
// functions vs function parameters
// methods vs objects

// --- OOP basics
// ctor/dtor
// copy-ctor, copy-assignment
// move-ctor, move-assignment (not covered in CS321)
// inheritance (not covered in CS321)

// --- Functional Programming Basics
// function / operator overloading

// namespaces
// static variables, attributes
// inline keyword
// static inline


#include <iostream>
// #include <stdio.h>

using namespace std;


struct Core {
    // float f;
    char a, b, c, d, e;

    Core() {
        cout << "Core is being constructed" << endl;
    }

    Core(int a) {
        cout << "Core is being constructed with a" << endl;
    }
};

struct Vector2d : Core { //   <------ this is pointing to the instance of Vector2d
    static inline double count = 0;

    // public:
    int x; // <---- this
    double y;

private:
    int z;

public:
    Vector2d() : x() {
        cout << "C-tor of Vector2d got called" << endl;
        count++;
        //
    }

    Vector2d(int x, int y) : Core(x), x(x), y(y) {
        this->x = x;
        this->y = y;
        cout << "C-tor of Vector2d(x, y) got called" << endl;
        //
    }

    ~Vector2d() {
        count--;
    }

};

// double Vector2d::count = 0;


struct ExtendedVector2d {
    Vector2d v;
    char c;
};

struct TwoVector2Ds {
    Vector2d first;
    Vector2d second;
    TwoVector2Ds() {
        // ...
    }
};


double lookup[256];
bool initialized_lookup = false;

void do_smt() {
    if (!initialized_lookup) {
        initialized_lookup = true;
        // do initialize
    }
    // real deal
}


// double pi = 3.14;

int main(int argc, char* argv[])
{
    static double pi = 3.14;


    // int a;
    // Vector2d xy;
    auto xy = Vector2d(1, 2);
    auto ab = TwoVector2Ds();
    do_smt();

    // printf("Hello");
    // cout << "Something" << endl;

    // cout << sizeof(double) << endl;
    // cout << "Size of Vector2d instance is " << sizeof(Vector2d) << endl;
    cout << "Size of ExtendedVector2d instance is " << sizeof(ExtendedVector2d) << endl;

    return 0;
}
