// core language definitions:
// - C++ reference vs pointers
// - l-value / r-value
// - chain assignment
// - constness: east/west const, pointers and const

// new, new[], delete, delete[]

// copy c-tor, copy assignment
// move-ctor, move-assignment

// Generics / Templates:
// function, class, variable, type templates

// OOP:
// inheritance
// dynamic polymorphism / virtual functions vs RTTI
// v-table

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct Vector {
    size_t size;
    T* data;

    // Vector(int size) : size(size), data((T*)malloc(size * sizeof(T))) {
    Vector(int size) : size(size), data(new T[size]) {

    }

    ~Vector() {
        // free(data);
        delete[] data;
    }
};

// struct Vector_int {
//     size_t size;
//     int* data;

//     // Vector(int size) : size(size), data((int*)malloc(size * sizeof(int))) {
//     Vector_int(int size) : size(size), data(new int[size]) {

//     }

//     ~Vector_int() {
//         // free(data);
//         delete[] data;
//     }
// };


int main(int argc, char* argv[])
{
    // C++ ref &
    // C++ refref && -> only binds to r-values

    auto v = Vector<int>(100);

    auto v2 = new std::vector<int>(100);

    return 0;
}
