#include <iostream>
using namespace std;

#define SIZE 1000

int hashFunction(int x) {
    if (x < 0)
        x = -x;
    return x % SIZE;
}

int main() {
    int n, T;
    int a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter target: ";
    cin >> T;

    int table[SIZE];
    int indexTable[SIZE];

    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
        indexTable[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int need = T - a[i];
        int index = hashFunction(need);

        while (table[index] != -1) {
            if (table[index] == need) {
                cout << "Elements: " << need << " and " << a[i] << endl;
                cout << "Indices: " << indexTable[index] << " and " << i << endl;
                return 0;
            }
            index = (index + 1) % SIZE;
        }

        index = hashFunction(a[i]);

        while (table[index] != -1)
            index = (index + 1) % SIZE;

        table[index] = a[i];
        indexTable[index] = i;
    }

    cout << "No pair found";

    return 0;
}