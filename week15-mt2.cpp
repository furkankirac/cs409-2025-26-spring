#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <variant>

#include "week15-mt2-impl.hpp"

template<class T>
std::string as_text(T const &value) {
    std::ostringstream out;
    out << value;
    return out.str();
}

int main()
{
    std::cout << "ExprLab++ MT2\n";

    auto mt1_expr = (1.5 + $z) * ($x + $y / 2.0);
    auto mt1_vector = Vector<int>{10, 20, 30, 40, 50};

    std::cout << "\nQ1)\n";
    std::cout << "mt1 expr = " << mt1_expr(5, 10, 15) << '\n';
    std::cout << "mt1 vector = " << mt1_vector << '\n';
    // Expected Q1 output:
    // mt1 expr = 165
    // mt1 vector = 10 20 30 40 50

    auto registry = ExpressionRegistry{};
    registry.add("square_minus_self", $x * $x - $x);
    registry.add("shift", $x + 0.5);
    std::function<double(double)> cube = [](double value) { return value * value * value; };
    registry.add_function("cube", cube);

    auto runtime_expr = registry.invoke("square_minus_self") + registry.invoke("shift");

    std::cout << "\nQ2)\n";
    std::cout << "registry map = " << Vector<double>{1.0, 2.5, 4.0}.map(runtime_expr) << '\n';
    std::cout << "registered cube = " << registry.invoke("cube")(2, 0, 0) << '\n';
    std::cout << "contains missing = " << registry.contains("missing") << '\n';
    // Expected Q2 output:
    // registry map = 1.5 6.75 16.5
    // registered cube = 8
    // contains missing = 0

    using Scalar = std::variant<int, float, double>;
    auto variant_expr = $x * $y + $z;
    auto mixed = Vector<Scalar>{
        Scalar{1},
        Scalar{2.5f},
        Scalar{4.0},
        Scalar{6.5}
    };
    auto variant_runtime = registry.invoke("square_minus_self");
    auto variant_serial = mixed.map(variant_runtime);
    auto variant_again = mixed.map(variant_runtime);

    std::cout << "\nQ3)\n";
    std::cout << "variant scalar = " << variant_expr(Scalar{2}, Scalar{3.5f}, Scalar{4}) << '\n';
    std::cout << "variant map = " << variant_serial << '\n';
    std::cout << "variant repeated map matches = " << (as_text(variant_again) == as_text(variant_serial)) << '\n';
    // Expected Q3 output:
    // variant scalar = 11
    // variant map = 0 3.75 12 35.75
    // variant repeated map matches = 1

    auto speed_sanity = registry.invoke("square_minus_self") + $x;

    std::cout << "\nQ4)\n";
    std::cout << "benchmark sanity = " << Vector<double>{1.0, 2.0, 3.0}.map(speed_sanity) << '\n';
    // Expected Q4 output:
    // benchmark sanity = 1 4 9
}
