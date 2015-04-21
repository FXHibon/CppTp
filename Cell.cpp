//
// Created by fx on 21/04/2015.
//

template<typename T>
class Cell {

public:
    T value;
    Cell<T> *next;

    Cell() { }
};
