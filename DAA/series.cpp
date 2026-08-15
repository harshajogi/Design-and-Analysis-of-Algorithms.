#include <iostream>
using namespace std;

int main() {
    int x, n;
    long long sum = 0, power = 1;
    cout<<"Enter the x and n";
    cin >> x >> n;

    for (int i = 0; i <= n; i++) {
        sum = sum + power;
        power = power * x;
    }

    cout << "Sum of series = " << sum;

    return 0;
}