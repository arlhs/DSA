// https://www.youtube.com/watch?v=3gbO7FDYNFQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=23
#include <bits/stdc++.h>
using namespace std;

int findParent(int node, int parent[])
{
    if (parent[node] == -1)
        return node;

    // return findParent(parent[node], parent);     // this is without find parent
    return parent[node] = findParent(parent[node], parent); // we are storing the value of parent on node whenwve we find it
}

void Union(int u, int v, int parent[], int rank[])
{
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++; //rank will increase of partent node
    }
}

int main()
{
    int n;
    cin >> n;

    int parent[n + 1];
    int rank[n + 1];

    // making every node as disjoint initially

    for (int i = 0; i <= n; i++)
        rank[i] = 0, parent[i] = -1;

    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v, parent, rank);
    }

    int u, v;
    cin >> u >> v;

    if (findParent(u, parent) != findParent(v, parent))
        cout << "Node are not of same set";
    else
        cout << "node of the same set";
}