#include <iostream>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    int wt[n + 1], val[n + 1];

    cout << "Enter weights: ";
    for (int i = 1; i <= n; i++)
        cin >> wt[i];

    cout << "Enter profits: ";
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    cout << "Enter capacity: ";
    cin >> W;

    int c[n + 1][W + 1];

    // Initialization
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                c[i][w] = 0;
        }
    }

    // Dynamic Programming
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i] > w)
            {
                c[i][w] = c[i - 1][w];
            }
            else
            {
                c[i][w] = max(
                    val[i] + c[i - 1][w - wt[i]],
                    c[i - 1][w]
                );
            }
        }
    }

    cout << "Maximum Profit = " << c[n][W] << endl;

    return 0;
}