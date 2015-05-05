//
// Created by fx on 05/05/2015.
//

template<typename T>
class Cell {

public:
    T value;
    Cell<T> *next;
    Cell<T> *prev;

    Cell() { }
};
