#include "Point2D.h"

// Constructor
Point2D::Point2D(double x, double y) : x(x), y(y) {}

// Método estático: Calcula la distancia euclidiana
double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Sobrecarga del operador ==
bool operator==(const Point2D &a, const Point2D &b) {
    return a.x == b.x && a.y == b.y;
}

// Sobrecarga del operador !=
bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b);
}

// Sobrecarga del operador <<
std::ostream &operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
