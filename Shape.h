#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include <iostream>
#include "Point2D.h"

class Shape {
protected:
    std::string color; // Color de la figura: "red", "green", "blue"

public:
    // Constructor por defecto
    Shape() : color("red") {}

    // Constructor con color
    Shape(const std::string& color) {
        set_color(color); // Valida y asigna el color
    }

    // Devuelve el color de la figura
    std::string get_color() const {
        return color;
    }

    // Modifica el color de la figura
    void set_color(const std::string& c) {
        if (c != "red" && c != "green" && c != "blue") {
            throw std::invalid_argument("Color inválido. Los colores válidos son: red, green, blue.");
        }
        color = c;
    }

    // Métodos virtuales puros
    virtual double area() const = 0;           // Calcula el área de la figura
    virtual double perimeter() const = 0;     // Calcula el perímetro de la figura
    virtual void translate(double incX, double incY) = 0; // Traslada la figura
    virtual void print() const = 0;           // Imprime información básica sobre la figura

    // Virtual destructor
    virtual ~Shape() = default;
};

#endif

