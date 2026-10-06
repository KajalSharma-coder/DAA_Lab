#include <iostream>
#include <climits>
using namespace std;

int m[10][10];

void matrix_chain_order(int p[], int n, int s[10][10])
{
    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;

            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k]
                      + m[k + 1][j]
                      + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int s[10][10], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";

        print_optimal_parens(s, i, s[i][j]);

        print_optimal_parens(s, s[i][j] + 1, j);

        cout << ")";
    }
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];
    int s[10][10];

    cout << "Enter dimensions of matrices: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    matrix_chain_order(p, n + 1, s);

    cout << "Minimum number of multiplications: "
         << m[1][n] << endl;

    cout << "Optimal Parenthesization: ";

    print_optimal_parens(s, 1, n);

    return 0;
}