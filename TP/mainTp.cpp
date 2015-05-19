//
// Created by fx on 19/05/2015.
//

#include <iostream>
#include "AList.cpp"
#include "TreeList/TreeList.cpp"
#include "LinkedList/LinkedList.cpp"

using namespace std;

int testCount = 0;

void testOK(string testName) {
    std::cout << "- " << ++testCount << ": " << testName << " OK" << std::endl;
}

void testKO(string testName) {
    std::cout << "- " << ++testCount << ": " << testName << " KO" << std::endl;
}

// Lance quelques tests
void test() {

    AList<int> *list = new TreeList<int>();

    string msg;

    msg = "length shoud be 0";
    if (list->length() == 0) {
        testOK(msg);
    } else {
        testKO(msg);
    }

    list->toString();

    int val1 = 1;

    msg = "length shoud be equals to 1";
    list->push(val1);
    if (list->length() == 1) {
        testOK(msg);
    } else {
        testKO(msg);
    }

    list->toString();

    list->pop();
    msg = "length shoud be 0";
    if (list->length() == 0) {
        testOK(msg);
    } else {
        testKO(msg);
    }

    for (int i = 0; i < 10; i++) {
        list->push(i);
    }

    list->toString();

    msg = "length shoud be 10";
    if (list->length() == 10) {
        testOK(msg);
    } else {
        testKO(msg);
    }

    list->toString();

}

int main() {
    test();
    return 0;
}