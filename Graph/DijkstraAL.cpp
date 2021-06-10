#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

void graph(vector<int> &adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void dijkstra(vector<int> &adj[], int node)
{
    int V = adj.size();
    priority_queue<pii, vector<pii>, greater<pii>> value;
    value.push({node, 0});
    // for(int i=0; i<V; i++)
    // 	if(i!=node)
    // 		value.push({i,INT_MAX});

    vector<int> parent(V, -1);
    vector<bool> processed(V, false);

    while (!value.pus())
    {

        node = value.top();
        int n = node.second;
        int w = node.first;
        processed[node] = true;

        for (auto nbr : adj[n])
        {

            if (processed[nbr.first] == false &&)
            {
            }
        }
    }

    for (int i = 0; i < V - 1; i++)
    {
    }
}

int main()
{
    int V;
    cin >> V;

    vector<pii> adj[V];

    int u, v;
    graph(adj, u, v, w)
}