#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <cmath>

class Point2D {
public:
    double x; // Coordenada x
    double y; // Coordenada y

    // Constructor
    Point2D(double x = 0, double y = 0);

    // Métodos de acceso (getters y setters)
    double getX() const { return x; }
    void setX(double val) { x = val; }

    double getY() const { return y; }
    void setY(double val) { y = val; }

    // Métodos estáticos
    static double distance(const Point2D &a, const Point2D &b);

    // Sobrecarga de operadores
    friend bool operator==(const Point2D &a, const Point2D &b);
    friend bool operator!=(const Point2D &a, const Point2D &b);
    friend std::ostream &operator<<(std::ostream &out, const Point2D &p);
};

#endif

