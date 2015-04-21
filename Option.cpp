//
// Created by fx on 21/04/2015.
//


template<typename T>
class Option {

private:
    T value;
    bool none;

public:
    Option() {
        none = true;
    }

    Option(T val) {
        value = val;
        none = false;
    }

    T get() {
        if (!none) {
            return value;
        }
        throw;
    }
};