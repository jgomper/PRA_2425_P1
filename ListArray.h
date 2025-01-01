#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <iostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
    private:
        static const int DEFAULT_CAPACITY = 10;  // Capacidad por defecto
        T* data;                                 // Puntero a un array dinámico
        int size;                                // Número de elementos en la lista
        int capacity;                            // Capacidad actual del array

        void resize();                           // Método privado para redimensionar el array si es necesario

    public:
        // Constructor y destructor
        ListArray();                             // Constructor por defecto
        ~ListArray();                            // Destructor

        // Métodos sobreescritos de List<T>
        bool isEmpty() const override;           // Implementación de isEmpty
        int getSize() const override;            // Implementación de getSize
        void insert(const T& element) override;  // Implementación de insert
        T remove() override;                     // Implementación de remove
        T get(int index) const override;         // Implementación de get
        int search(const T& element) const override;  // Implementación de search
        void append(const T& element) override;  // Implementación de append
        void prepend(const T& element) override; // Implementación de prepend

        // Sobrecarga del operador de inserción de flujo
        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const ListArray<U>& list);
};

// Implementación de métodos

template <typename T>
ListArray<T>::ListArray() : size(0), capacity(DEFAULT_CAPACITY) {
    data = new T[capacity];  // Reserva memoria para el array
}

template <typename T>
ListArray<T>::~ListArray() {
    delete[] data;  // Libera la memoria reservada
}

template <typename T>
bool ListArray<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
int ListArray<T>::getSize() const {
    return size;
}

template <typename T>
void ListArray<T>::insert(const T& element) {
    if (size == capacity) {
        resize();  // Redimensiona si es necesario
    }
    data[size++] = element;  // Inserta el elemento y aumenta el tamaño
}

template <typename T>
T ListArray<T>::remove() {
    if (isEmpty()) {
        throw std::out_of_range("No se puede eliminar de una lista vacía");
    }
    return data[--size];  // Disminuye el tamaño y devuelve el último elemento
}

template <typename T>
T ListArray<T>::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Índice fuera de rango");
    }	
    return data[index];  // Devuelve el elemento en la posición dada
}

template <typename T>
int ListArray<T>::search(const T& element) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == element) {
            return i;  // Devuelve el índice si encuentra el elemento
        }
    }
    return -1;  // Devuelve -1 si no encuentra el elemento
}

template <typename T>
void ListArray<T>::append(const T& element) {
    insert(element);  // Agrega al final
}

template <typename T>
void ListArray<T>::prepend(const T& element) {
    if (size == capacity) {
        resize();  // Redimensiona si es necesario
    }
    // Desplazar los elementos hacia la derecha
    for (int i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = element;
    ++size;  // Aumenta el tamaño
}

// Método privado para redimensionar el array dinámico
template <typename T>
void ListArray<T>::resize() {
    capacity *= 2;  // Duplica la capacidad
    T* newData = new T[capacity];  // Reserva nuevo array con más capacidad
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];  // Copia los elementos
    }
    delete[] data;  // Libera la memoria antigua
    data = newData; // Apunta al nuevo array
}

// Sobrecarga del operador de inserción para mostrar el contenido de la lista
template <typename T>
std::ostream& operator<<(std::ostream& os, const ListArray<T>& list) {
    os << "[";
    for (int i = 0; i < list.size; ++i) {
        os << list.data[i];
        if (i < list.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif  // LISTARRAY_H

