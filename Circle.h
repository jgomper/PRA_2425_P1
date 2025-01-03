#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    Circle() : Shape(), center(Point2D(0, 0)), radius(1.0) {}
    Circle(std::string color, Point2D center, double radius) 
        : Shape(color), center(center), radius(radius) {}

    Point2D get_center() const { return center; }
    void set_center(Point2D p) { center = p; }

    double get_radius() const { return radius; }
    void set_radius(double r) {
        if (r > 0) radius = r;
        else throw std::invalid_argument("El radio debe ser positivo.");
    }

    double area() const override;
    double perimeter() const override;
    void print(std::ostream &out) const override;

    friend std::ostream &operator<<(std::ostream &out, const Circle &c) {
        c.print(out);
        return out;
    }
};

#endif // CIRCLE_H

