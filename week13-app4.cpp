#include <iostream>

// friend funtions and Argument Dependent Lookup

namespace geometry {
    class Point {
    private:
        double x{};
        double y{};

    public:
        Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

        // === Friend functions (defined outside the class) ===
        // Friend functions are allowed to access private members

        // 1. Stream insertion operator (very common use of friend + ADL)
        friend std::ostream& operator<<(std::ostream& os, const Point& p);

        // 2. Addition operator (symmetric - works as p1 + p2 or p2 + p1)
        friend Point operator+(const Point& a, const Point& b);
    };

    // --- Definitions outside the class ---

    std::ostream& operator<<(std::ostream& os, const Point& p) {
        // uses .x and .y that are private
        // even though this one is a free function, it's a friend function of Point
        // so, Point allows this function to touch private attributes
        return os << "(" << p.x << ", " << p.y << ")";
    }

    Point operator+(const Point& a, const Point& b) {
        return Point(a.x + b.x, a.y + b.y);
    }
} // end of namespace geometry

int main() {
    using geometry::Point;

    auto p1 = Point{1.5, 2.0};
    auto p2 = Point{3.0, 4.5};

    // === ADL in action ===
    // operator+ for geometry::Point is inside geometry namespace
    // auto p3 = operator+(p1, p2);
    // p1 and p2 tell that they're belonging to geometry namespace
    auto p3 = p1 + p2;           // Finds operator+ via ADL in geometry namespace
    auto p4 = p2 + p1;           // Symmetric - also works

    std::cout << "p1      = " << p1 << '\n';
    std::cout << "p2      = " << p2 << '\n';
    std::cout << "p1 + p2 = " << p3 << '\n';
    std::cout << "p2 + p1 = " << p4 << '\n';

    // Even this works thanks to ADL + friend
    std::cout << "Result: " << (p1 + p2) << '\n';
}