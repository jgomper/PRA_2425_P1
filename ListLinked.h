#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

private:
    Node<T>* first;  // Puntero al primer nodo de la lista enlazada
    int n;           // Número de elementos en la lista

public:
    // Constructor sin argumentos
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next;  // Apuntar al siguiente nodo
            delete first;       // Liberar el nodo actual
            first = aux;        // Mover el puntero first al siguiente nodo
        }
    }

    // Retorna el número de elementos en la lista
    int size() const override {
        return n;
    }

    // Verifica si la lista está vacía
    bool empty() const override {
        return n == 0;
    }

    // Inserta un elemento en una posición específica
    void insert(int pos, const T& value) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* newNode = new Node<T>(value);

        if (pos == 0) {
            newNode->next = first;
            first = newNode;
        } else {
            Node<T>* current = first;
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        ++n;
    }

    // Remueve un elemento de la posición especificada
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        T value;

        if (pos == 0) {
            first = first->next;
            value = current->data;
            delete current;
        } else {
            for (int i = 0; i < pos - 1; ++i) {
                current = current->next;
            }
            Node<T>* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            value = nodeToDelete->data;
            delete nodeToDelete;
        }

        --n;
        return value;
    }

    // Obtiene el valor en una posición específica
    T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Sobrecarga del operador []
    T operator[](int pos) const override {
        return get(pos); // Utilizamos get() para evitar código duplicado
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListLinked<T>& list) {
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

    // Agrega un elemento al final de la lista
    void append(const T& value) override {
        insert(n, value); // insert en la última posición
    }

    // Agrega un elemento al inicio de la lista
    void prepend(const T& value) override {
        insert(0, value); // insert en la primera posición
    }

    // Busca un elemento en la lista
    int search(const T& value) const override {
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;  // Elemento no encontrado
    }
};

