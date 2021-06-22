// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.

    void topoSort(int node, vector<int> adj[], int visited[], stack<int> &st)
    {
        visited[node] = 1;
        for (auto nbr : adj[node])
        {
            if (visited[nbr] == 0)
                topoSort(nbr, adj, visited, st);
        }

        st.push(node);
    }

    void revDfs(int node, vector<int> adj[], int visited[])
    {
        visited[node] = 1;
        for (auto nbr : adj[node])
        {
            if (visited[nbr] == 0)
                revDfs(nbr, adj, visited);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        int visited[V] = {0};
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
                topoSort(i, adj, visited, st);
        }

        vector<int> transpose[V];

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto nbr : adj[i])
                transpose[nbr].push_back(i);
        }

        int count = 0;

        while (st.empty() == false)
        {
            int node = st.top();
            st.pop();

            if (visited[node] == 0)
            {
                count++;
                revDfs(node, transpose, visited);
            }
        }

        return count;
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

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends