#include <iostream>
using namespace std;

void bucketSort(int a[], int n)
{
    int b[100] = {0};

    for(int i = 0; i < n; i++)
        b[a[i]]++;

    int k = 0;

    for(int i = 0; i < 100; i++)
    {
        while(b[i] > 0)
        {
            a[k++] = i;
            b[i]--;
        }
    }
}

int main()
{
    int a[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements (0-99): ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    bucketSort(a, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}