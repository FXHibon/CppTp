//
// Created by fx on 21/04/2015.
//

#ifndef COURS_LINKEDLIST_CPP
#define COURS_LINKEDLIST_CPP

#include <iostream>
#include "Cell.cpp"

template<typename T>
class DoubleLinkedList {

private:
    Cell<T> *first;

public:

    DoubleLinkedList() {
    }

    void push(T);

    T pop();

    int length();

    T get(int);

    void toString();

};

/**
 * Add new elem at the begining of the LinkedList
 */
template<typename T>
void DoubleLinkedList<T>::push(T val) {
    Cell<T> *cell = new Cell<T>;
    cell->value = val;
    cell->next = this->first;
    this->first = cell;
}

/**
 * Remove and return first elem of the LinkedList or -1 if empty
 */
template<typename T>
T DoubleLinkedList<T>::pop() {
    if (this->first == 0) {
        throw;
    } else {
        T val = this->first->value;
        delete this->first;
        this->first = this->first->next;
        return val;
    }
}

/**
 * Return the LinkedList size
 */
template<typename T>
int DoubleLinkedList<T>::length() {
    Cell<T> *cell = this->first;
    int val = 0;
    while (cell != 0) {
        cell = cell->next;
        val++;
    }
    return val;
}

/**
 * get the index-iem elem of the LinkedList
 */
template<typename T>
T DoubleLinkedList<T>::get(int index) {
    Cell<T> *cell = this->first;
    int val = 0;
    while (cell != 0) {
        if (val == index) {
            return cell->value;
        }
        cell = cell->next;
        val++;
    }
    throw;
}

template<typename T>
void DoubleLinkedList<T>::toString() {
    if (this->first == NULL) {
        std::cout << "[]" << std::endl;
        return;
    }
    Cell<T> *cell = this->first;
    std::cout << "[\n\t";
    while (cell != NULL) {
        std::cout << cell->value;
        std::cout << "\n";
        if (cell->next != NULL) {
            std::cout << "\t";
        }
        cell = cell->next;
    }
    std::cout << "]\n" << std::endl;
}


#endif //COURS_LINKEDLIST_CPP
