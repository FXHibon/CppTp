//
// Created by fx on 21/04/2015.
//


template<typename T>
class Option {

private:
    T value;
    bool none;

public:

    virtual T get() = 0;

    virtual bool isSome() = 0;
};