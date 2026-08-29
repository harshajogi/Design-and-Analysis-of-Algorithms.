#include <iostream>
using namespace std;

#define SIZE 10

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hashFunction(key);

    while (table[index] != -1) {
        index = (index + 1) % SIZE;
    }

    table[index] = key;
}

void display(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : " << table[i] << "\n ";
    }
}

int main() {
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout<<"Enter number of elements: ";
    cin >> n;
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(table, x);
    }

    display(table);

    return 0;
}