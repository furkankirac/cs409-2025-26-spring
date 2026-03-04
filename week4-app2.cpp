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

struct Animal {
    string name;
    Animal(const string& name) : name(name) {
    }
    ~Animal() {

    }

    void whoami() const {
        cout << name << endl;
    }

    virtual void fly() const {
        cout << "I cannot fly!" << endl;
    }

    virtual void jump() const {
        cout << "I cannot jump!" << endl;
    }
};

enum Color {
    Red = 0,
    Blue = 1,
    Green = 2,
};

struct Bird : Animal {
    Color color;
    Bird(const string& name, Color color) : Animal(name), color(color) {
    }

    void fly() const {
        cout << "I fly now" << endl;
    }
    void jump() const {
        cout << "I am a parrot, of course I can jump" << endl;
    }
};



int main(int argc, char* argv[])
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Bird) << endl;

    auto* animal = new Animal("Arbitrary Animal");
    auto* bird = new Bird("Parrot", Red);

    // Animal* animals[2];

    // auto animals = new Animal*[2];
    auto animals = std::vector<Animal*>(2);
    animals[0] = animal;
    animals[1] = bird;
    // delete[] animals;

    for(Animal* item : animals) {
        // item->whoami();

        // static_cast
        // dynamic_cast
        // reinterpret_cast
        // const_cast



        auto ptr = dynamic_cast<Bird*>(item);
        if (ptr) {
            cout << "THIS IS A BIRD!" << endl;
        }

        item->fly();
    }

    // animal.fly();
    // bird.fly();

    return 0;
}
