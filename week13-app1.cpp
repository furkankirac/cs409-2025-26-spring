#include <iostream>
#include <string>
#include <optional>

using namespace std;

// std::optional
// = delete
// = default
// std::declval<T>
// unique_ptr, shared_ptr
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

enum ErrorCode {
    Failed
};

struct MyException {
    ErrorCode fail_state;
};

struct MyExceptionDetailed : MyException {
    string message;
};


auto calculate(double d) -> optional<int> {
    // throw 10;
    // throw MyExceptionDetailed{Failed, "Hi there"};
    // return std::nullopt;
    return {};
    // return ((int)d) + 1;
}


// struct XYZ {

//     operator bool() const {
//         return true;
//     }
// };


int main()
{
    auto value = calculate(1000); // value is std::optional<int> instance
    if (value) { // check that instance by casting it to bool
        // auto internal = *value;
        // we have a value returned
    } else {
        // nothing returned
    }

    // try {
    //     calculate(1000);
    // } catch(int i) {

    // } catch(MyException e) {

    // } catch(...) {

    // }


    return 0;
}
