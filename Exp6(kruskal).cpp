#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, cost;
};

bool compare(Edge a, Edge b)
{
    return a.cost < b.cost;
}

void kruskal(Edge edges[], int n, int e)
{
    int parent[10];

    for(int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + e, compare);

    int total = 0;
    int count = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for(int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if(parent[u] != parent[v])
        {
            cout << u << " - " << v
                 << " = " << edges[i].cost << endl;

            total += edges[i].cost;
            count++;

            for(int j = 0; j < n; j++)
            {
                if(parent[j] == parent[v])
                    parent[j] = parent[u];
            }
        }
    }

    cout << "Minimum Cost = " << total << endl;
}

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    Edge edges[20];

    cout << "Enter edges (u v cost):\n";

    for(int i = 0; i < e; i++)
    {
        cin >> edges[i].u;
        cin >> edges[i].v;
        cin >> edges[i].cost;
    }

    kruskal(edges, n, e);

    return 0;
}