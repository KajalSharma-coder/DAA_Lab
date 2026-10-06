#include <iostream>
using namespace std;

void prims(int cost[10][10], int n)
{
    int visited[10] = {0};
    visited[0] = 1;

    int minCost = 0;

    for(int k = 0; k < n - 1; k++)
    {
        int min = 100000;
        int u = -1, v = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] != 0)
                    {
                        if(cost[i][j] < min)
                        {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }
        }

        cout << u << " - " << v << " = " << min << endl;

        minCost = minCost + min;
        visited[v] = 1;
    }

    cout << "Minimum Cost = " << minCost << endl;
}

int main()
{
    int n;
    int cost[10][10];

    cout << "Enter graph size: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    prims(cost, n);

    return 0;
}