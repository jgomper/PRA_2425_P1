#include "Square.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

// Verifica si los puntos forman un cuadrado válido
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    double d02 = Point2D::distance(vertices[0], vertices[2]);
    double d13 = Point2D::distance(vertices[1], vertices[3]);

    // Comprobar si las 4 aristas son iguales y las diagonales son iguales
    return (d01 == d12 && d12 == d23 && d23 == d30) && (d02 == d13);
}

// Constructor por defecto
Square::Square() : Rectangle("red", new Point2D[4]{
    Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1)}) {}

// Constructor con parámetros
Square::Square(const std::string& color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }
}

// Establecer los vértices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices proporcionados no forman un cuadrado válido.");
    }
    Rectangle::set_vertices(vertices);
}

// Imprimir información del cuadrado
void Square::print() const {
    std::cout << "[Square: color = " << get_color()
              << "; v0 = " << vs[0]
              << "; v1 = " << vs[1]
              << "; v2 = " << vs[2]
              << "; v3 = " << vs[3] << "]"; // vs = vertices
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Square& square) {
    out << "[Square: color = " << square.get_color()
        << "; v0 = " << square.vs[0]
        << "; v1 = " << square.vs[1]
        << "; v2 = " << square.vs[2]
        << "; v3 = " << square.vs[3] << "]";
    return out;
}

