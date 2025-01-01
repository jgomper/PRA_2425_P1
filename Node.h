#include <ostream>

template <typename T> 
class Node {
    public:
        // Miembros de datos
        T data;  // Valor del nodo
        Node* next;  // Puntero al siguiente nodo

        // Constructor (modificado para aceptar valor y puntero al siguiente nodo)
        Node(T val, Node* nextNode = nullptr) : data(val), next(nextNode) {}

        // Destructor
        ~Node() {
            // Aquí podrías liberar recursos si fuera necesario
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
            return data;
        }

        // Método para imprimir el nodo (opcional)
        void print(std::ostream& out) const {
            out << data;
        }
};

// Sobrecarga del operador de salida para imprimir el nodo
template <typename T>
std::ostream& operator<<(std::ostream& out, const Node<T>& node) {
    node.print(out);
    return out;
}

