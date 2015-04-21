#include <iostream>

using namespace std;

struct Cell {
    int value;
    Cell* next;
};
struct List {
    Cell first;
};


List *create();

void push(List *, int);

int pop(List *);

int length(List *);

int get(List *, int);

List *create() {
    List *newList = (List *) malloc(sizeof(List));
    newList->first = NULL;
    return newList;
}

void push(List *list, int val) {
    Cell *cell = (Cell *) malloc(sizeof(Cell));
    cell->value = val;
    cell->next = NULL;

    Cell *tmp = &list->first;

    while (tmp != NULL) {
        tmp = tmp->next;
    }
    tmp->next = cell;
}

int pop(List *list) {

}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}