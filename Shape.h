#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>

class Shape {
protected:
    std::string color;

public:
    // Constructor por defecto
    Shape();

    // Constructor con validación de color
    Shape(const std::string& color);

    // Devuelve el color actual
    std::string get_color() const;

    // Modifica el color de la figura (validación incluida)
    void set_color(const std::string& c);

    // Destructor virtual
    virtual ~Shape() = default;

    // Métodos virtuales puros
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() = 0;
};

#endif

