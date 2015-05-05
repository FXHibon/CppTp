//
// Created by fx on 21/04/2015.
//

#ifndef DOUBLE_LINKEDLIST_CPP
#define DOUBLE_LINKEDLIST_CPP

#include <iostream>
#include <functional>
#include "Node.cpp"
#include "../Result/Result.cpp"
#include "../Result/Value.cpp"
#include "../Result/Error.cpp"

template<typename T>
class DoubleLinkedList {

private:


    Node<T> *nodeFilter(Node<T> *node, std::function<bool(T)>);
public:

    Node<T> *first;

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
    Node<T> *cell = this->first;
    std::cout << "[";
    while (cell != 0) {
        std::cout << cell->value;
        if (cell->next != 0) {
            std::cout << ", ";
        }
        cell = cell->next;
    }
    std::cout << "]" << std::endl;
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
Node<T> *DoubleLinkedList<T>::nodeFilter(Node<T> *node, std::function<bool(T)> cls) {
    if (node == 0) {
        return 0;
    } else if (cls(node->value)) {
        Node<T> *tmp = new Node<T>();
        tmp->value = node->value;
        tmp->next = nodeFilter(node->next, cls);
        return tmp;
    } else {
        return nodeFilter(node->next, cls);
    }
}

template<typename T, typename U>
Node<U> *nodeMap(Node<T> *node, std::function<U(T)> cls) {
    if (node == 0) {
        return 0;
    } else {
        Node<U> *tmp = new Node<U>();
        tmp->value = cls(node->value);
        tmp->next = nodeMap(node->next, cls);
        return tmp;
    }
}

template<typename T, typename U>
DoubleLinkedList<U> *map(DoubleLinkedList<T> *list, std::function<U(T)> cls) {
    return new DoubleLinkedList<U>(
            nodeMap(list->first, cls)
    );
}

template<typename T, typename U>
U nodeFold(Node<T> *node, U acc, std::function<U(T, U)> cls) {
    if (node == 0) {
        return acc;
    } else {
        return nodeFold(node->next, cls(acc, node->value), cls);
    };
}

template<typename T, typename U>
U fold(DoubleLinkedList<T> *list, U acc, std::function<U(T, U)> cls) {
    return nodeFold(list->first, acc, cls);
}

template<typename T, typename U, typename V>
Result<V, U> *map(Result<T, U> *result, std::function<T(V)> cls) {
    if (result->isOk()) {
        return new Value<V, U>(cls(result->get()));
    } else {
        return new Error<V, U>(result->getError());
    }
}

template<typename T, typename U, typename V>
Result<V, U> *mapError(Result<T, U> *result, std::function<U(V)> cls) {
    if (result->isOk()) {
        return new Value<V, U>(result->get());
    } else {
        return new Error<V, U>(cls(result->getError()));
    }
}


#endif //DOUBLE_LINKEDLIST_CPP
