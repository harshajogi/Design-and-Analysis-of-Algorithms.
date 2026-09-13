#include <iostream>
using namespace std;

void knapsack(int wt[], int val[], int n, int cap)
{
    double ratio[100];
    
    for (int i = 0; i < n; i++)
        ratio[i] = (double)val[i] / wt[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                double t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;

                t = wt[i];
                wt[i] = wt[j];
                wt[j] = t;

                t = val[i];
                val[i] = val[j];
                val[j] = t;
            }
        }
    }

    double total = 0;

    for (int i = 0; i < n; i++)
    {
        if (cap >= wt[i])
        {
            cap -= wt[i];
            total += val[i];
        }
        else
        {
            total += ratio[i] * cap;
            break;
        }
    }

    cout << "Maximum value = " << total;
}

int main()
{
    int wt[100], val[100], n, cap;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cout << "Enter capacity: ";
    cin >> cap;

    knapsack(wt, val, n, cap);

    return 0;
}