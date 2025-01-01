#ifndef LISTARRAY_H
#define LISTARRAY_H

#include "List.h"
#include <iostream>
#include <stdexcept>



template <typename T>
class ListArray {
private:
    T* array;
    int size;
    int capacity;

    void resize(int new_capacity) {
        T* new_array = new T[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
        capacity = new_capacity;
    }

public:
    ListArray() : size(0), capacity(10) {
        array = new T[capacity];
    }

    ~ListArray() {
        delete[] array;
    }

    void insert(const T& value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        array[size++] = value;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }
};

#endif

