//
// Created by fx on 19/05/2015.
// Implementation of AList with a tree
//
#ifndef CLASS_TREE_LIST
#define CLASS_TREE_LIST

#include <iostream>
#include "../AList.cpp"
#include "Node.cpp"


template<class T>
class TreeList : public AList<T> {

private:
    Node<T> *root;

    void internalPush(Node<T> *node, T val);

    T internalPop(Node<T> *node);

    void internalToString(Node<T> *node);

public:

    virtual void push(T t);

    virtual T pop();

    virtual int length();

    virtual T get(int i);

    virtual void toString();
};

/**
 * Add the value in the node
 */
template<class T>
void TreeList<T>::internalPush(Node<T> *node, T val) {
    if (val > node->val) {
        if (node->right == 0) {
            node->right = new Node<T>(val, node);
        } else {
            internalPush(node->right, val);
        }
    } else {
        if (node->left == 0) {
            node->left = new Node<T>(val, node);
        } else {
            internalPush(node->left, val);
        }
    }
}

template<class T>
void TreeList<T>::push(T t) {
    if (this->root == 0) {
        this->root = new Node<T>(t, 0);
    } else {
        internalPush(root, t);
    }
}

template<class T>
T TreeList<T>::pop() {
    if (this->root != 0) {
        return internalPop(this->root);
    }
    return 0;
}

template<class T>
T TreeList<T>::internalPop(Node<T> *node) {
    if (node->right != 0) {
        return internalPop(node->right);
    } else if (node->left != 0) {
        return internalPop(node->left);
    } else {
        if (node->parent->left == node) {
            node->parent->left = 0;
        } else if (node->parent->right == node) {
            node->parent->right = 0;
        }
        T val = node->val;
        delete node;
        return val;
    }
}

template<class T>
int TreeList<T>::length() {
    return 0;
}

template<class T>
T TreeList<T>::get(int i) {
    return 0;
}

template<class T>
void TreeList<T>::toString() {
    if (this->root != 0) {
        internalToString(this->root);
    }
}

template<class T>
void TreeList<T>::internalToString(Node<T> *node) {
    if (node != 0) {
        internalToString(node->right);
        std::cout << " " << node->val << " ";
        internalToString(node->left);
    }
}

#endif