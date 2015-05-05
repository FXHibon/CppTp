//
// Created by fx on 21/04/2015.
//

#ifndef DOUBLE_LINKEDLIST_CPP
#define DOUBLE_LINKEDLIST_CPP

#include <iostream>
#include <functional>
#include "Node.cpp"

template<typename T>
class DoubleLinkedList {

private:
    Node<T> *first;

    Node *nodeFilter(Node *node, std::function<bool(T)>);
public:

    DoubleLinkedList() {
        this->first = 0;
    }


    DoubleLinkedList(Node<T> *first) : first(first) { }

    void push(T);

    T pop();

    T removeLast();

    void insert(T, int);

    T remove(int);

    int length();

    T get(int);

    void toString();

    void append(T val);

    DoubleLinkedList<T> *filter(std::function<bool(T)>);
};

/**
 * Add new elem at the begining of the DoubleLinkedList
 */
template<typename T>
void DoubleLinkedList<T>::push(T val) {
    Node<T> *cell = new Node<T>;

    cell->value = val;
    cell->next = this->first;
    cell->prev = 0;

    this->first = cell;
}

/**
 * Remove and return first elem of the DoubleLinkedList or throw error if empty
 */
template<typename T>
T DoubleLinkedList<T>::pop() {
    if (this->first == 0) {
        throw;
    } else {
        T val = this->first->value;
        if (this->first->next != 0) {
            this->first = this->first->next;
            delete this->first->prev;
            this->first->prev = 0;
        } else {
            delete this->first;
            this->first = 0;
        }
        return val;
    }
}

/**
 * Return the DoubleLinkedList size
 */
template<typename T>
int DoubleLinkedList<T>::length() {
    Node<T> *cell = this->first;
    int val = 0;
    while (cell != 0) {
        cell = cell->next;
        val++;
    }
    return val;
}

/**
 * get the index-iem elem of the DoubleLinkedList
 */
template<typename T>
T DoubleLinkedList<T>::get(int index) {
    Node<T> *cell = this->first;
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
    if (this->first == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    Node<T> *cell = this->first;
    std::cout << "[\n";
    while (cell != 0) {
        std::cout << "\t";
        std::cout << cell->value;
        std::cout << "\n";
        cell = cell->next;
    }
    std::cout << "]\n" << std::endl;
}

template<typename T>
T DoubleLinkedList<T>::removeLast() {

    if (this->first == 0) {
        throw;
    }

    T val;
    Node<T> *cellPrev = 0;
    Node<T> *cell = this->first;
    while (cell->next != 0) {
        cellPrev = cell;
        cell = cell->next;
    }
    if (cellPrev == 0) {
        cellPrev = cell;
    }
    val = cell->value;
    delete cell;
    cellPrev->next = 0;
    return val;
}

template<typename T>
void DoubleLinkedList<T>::insert(T val, int position) {
    Node<T> *cellPrev = 0;
    Node<T> *cell = this->first;
    int count = 0;
    while (cell->next != 0 && count++ < position) {
        cellPrev = cell;
        cell = cell->next;
    }

    Node<T> *newCell = new Node<T>();
    newCell->value = val;
    newCell->prev = cellPrev;
    newCell->next = cell;

    if (cellPrev != 0) {
        cellPrev->next = newCell;
    }
    cell->prev = cell;
}

template<typename T>
T DoubleLinkedList<T>::remove(int position) {
    Node<T> *cell = this->first;
    int count = 0;
    T val;
    while (cell->next != 0 && count++ < position) {
        cell = cell->next;
    }

    cell->prev->next = cell->next;
    cell->next->prev = cell->prev;

    val = cell->value;
    delete cell;
    return val;
}

template<typename T>
void DoubleLinkedList<T>::append(T val) {

}

template<typename T>
DoubleLinkedList<T> *DoubleLinkedList<T>::filter(std::function<bool(T)> cls) {
    return new DoubleLinkedList(nodeFilter(this->first, cls));
}

template<typename T>
Node *DoubleLinkedList<T>::nodeFilter(Node *node, std::function<bool(T)> cls) {
    if (node == 0) {
        return 0;
    } else if (cls(node->value)) {
        Node *tmp = new Node();
        tmp->value = node->value;
        tmp->next = cls(node->next, cls);
        return tmp;
    } else {
        return nodeFilter(node->next, cls);
    }
}

#endif //DOUBLE_LINKEDLIST_CPP
