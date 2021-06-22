// https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#
// https://www.youtube.com/watch?v=2rjZH0-2lhk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=25
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int res;

public:
    //Function to find if the given edge is a bridge in graph.

    void dfs(int node, int parent, int c, int d, int &timer, vector<int> adj[], int tin[], int low[], bool visited[])
    {
        visited[node] = true;
        tin[node] = low[node] = ++timer;

        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            if (visited[nbr] == false)
            {
                dfs(nbr, node, c, d, timer, adj, tin, low, visited);
                low[node] = min(low[node], low[nbr]);
                if (tin[node] < low[nbr])
                {
                    if (nbr == c and node == d or nbr == d and node == c)
                        res = 1;
                    //cout<<res<< "-";
                }
            }
            else
                low[node] = min(low[node], tin[nbr]);
        }
    }

    int isBridge(int V, vector<int> adj[], int c, int d)
    {
        // Code here
        int tin[V] = {0};
        int low[V] = {0};
        bool visited[V] = {false};
        int timer = 0;

        res = 0;
        //cout<<res<<" ";

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                dfs(i, -1, c, d, timer, adj, tin, low, visited);
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends