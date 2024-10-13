#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    public:
        virtual void insert(const T& element) = 0;       // Método puro para insertar un elemento en la lista
	virtual void append(const T& element) = 0;       // Añade un elemento al final de la lista
        virtual void prepend(const T& element) = 0;      // Añade un elemento al principio de la lista

        virtual T remove() = 0;                          // Método puro para remover un elemento de la lista
        virtual T get(int index) const = 0;              // Método puro para obtener un elemento en un índice específico
	virtual int search(const T& element) const = 0;  // Busca un elemento y devuelve su índice o -1 si no existe

	virtual bool isEmpty() const = 0;                // Método puro para verificar si la lista está vacía
        virtual int size() const = 0;                    // Método puro para obtener el tamaño de la lista
	virtual ~List() {}                               // Destructor virtual para limpieza adecuada


};

#endif

