#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;                  // Puntero al inicio del array
    int max;                 // Tamaño actual del array
    int n;                   // Número de elementos en la lista
    static const int MINSIZE = 2; // Tamaño mínimo del array

    void resize(int new_size) {
        T* new_arr = new T[new_size];
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor
    ~ListArray() {
        delete[] arr;
    }

    // Inserta el elemento e en la posición pos
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        ++n;
    }

    // Inserta el elemento e al final de la lista
    void append(T e) override {
        insert(n, e);
    }

    // Inserta el elemento e al principio de la lista
    void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento situado en la posición pos
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        T removed = arr[pos];
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;
        if (n < max / 4 && max > MINSIZE) {
            resize(max / 2);
        }
        return removed;
    }

    // Devuelve el elemento situado en la posición pos
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango");
        }
        return arr[pos];
    }

    // Devuelve la posición de la primera ocurrencia del elemento e, o -1 si no se encuentra
    int search(T e) override {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    // Indica si la lista está vacía
    bool empty() override {
        return n == 0;
    }

    // Devuelve el número de elementos de la lista
    int size() override {
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos) {
        return get(pos);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "List => [";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }
};

