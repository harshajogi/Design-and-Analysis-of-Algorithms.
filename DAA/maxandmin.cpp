#include <iostream>
using namespace std;

void findMinMax(int a[], int low, int high, int &mn, int &mx)
{
    if (low == high)
    {
        mn = mx = a[low];
        return;
    }

    int mid = (low + high) / 2;
    int min1, max1, min2, max2;

    findMinMax(a, low, mid, min1, max1);
    findMinMax(a, mid + 1, high, min2, max2);

    mn = (min1 < min2) ? min1 : min2;
    mx = (max1 > max2) ? max1 : max2;
}

int main()
{
    int a[100], n, mn, mx;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    findMinMax(a, 0, n - 1, mn, mx);

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx;

    return 0;
}