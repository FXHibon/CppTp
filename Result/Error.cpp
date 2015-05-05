//
// Created by fx on 05/05/2015.
//

#include "Result.cpp"
#include "../Option/None.cpp"

template<typename T, typename U>
class Error : Result<T, U> {

private:
    U val;

public:


    Error(U val) : val(val) { }

    virtual bool isOk();

    virtual T get();

    virtual U getError();

    virtual Option<T> *toOption();
};

template<typename T, typename U>
bool Error<T, U>::isOk() {
    return false;
}

template<typename T, typename U>
T Error<T, U>::get() {
    throw;
}

template<typename T, typename U>
U Error<T, U>::getError() {
    return this->val;
}

template<typename T, typename U>
Option<T> *Error<T, U>::toOption() {
    return new None<T>;
}
