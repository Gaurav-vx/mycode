#include <iostream>
#include <vector>
#include <variant>
#include <cmath>

// 1. Define independent, simple structs (No base class, no virtual functions)
struct Circle {
    double radius;
};

struct Rectangle {
    double width;
    double height;
};

struct Triangle {
    double base;
    double height;
};

// 2. Create the Variant Type
using Shape = std::variant<Circle, Rectangle, Triangle>;

// 3. Define the operations using a Visitor pattern (Overloaded lambda trick)
struct AreaCalculator {
    double operator()(const Circle& c) const { return M_PI * c.radius * c.radius; }
    double operator()(const Rectangle& r) const { return r.width * r.height; }
    double operator()(const Triangle& t) const { return 0.5 * t.base * t.height; }
};

int main() {
    // 4. Create a single vector holding completely different types
    // Packed directly in memory without heap pointers!
    std::vector<Shape> shapes;
    
    shapes.push_back(Circle{3.0});
    shapes.push_back(Rectangle{4.0, 5.0});
    shapes.push_back(Triangle{3.0, 6.0});

    // 5. Iterate and process using std::visit
    for (const auto& shape : shapes) {
        double area = std::visit(AreaCalculator{}, shape);
        std::cout << "Shape area: " << area << "\n";
    }

    return 0;
}

