//
// Created by fx on 21/04/2015.
//

template<typename T, typename E>
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
        if (!isErr) {
            return val;
        }
        throw;
    }

    E getError() {
        if (isErr) {
            return error;
        }
        throw;
    }

    bool isError() {
        return isErr;
    }
};