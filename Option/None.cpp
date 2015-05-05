//
// Created by fx on 05/05/2015.
//

#include "Option.cpp"

template<typename T>
class None : Option {
private:
    T val;

public:
    None<T>();


    virtual T get();

    virtual bool isSome();
};

template<typename T>
T None::get() {
    return val;
}

bool None::isSome() {
    return false;
}
