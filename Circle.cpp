#include "Circle.h"
#include <cmath> // Para std::pow() y M_PI

// Constructor por defecto
Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1) {}

// Constructor parametrizado
Circle::Circle(const std::string& color, const Point2D& center, double radius) 
    : Shape(color), center(center) {
    if (radius <= 0) {
        throw std::invalid_argument("El radio debe ser mayor que 0.");
    }
    this->radius = radius;
}

// Consultor del atributo center
Point2D Circle::get_center() const {
    return center;
}

// Modificador del atributo center
void Circle::set_center(const Point2D& p) {
    center = p;
}

// Consultor del atributo radius
double Circle::get_radius() const {
    return radius;
}

// Modificador del atributo radius
void Circle::set_radius(double r) {
    if (r <= 0) {
        throw std::invalid_argument("El radio debe ser mayor que 0.");
    }
    radius = r;
}

// Implementación de area()
double Circle::area() const {
    return M_PI * std::pow(radius, 2); // π * r^2
}

// Implementación de perimeter()
double Circle::perimeter() const {
    return 2 * M_PI * radius; // 2πr
}

// Implementación de translate()
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Implementación de print()
void Circle::print() const {
    std::cout << "Circle:(color =  " << get_color() 
              << ", center = (" << center.x << ", " << center.y << ")"
              << ", radius = " << radius << ")" << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Circle& c) {
    c.print(); // Reutilizamos el método print() para evitar duplicidad de código
    return out;
}

