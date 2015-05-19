////
//// Created by fx on 05/05/2015.
////
//
//#include <iostream>
//#include "DoubleLinkedList.cpp"
//
//using namespace std;
//
//int testCount = 0;
//
//void testOK(string testName) {
//    std::cout << "- " << ++testCount << ": " << testName << " OK" << std::endl;
//}
//
//void testKO(string testName) {
//    std::cout << "- " << ++testCount << ": " << testName << " KO" << std::endl;
//}
//
//// Lance quelques tests
//void test() {
//
//    DoubleLinkedList<int> *linkedList = new DoubleLinkedList<int>();
//
//    string msg;
//
//    msg = "length shoud be 0";
//    if (linkedList->length() == 0) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    int val1 = 1;
//
//    msg = "length shoud be equals to 1";
//    linkedList->push(val1);
//    if (linkedList->length() == 1) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    int poped = linkedList->pop();
//    msg = "length shoud be 0";
//    if (linkedList->length() == 0) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    msg = "poped value should be equals to what we have added";
//    if (poped == val1) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//        std::cout << poped;
//    }
//
//    for (int i = 0; i < 10; i++) {
//        linkedList->push(i);
//    }
//
//    msg = "length shoud be 10";
//    if (linkedList->length() == 10) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    std::cout << "BEFORE removeLast" << endl;
//    linkedList->toString();
//
//    linkedList->removeLast();
//
//    std::cout << "AFTER removeLast" << endl;
//    linkedList->toString();
//
//    msg = "length shoud be 9";
//    if (linkedList->length() == 9) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    std::cout << "BEFORE insert" << endl;
//    linkedList->toString();
//
//    linkedList->insert(15, 5);
//
//    std::cout << "AFTER insert" << endl;
//    linkedList->toString();
//
//
//    std::cout << "BEFORE remove" << endl;
//    linkedList->toString();
//
//    int val = linkedList->remove(5);
//
//    msg = "removed val should be 15";
//    if (val == 15) {
//        testOK(msg);
//    } else {
//        testKO(msg);
//    }
//
//    std::cout << "AFTER remove" << endl;
//    linkedList->toString();
//
//}
//
//int main() {
//    DoubleLinkedList<int> *linkedList = new DoubleLinkedList<int>();
//
//    for (int i = 5; i > 0; i--)
//        linkedList->push(i);
//
//
//    std::cout << "Liste de base:" << std::endl;
//    linkedList->toString();
//    std::cout << "Mapped:" << std::endl;
//    map<int, int>(linkedList, [](int x) { return x * 2; })
//            ->toString();
//    std::cout << "Filtered:" << std::endl;
//    linkedList->filter([](int x) { return x % 2 == 0; })
//            ->toString();
//
//    std::cout << "Fold:" << std::endl;
//    std::cout << fold<int, int>(linkedList, 0, [](int acc, int x) { return acc + x; }) << endl;
//}
//
