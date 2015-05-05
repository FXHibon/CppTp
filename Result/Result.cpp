//
// Created by fx on 05/05/2015.
//

#ifndef COURS_RESULT
#define COURS_RESULT

#include "../Option/Option.cpp"

template<typename T, typename U>
class Result {
public:
    virtual bool isOk() = 0;

    virtual T get() = 0;

    virtual U getError() = 0;

    virtual Option<T> *toOption() = 0;
};

#endif