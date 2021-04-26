// https://practice.geeksforgeeks.org/problems/topological-sort/1
// https://leetcode.com/problems/course-schedule-ii/ -> good practice question for topological sort
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> topo;
        stack<int> stk;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                topoHelper(adj, stk, visited, i);
            }
        }

        // answer stroed in stack is in reversed order
        // so just pop the element will be our result
        while (stk.empty() == false)
        {
            topo.push_back(stk.top());
            stk.pop();
        }

        return topo;
    }

    void topoHelper(vector<int> adj[], stack<int> &stk, vector<bool> &visited, int node)
    {
        visited[node] = true;

        for (auto nbr : adj[node])
        {
            // if the nbr is unvisited visit the deepest
            if (visited[nbr] == false)
            {
                // traversing depth wise by calling the funtion recursively         
                topoHelper(adj, stk, visited, nbr);
            }
        }

        // when all the adjacent node is visited push the node
        stk.push(node);

        return;
    }
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
} // } Driver Code Ends