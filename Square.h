#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"

class Square : public Rectangle {
private:
    // Método privado para comprobar si los vértices forman un cuadrado válido
    static bool check(Point2D* vertices);

public:
    // Constructor por defecto
    Square();

    // Constructor con color y vértices
    Square(const std::string& color, Point2D* vertices);

    // Modifica los vértices del cuadrado
    void set_vertices(Point2D* vertices);

    // Sobrecarga del operador << para imprimir el cuadrado
    friend std::ostream& operator<<(std::ostream& out, const Square& square);

    // Método print sobreescrito
    void print() const override;
};

#endif

