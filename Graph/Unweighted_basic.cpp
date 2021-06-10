#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addNode(map<int, list<int>> &adj, int u, int v)
{
    // these two lines are for undirected graph
    adj[u].push_back(v);
    //adj[v].push_back(u);    // for directed graph remove this line  
}
/*
// this function is for undirected graph 
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bool ans = cycleHelper(adj, visited, i, -1);
            if (ans == true)
                return true;
        }
    }
    return false;
}

bool cycleHelper(vector<int> adj[], vector<bool> &visited, int node, int parent)
{
    visited[node] = true;

    for (auto nbr : adj[node])
    {
        // nbr is not visited traverse depth wise
        if (visited[nbr] == false)
        {
            bool cycle_mila = cycleHelper(adj, visited, nbr, node);
            if (cycle_mila)
                return true;
        }
        //  nbr is visited but nbr is not equal to parent
        else if (nbr != parent)
            return true;
    }

    return false;
}

*/

bool cyclicUntill(map<int, list<int>> &adj, vector<bool> &visited, vector<bool> &ordered, int node)
{
    //visited[i] =true;
    visited[node] = true;
    ordered[node] = true;
    for (auto it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (visited[*it] == false)
        {
            visited[*it] = true;
            bool config = cyclicUntill(adj, visited, ordered, *it);
            if (config)
                return true;
        }
        else if (ordered[*it] == true)
            return true;
    }
    ordered[node] = false;
    return false;
}

bool isCyclic(int V, map<int, list<int>> adj)
{
    vector<bool> visited(V, false);
    vector<bool> ordered(V, false);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            bool cycle = cyclicUntill(adj, visited, ordered, i);
            if (cycle)
                return true;
        }
    }
    return false;
}





void bfs(map<int, list<int>> adj, int node)
{
    int size = adj.size();
    //    cout<<size<<" ";
    vector<bool> visited(size, false);

    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        node = q.front();
        q.pop();
        cout << node << " ";

        for (auto it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!visited[*it])
            {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

// Gives nth connection of a node
void nthCon(map<int, list<int>> adj, int node, int n)
{
    int size = adj.size();
    //    cout<<size<<" ";
    vector<bool> visited(size, false);

    queue<int> q;
    q.push(node);
    int nbr;
    int nth = 0;
    visited[node] = true;

    while (!q.empty())
    {
        nbr = q.size();

        while (nbr--)
        {

            node = q.front();
            q.pop();
            if (nth == n)
                cout << node << " ";

            for (auto it = adj[node].begin(); it != adj[node].end(); it++)
            {
                if (!visited[*it])
                {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        if (nth == n)
            return;
        nth++;
    }
}

void dfs(map<int, list<int>> &adj, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";

    for (auto it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if (!visited[*it])
        {
            visited[*it] = true;
            dfs(adj, visited, *it);
        }
    }
}

void dfsUntil(map<int, list<int>> &adj, int node)
{
    vector<bool> visited(adj.size(), false);

    dfs(adj, visited, node);
}

int main()
{
    map<int, list<int>> adj;

    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     addNode(adj, u, v);
    // }

    addNode(adj, 0, 1);
    addNode(adj, 0, 2);
    addNode(adj, 0, 3);
    addNode(adj, 1, 3);
    addNode(adj, 2, 4);
    addNode(adj, 3, 4);
    addNode(adj, 3, 5);
    addNode(adj, 4, 5);
    // addNode(adj, 5, 8);
    // addNode(adj, 6, 9);
    // addNode(adj, 7, 9);
    // addNode(adj, 8, 9);

    cout<<"BFT: ";
    bfs(adj, 0);

    cout<<"\nDFT: ";

    dfsUntil(adj, 0);

    cout<<isCyclic(adj.size(), adj);
}