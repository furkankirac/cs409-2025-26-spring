#include <iostream>
#include <string>
#include <optional>
#include <memory>

using namespace std;

// = delete
// = default
// unique_ptr, shared_ptr
// std::declval<T>
// ADL: argument dependent lookup
// friend functions
// tag-dispatching
// SFINAE

// [[nodiscard]]
// [[deprecated("reason")]]
// [[maybe_unused]]: Suppresses compiler warnings about unused entities
// [[fallthrough]]: fallthrough to the next case statement is okay
// [[likely]]: Hint to the compiler that a statement is likely to be taken
// [[unlikely]]

struct Base {
    int i;

    Base() = default;
    Base(int i) : i(i) { }
};

struct Foo : Base {
    double d;

    // Foo() = default;
    // Foo(int i) : Base(i) { }
    // Foo() = delete;
};


struct BigObject {

    BigObject() { }
    BigObject(int i) { }
    // ...
};

template<typename T>
struct UniquePtr {
    T* ptr;

    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other) {

    }

};

void func(unique_ptr<BigObject> bo) {

}


int main()
{
    // auto a = std::unique_ptr<BigObject>{new BigObject()};
    // auto a = std::unique_ptr<BigObject>{new BigObject(10)};
    // auto a = make_unique<BigObject>();
    auto a = make_unique<BigObject>(10);
    func(std::move(a));

    auto b = make_shared<BigObject>(10);
    // func(std::move(a));


    // cannot use a yourself


    // auto f = Foo{};

    return 0;
}
