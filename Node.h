#include <ostream>

template <typename T> 
class Node {
    public:
        // Miembros de datos
        T value;  // Valor del nodo
        Node* next;  // Puntero al siguiente nodo

        // Constructor
        Node(T val) : value(val), next(nullptr) {}

        // Destructor
        ~Node() {
            // Si quieres implementar algún tipo de limpieza, hazlo aquí
        }

        // Método para establecer el siguiente nodo
        void setNext(Node* nextNode) {
            next = nextNode;
        }

        // Método para obtener el siguiente nodo
        Node* getNext() const {
            return next;
        }

        // Método para obtener el valor del nodo
        T getValue() const {
            return value;
        }

        // Método para imprimir el nodo (opcional)
        void print(std::ostream& out) const {
            out << value;
        }
};

// Sobrecarga del operador de salida para imprimir el nodo
template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    node.print(out);
    return out;
}

