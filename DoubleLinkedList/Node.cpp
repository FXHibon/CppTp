//
// Created by fx on 05/05/2015.
//

template<typename T>
class Node {

public:
    T value;
    Node<T> *next;
    Node<T> *prev;

    Node() { }
};
