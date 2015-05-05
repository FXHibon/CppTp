//
// Created by fx on 05/05/2015.
//


#include "Result.cpp"
#include "../Option/Some.cpp"

template<typename T, typename U>
class Value : public Result<T, U> {

private:
    T val;
public:


    Value(T val) : val(val) { }

    virtual bool isOk();

    virtual T get();

    virtual U getError();

    virtual Option<T> *toOption();
};

template<typename T, typename U>
bool Value<T, U>::isOk() {
    return true;
}

template<typename T, typename U>
T Value<T, U>::get() {
    return this->val;
}

template<typename T, typename U>
U Value<T, U>::getError() {
    throw;
}

template<typename T, typename U>
Option<T> *Value<T, U>::toOption() {
    return new Some<T>(val);
}
