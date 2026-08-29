#include <iostream>
using namespace std;

#define SIZE 1000

int hashFunction(int x) {
    if (x < 0)
        x = -x;
    return x % SIZE;
}

int main() {
    int n;
    cout<<"Enter the number of elements:";
    cin >> n;
    int a[n];
    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key[SIZE];
    int freq[SIZE];
    for (int i = 0; i < SIZE; i++) {
        key[i] = -1;
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = hashFunction(a[i]);
        while (key[index] != -1 && key[index] != a[i]) {
            index = (index + 1) % SIZE;
        }
        if (key[index] == -1)
            key[index] = a[i];
        freq[index]++;
    }
    for (int i = 0; i < SIZE; i++) {
        if (key[i] != -1)
            cout << key[i] << " : " << freq[i] << endl;
    }

    return 0;
}