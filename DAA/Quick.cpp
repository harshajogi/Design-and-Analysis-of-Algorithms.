#include <iostream>
using namespace std;

int partition(int a[], int l, int r)
{
    int p = a[r];
    int i = l - 1;

    for(int j = l; j < r; j++)
    {
        if(a[j] < p)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;
}

void quickSort(int a[], int l, int r)
{
    if(l < r)
    {
        int p = partition(a, l, r);

        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}