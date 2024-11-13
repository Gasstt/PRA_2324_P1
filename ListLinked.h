#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first;  // Puntero al primer nodo de la lista
    int n;           // Número de elementos en la lista

public:
    // Constructor sin argumentos
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* aux;
        while (first != nullptr) {
            aux = first->next; // Guardamos el siguiente nodo
            delete first;       // Liberamos el nodo actual
            first = aux;        // Avanzamos al siguiente nodo
        }
    }

    // Implementación de los métodos heredados de la interfaz List<T>

    // Insertar un elemento en una posición específica
    void insert(int pos, T e){
        if (pos < 0 || pos > n) {
            throw out_of_range("Posición inválida");
        }

        if (pos == 0) {
            // Insertar al inicio
            first = new Node<T>(e, first);
        } else {
            // Insertar en una posición específica
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
            }
            prev->next = new Node<T>(e, prev->next);
        }
        ++n;
    }

    // Agregar un elemento al final de la lista
    void append(T e){
        if (first == nullptr) {
            first = new Node<T>(e);
        } else {
            Node<T>* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node<T>(e);
        }
        ++n;
    }

    // Agregar un elemento al inicio de la lista
    void prepend(T e){
        insert(0, e);  // Inserta al inicio usando el método `insert`
    }

    // Eliminar y devolver el elemento en una posición específica
    T remove(int pos){
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición inválida");
        }

        Node<T>* toDelete;
        T removedData;

        if (pos == 0) {
            // Eliminar el primer elemento
            toDelete = first;
            removedData = toDelete->data;
            first = first->next;
        } else {
            // Eliminar en una posición específica
            Node<T>* prev = first;
            for (int i = 0; i < pos - 1; ++i) {
                prev = prev->next;
            }
            toDelete = prev->next;
            removedData = toDelete->data;
            prev->next = toDelete->next;
        }

        delete toDelete;
        --n;
        return removedData;
    }

    // Obtener el elemento en una posición específica
    T get(int pos){
        if (pos < 0 || pos >= n) {
            throw out_of_range("Posición inválida");
        }

        Node<T>* current = first;
        for (int i = 0; i < pos; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Buscar la posición de un elemento específico
    int search(T e){
        Node<T>* current = first;
        int index = 0;
        while (current != nullptr) {
            if (current->data == e) {
                return index;
            }
            current = current->next;
            ++index;
        }
        return -1;
    }

    // Verificar si la lista está vacía
    bool empty(){
        return n == 0;
    }

    // Obtener el número de elementos en la lista
    int size(){
        return n;
    }

    // Sobrecarga del operador []
    T operator[](int pos){
        return get(pos);  // Usa el método get() para obtener el elemento
    }

    // Sobrecarga del operador << para imprimir la lista
    friend ostream& operator<<(ostream& out, const ListLinked<T>& list) {
        out << "[";
        Node<T>* current = list.first;
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }
};

#endif

