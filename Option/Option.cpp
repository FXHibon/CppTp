//
// Created by fx on 21/04/2015.
//

#ifndef COURS_OPTION
#define COURS_OPTION

template<typename T>
class Option {

private:
    T value;
    bool none;

public:

    virtual T get() = 0;

    virtual bool isSome() = 0;
};

#endif