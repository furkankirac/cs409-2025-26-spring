#include <iostream>
#include <variant>
#include <vector>

using namespace std;

// overloaded function objects
// std::holds_alternative<T>

struct FuncObjInt {
    auto operator() (int i) const { return i * 2; }
};

struct FuncObjDouble {
    auto operator() (double d) const { return d * 10.0; }
};

struct FuncObjChar {
    auto operator() (char c) const { return c + 1; }
};

struct FuncObjIntDouble {
    auto operator() (int i) const { return i * 2; }
    auto operator() (double d) const { return d * 10.0; }
};

// struct FuncObjIntDoubleChar {
//     auto operator() (int i) const { return i * 2; }
//     auto operator() (double d) const { return d * 10.0; }
//     auto operator() (char c) const -> char { return c + 1; }
// };

struct FuncObjIntDoubleChar : FuncObjInt, FuncObjDouble, FuncObjChar {
    using FuncObjInt::operator(),
        FuncObjDouble::operator(),
        FuncObjChar::operator();
    // auto operator() (int i) const { return i * 2; }
    // auto operator() (double d) const { return d * 10.0; }
    // auto operator() (char c) const -> char { return c + 1; }
};

template<typename ... Ts>
struct Overloaded : Ts... {
    using Ts::operator()...;
};

auto lambda_fo_int = [](int i) { return i * 2; };
auto lambda_fo_double = [](double i) { return i * 10.0; };
auto lambda_fo_char = [](char c) -> char { return c + 1; };


int main(int argc, char* argv[])
{
    // auto fo_i = FuncObjInt{};

    // cout << fo_i(1) << endl;
    // cout << fo_i.operator()(1) << endl;

    // auto fo_d = FuncObjDouble{};
    // cout << fo_d(5.0) << endl;

    // auto fo_id = FuncObjIntDouble{};
    // cout << fo_id.operator()(1) << endl;
    // cout << fo_id(5.0) << endl;

    // auto fo_idc = FuncObjIntDoubleChar{};
    // cout << fo_idc('F') << endl;

    // auto fo_idc_ = Overloaded<FuncObjInt, FuncObjDouble, FuncObjChar>{};
    // auto fo_idc  = Overloaded{lambda_fo_int, lambda_fo_double, lambda_fo_char};

    // switch-case for compile-time types!
    auto fo_idc  = Overloaded{
        [](int i) -> double { return i * 2; },
        [](double i) -> double { return i * 10.0; },
        [](char c) -> double { return c + 1; },
        [](string s) -> double { return 42.0; }
    };

    // cout << fo_idc('F') << endl;

    auto V = std::variant<int, double, char, string>{"HELLO"};

    cout << std::visit(fo_idc, V) << endl;

    // if (std::holds_alternative<int>(V))
    //     1;
    // else if (std::holds_alternative<double>(V))
    //     1;
    // else if (std::holds_alternative<char>(V))
    //     1;
    // else if (std::holds_alternative<string>(V))
    //     1;
    // cout << fo_idc(runtime_value) << endl;

}
