#include <iostream>
using namespace std;

#define SIZE 10

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int table[], int key) {
    int index = hashFunction(key);
    int i = 0;

    while (table[(index + i * i) % SIZE] != -1) {
        i++;
    }

    table[(index + i * i) % SIZE] = key;
}

void display(int table[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << i << " : " << table[i] << endl;
    }
}

int main() {
    int table[SIZE];

    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    int n;
    cout<<"Enter the number of elements: ";
    cin >> n;
    cout<<"Enter the Elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(table, x);
    }

    display(table);

    return 0;
}