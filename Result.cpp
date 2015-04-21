//
// Created by fx on 21/04/2015.
//

template<typename T>
template<typename E>
class Result {

private:
    T val;
    E error;
    bool isErr;

public:
    Result(T value) {
        val = value;
        isErr = false;
    }

    Result(E err) {
        error = err;
        isErr = true;
    }

    T get() {
        return val;
    }

    E getError() {
        return error;
    }

    bool isError() {
        return isErr;
    }
};