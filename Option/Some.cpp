//
// Created by fx on 05/05/2015.
//

#include "Option.cpp"

template<typename T>
class Some : public Option<T> {
private:
    T val;

public:

    Some(T value) {
        this->val = value;
    }

    T get();

    bool isSome();
};

template<typename T>
T Some<T>::get() {
    return val;
}

template<typename T>
bool Some<T>::isSome() {
    return true;
}
