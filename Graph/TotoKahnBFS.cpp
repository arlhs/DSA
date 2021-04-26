// https : //practice.geeksforgeeks.org/problems/topological-sort/1#
// { Driver Code Starts
#include <bits/stdc++.h>
        using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {

        //int size = adj.size();
        vector<int> topo;

        if (V == 0)
            return {};

        // S1.create indegree array of each no(i.e., no of incoming edge)
        int *indegree = new int[V];
        //vector<int> indegree(V,0);
        //memset(indegree, 0, sizeof(indegree));


        
        for (int i = 0; i < V; i++)
        {
            for (auto v : adj[i])
                indegree[v]++;
        }

        int count = 0;

        queue<int> que;

        // S2. push all node with indegree 0 into the queue
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                que.push(i);

        // S3. While stack in not empty
        while (!que.empty())
        {
            // take front node from the queue push in the result vector topo and the pop 
            int node = que.front();
            topo.push_back(node);
            que.pop();
            
            for (auto nbr : adj[node])
            {
                // for every neighbour of the node decrement the indegree by 1
                indegree[nbr]--;

                //if indegree become zero push it into the queu
                if (indegree[nbr] == 0)
                    que.push(nbr);
            }

            //increase the visited counter 
            count++;
        }

        // counter no equal to no of vertex then topological order not possible
        if (count != V)
            return {};

        return topo;
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