#include <iostream>

using namespace std;

struct Cell {
    int value;
    Cell* next;
};
struct List {
    Cell first;
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}