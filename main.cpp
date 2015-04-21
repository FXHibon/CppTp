#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cell {
    int value;
    Cell *next;
};
struct List {
    Cell *first;
};


List *create();

void push(List *, int);

int pop(List *);

int length(List *);

int get(List *, int);

/**
 * Create new list
 */
List *create() {
    List *newList = (List *) malloc(sizeof(List));
    newList->first = NULL;
    return newList;
}

/**
 * Add new elem at the end of the list
 */
void push(List *list, int val) {
    Cell *cell = (Cell *) malloc(sizeof(Cell));
    cell->value = val;
    cell->next = list->first;
    list->first = cell;
}

/**
 * Remove and return last elem of the list
 */
int pop(List *list) {
    if (list->first == NULL) {
        return -1;
    } else if (list->first->next == NULL) {
        int val = list->first->value;
        list->first = NULL;
        free(list->first);
        return val;
    } else {
        Cell *tmp = list->first;
        Cell *last = tmp;

        while (tmp->next != NULL) {
            last = tmp;
            tmp = tmp->next;
        }
        int val = tmp->value;
        free(tmp);
        last->next = NULL;
        return val;
    }
}

/**
 * Return the list size
 */
int length(List *list) {
    Cell *cell = list->first;
    int val = 0;
    while (cell != NULL) {
        cell = cell->next;
        val++;
    }
    return val;
}

/**
 * get the index-iem elem of the list
 */
int get(List *list, int index) {
    Cell *cell = list->first;
    int val = 0;
    while (cell != NULL) {
        if (val == index) {
            return cell->value;
        }
        cell = cell->next;
        val++;
    }
    return val;
}

void toString(List *list) {
    Cell *cell = list->first;
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
int main() {
    List *maListe = create();
    toString(maListe);
    cout << "Size = " << length(maListe) << endl;
    cout << "Pushing 10" << endl;
    push(maListe, 10);
    toString(maListe);
    cout << "Size = " << length(maListe) << endl;
    cout << "get(0) = " << get(maListe, 0) << endl;

    cout << "pop = " << pop(maListe) << endl;
    toString(maListe);
    cout << "Size = " << length(maListe) << endl;

    cout << "Pushing few values ..." << endl;

    for (int i = 0; i < 10; i++) {
        push(maListe, i * 10);
    }

    cout << "Size = " << length(maListe) << endl;
    toString(maListe);
    return 0;
}