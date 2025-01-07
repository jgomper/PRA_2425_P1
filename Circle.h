#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <stdexcept>
#include "Point2D.h"
#include "Shape.h"

class Circle : public Shape {
private:
    Point2D center;  // Centro del círculo
    double radius;   // Radio del círculo

public:
    // Constructor por defecto: círculo rojo, centro (0, 0), radio 1
    Circle();

    // Constructor con parámetros
    Circle(const std::string& color, const Point2D& center, double radius);

    // Consultor del atributo center
    Point2D get_center() const;

    // Modificador del atributo center
    void set_center(const Point2D& p);

    // Consultor del atributo radius
    double get_radius() const;

    // Modificador del atributo radius
    void set_radius(double r);

    // Implementación de métodos heredados de Shape
    double area() const override;                // Calcula el área del círculo
    double perimeter() const override;          // Calcula el perímetro del círculo
    void translate(double incX, double incY) override; // Traslada el círculo
    void print() override;                      // Imprime la información del círculo

    // Sobrecarga global del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Circle& c);
};

#endif

