#include <iostream>
using namespace std;

int maxCross(int a[], int low, int mid, int high)
{
    int sum = 0, left = -100000, right = -100000;

    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > left)
            left = sum;
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += a[i];
        if (sum > right)
            right = sum;
    }

    return left + right;
}

int maxSub(int a[], int low, int high)
{
    if (low == high)
        return a[low];

    int mid = (low + high) / 2;

    int left = maxSub(a, low, mid);
    int right = maxSub(a, mid + 1, high);
    int cross = maxCross(a, low, mid, high);

    if (left >= right && left >= cross)
        return left;
    else if (right >= left && right >= cross)
        return right;
    else
        return cross;
}

int main()
{
    int a[100], n;

    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Maximum subarray sum = "
         << maxSub(a, 0, n - 1);

    return 0;
}