#include <iostream>
using namespace std;
int main() {
    int n, k;
    cout<<"Enter the size of array: ";
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout<<"Enter the target element: ";
    cin >> k;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout<<"at position";
    cout << a[k - 1];
    return 0;
}