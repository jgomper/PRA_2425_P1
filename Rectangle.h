#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;  // Puntero a un array de 4 puntos (v0, v1, v2, v3)
    static const int N_VERTICES = 4;  // Número de vértices

    static bool check(Point2D* vertices);  // Método para verificar si los vértices forman un rectángulo válido

public:
    // Constructores
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);  // Constructor de copia
    ~Rectangle();  // Destructor

    // Métodos de acceso y modificación
    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    void set_vertices(Point2D* vertices);

    // Sobrecarga del operador de asignación
    Rectangle& operator=(const Rectangle &r);

    // Métodos abstractos heredados de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif

