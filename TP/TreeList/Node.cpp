//
// Created by fx on 19/05/2015.
//

#ifndef CLASS_NODE
#define CLASS_NODE

template<class T>
class Node {
public:
    T val;
    Node<T> *left;
    Node<T> *right;

    Node<T> *parent;

    Node(T val, Node<T> *parent) : val(val), parent(parent) {
        left = 0;
        right = 0;
    }
};

#endif