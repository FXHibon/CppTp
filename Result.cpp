//
// Created by fx on 21/04/2015.
//

template<typename T, typename E>
class Some {

private:
    T val;
    E error;
    bool isErr;

public:
    Some(T value) {
        val = value;
        isErr = false;
    }

    Some(E err) {
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