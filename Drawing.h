#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h" // Incluye la definición de Shape
#include <vector>  // Alternativa temporal a List<T>

class Drawing {
private:
    std::vector<Shape*>* shapes; // Lista de figuras representadas en el dibujo

public:
    // Constructor
    Drawing();

    // Destructor
    ~Drawing();

    // Añade una figura al frente del dibujo
    void add_front(Shape* shape);

    // Añade una figura al fondo del dibujo
    void add_back(Shape* shape);

    // Muestra información de todas las figuras del dibujo
    void print_all() const;

    // Devuelve el área total ocupada por los círculos en el dibujo
    double get_area_all_circles() const;

    // Mueve todos los cuadrados del dibujo
    void move_squares(double incX, double incY);
};

#endif // DRAWING_H

