//
// Created by fx on 05/05/2015.
//

#include "Option.cpp"

template<typename T>
class None : public Option<T> {

public:
    None<T>() { }

    T get();

    bool isSome();
};

template<typename T>
T None<T>::get() {
    throw;
}

template<typename T>
bool None<T>::isSome() {
    return false;
}
