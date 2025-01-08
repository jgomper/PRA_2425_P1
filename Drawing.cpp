#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() {}

Drawing::~Drawing() {
    for (Shape* shape : shapes) {
        delete shape;
    }
}

void Drawing::add_front(Shape* shape) {
    shapes.insert(shapes.begin(), shape);
}

void Drawing::add_back(Shape* shape) {
    shapes.push_back(shape);
}

void Drawing::print_all() const {
    std::cout << "Drawing contents:" << std::endl;
    for (const Shape* shape : shapes) {
	shape->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() const {
    double total_area = 0;
    for (const Shape* shape : shapes) {
        const Circle* circle = dynamic_cast<const Circle*>(shape);
        if (circle) {
            total_area += circle->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (Shape* shape : shapes) {
        Square* square = dynamic_cast<Square*>(shape);
        if (square) {
            square->translate(incX, incY);
        }
    }
}

