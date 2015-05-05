#include <iostream>
#include <stdlib.h>

using namespace std;


/**
 * Simple linked list
 */
template <typename T>
struct Node {
    T value;
    Node<T> *next;
};

template <typename T>
struct List {
    Node<T> *first;
};

template <typename T>
List<T> *create();

template <typename T>
void push(List<T> *, T);

template <typename T>
T pop(List<T> *);

template <typename T>
int length(List<T> *);

template <typename T>
T get(List<T> *, int);

/**
 * Create new list
 */
template <typename T>
List<T> *create() {
    List<T> *newList = new List<T>;
    newList->first = NULL;
    return newList;
}

/**
 * Add new elem at the begining of the list
 */
template <typename T>
void push(List<T> *list, T val) {
    Node<T> *cell = new Node<T>;
    cell->value = val;
    cell->next = list->first;
    list->first = cell;
}

/**
 * Remove and return first elem of the list or -1 if empty
 */
template <typename T>
T pop(List<T> *list) {
    if (list->first == NULL) {
        return -1;
    } else {
        int val = list->first->value;
        delete list->first;
        list->first = list->first->next;
        return val;
    }
}

/**
 * Return the list size
 */
template <typename T>
int length(List<T> *list) {
    Node<T> *cell = list->first;
    T val = 0;
    while (cell != NULL) {
        cell = cell->next;
        val++;
    }
    return val;
}

/**
 * get the index-iem elem of the list
 */
template <typename T>
T get(List<T> *list, int index) {
    Node<T> *cell = list->first;
    int val = 0;
    while (cell != NULL) {
        if (val == index) {
            return cell->value;
        }
        cell = cell->next;
        val++;
    }
    throw;
    return -1;
}

template <typename T>
void toString(List<T> *list) {
    Node<T> *cell = list->first;
    cout << "[";
    while (cell != NULL) {
        cout << cell->value;
        if (cell->next != NULL) {
            cout << ", ";
        }
        cell = cell->next;
    }
    cout << "]" << endl;
}
//int main() {
//    List<int> *maListe = create<int>();
//    toString<int>(maListe);
//    cout << "Size = " << length<int>(maListe) << endl;
//    cout << "Pushing 10" << endl;
//    push<int>(maListe, 10);
//    toString<int>(maListe);
//    cout << "Size = " << length<int>(maListe) << endl;
//    cout << "get(0) = " << get<int>(maListe, 0) << endl;
//
//    cout << "pop = " << pop<int>(maListe) << endl;
//    toString<int>(maListe);
//    cout << "Size = " << length<int>(maListe) << endl;
//
//    cout << "Pushing few values ..." << endl;
//
//    for (int i = 0; i < 10; i++) {
//        push<int>(maListe, i * 10);
//    }
//
//    cout << "Size = " << length<int>(maListe) << endl;
//    toString<int>(maListe);
//
//    cout << "pop = " << pop<int>(maListe) << endl;
//    cout << "Size = " << length<int>(maListe) << endl;
//    toString<int>(maListe);
//
//
//    List<string> *stringList = create<string>();
//    for (int i = 0; i < 10; i++) {
//        push<string>(stringList, "Martin est  bete!\n");
//    }
//    toString<string>(stringList);
//    return 0;
//}