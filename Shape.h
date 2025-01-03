#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"  // Asumimos que Point2D es una clase ya definida

class Shape {
protected:
    std::string color;  // Color de la figura (red, green, blue)

public:
    // Constructor por defecto: crea una figura de color rojo.
    Shape() : color("red") {}

    // Constructor que permite crear una figura con un color especificado.
    // Lanza std::invalid_argument si el color no es válido.
    Shape(std::string color) {
        if (color != "red" && color != "green" && color != "blue") {
            throw std::invalid_argument("Invalid color");
        }
        this->color = color;
    }

    // Método para obtener el color de la figura.
    std::string get_color() const {
        return color;
    }

    // Método para modificar el color de la figura.
    // Lanza std::invalid_argument si el color no es válido.
    void set_color(std::string c) {
        if (c != "red" && c != "green" && c != "blue") {
            throw std::invalid_argument("Invalid color");
        }
        color = c;
    }

    // Método virtual puro para calcular el área de la figura.
    virtual double area() const = 0;

    // Método virtual puro para calcular el perímetro de la figura.
    virtual double perimeter() const = 0;

    // Método virtual puro para trasladar la figura sobre el espacio.
    virtual void translate(double incX, double incY) = 0;

    // Método virtual puro para imprimir información básica sobre la figura.
    virtual void print() = 0;

    // Destructor virtual (para manejo correcto de la herencia)
    virtual ~Shape() = default;
};

#endif  // SHAPE_H

