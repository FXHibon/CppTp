//
// Created by fx on 21/04/2015.
//

#ifndef CLASS_CELL
#define CLASS_CELL

template<typename T>
class Cell {

public:
    T value;
    Cell<T> *next;

    Cell() { }
};

#endif