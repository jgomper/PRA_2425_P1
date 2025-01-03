#include "Circle.h"

double Circle::area() const {
    return M_PI * std::pow(radius, 2);
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::print(std::ostream &out) const {
    out << "Circle: {"
        << "Color: " << get_color() 
        << ", Center: (" << center.x << ", " << center.y << ")"
        << ", Radius: " << radius
        << "}";
}

