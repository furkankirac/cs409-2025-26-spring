#include "week10-mt1-impl.hpp"

int main()
{
    _println("Expression Lab");

    auto expr1 = (1.5 + $z) * ($x + $y / 2.0);
    _println("\nQ1a)\n", "expr1(5, 10, 15) = ", expr1(5, 10, 15));

    auto expr2 = expr1;
    _println("\nQ1b)\n", "expr2(5, 10, 15) = ", expr2(5, 10, 15));

    auto probes = vector<unique_ptr<Node>>{};
    probes.push_back(Literal(7));
    probes.push_back(Arg('y'));
    probes.push_back(BinaryOp('+', Expr(5), $x));
    _print("\nQ2a)\n", "probe kinds: ");
    for(size_t i = 0; i < probes.size(); ++i)
        cout << (i ? " " : "") << probes[i]->kind();
    _print('\n');

    _print("\nQ2b)\n", "probe evals: ");
    for(size_t i = 0; i < probes.size(); ++i)
        cout << (i ? " " : "") << probes[i]->eval(Args{3, 8, 13});
    _print('\n');

    auto v = Vector<int>{10, 20, 30, 40, 50};
    _println("\nQ3a)\n", "v = ", v);

    auto mask = v[$x > 25];
    _println("\nQ3b)\n", "mask = v[$x > 25] = ", mask);

    auto picked = v[mask];
    _println("\nQ3c)\n", "v[mask] = ", picked);

    auto mapped = v.map($x / 10 + $y);
    _println("\nQ3d)\n", "mapped with $x/10+$y = ", mapped);

    _println("\nQ3e)\n", "tail = ", v[-1], ' ', v[-2]);

    auto spec = tuple{1, -1};
    auto sliced = v[spec];
    _println("\nQ3f)\n", "sliced = v[1:-1] = ", sliced);

    _print(
        "\nQ4a)\n",
        "v.mask($x > 45) = ",
        v.mask($x > 45), "\n",

        "v.pick(vector<bool>{false, true, false, true, false}) = ",
        v.pick(vector<bool>{false, true, false, true, false}), "\n"
        );

    _print(
        "\nQ4b)\n",
        "v.slice(tuple{0, 5, 2}) = ",
        v.slice(tuple{0, 5, 2}), "\n",

        "v.slice(tuple{3, 5}) = ",
        v.slice(tuple{3, 5}), "\n"
        );

    _print(
        "\nQ4c)\n",
        "v.slice(pair{0, 2}) = ",
        v.slice(pair{0, 2}), "\n",

        "v.slice({1, 2}) = ",
        v.slice({1, 2}), "\n"
        );

    auto v2d = Vector<tuple<double, double, double>>{{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};
    _println("\nQ5)\n", "apply(x^2 + 2y^2 - z) -> ", v2d.map($x*$x + 2*$y*$y - $z));
}
