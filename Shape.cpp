#include "Shape.h"

// Constructor por defecto
Shape::Shape() : color("red") {}

// Constructor con validación de color
Shape::Shape(const std::string& color) {
    set_color(color); // Llama al método para validar el color
}

// Devuelve el color actual
std::string Shape::get_color() const {
    return color;
}

// Modifica el color de la figura, con validación
void Shape::set_color(const std::string& c) {
    if (c != "red" && c != "green" && c != "blue") {
        throw std::invalid_argument("Color inválido. Los colores válidos son: red, green, blue.");
    }
    color = c;
}

