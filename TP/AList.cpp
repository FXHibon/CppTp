//
// Created by fx on 19/05/2015.
// Abstract list
//

#ifndef ALIST_CLASS
#define ALIST_CLASS

template<class T>
class AList {
public:
    virtual void push(T) = 0;

    virtual T pop() = 0;

    virtual int length() = 0;

    virtual T get(int) = 0;

    virtual void toString() = 0;
};

#endif