//
// Created by fx on 05/05/2015.
//

#include <iostream>
#include "Option.cpp"
#include "Some.cpp"
#include "None.cpp"

Option<int> *testFunction(bool res) {
    if (res) {
        return new Some<int>(10);
    } else {
        return new None<int>();
    }
}

int main() {

    std::cout << testFunction(true) << std::endl;
    std::cout << testFunction(false) << std::endl;

}